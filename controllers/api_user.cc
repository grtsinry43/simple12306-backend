#include <drogon/orm/Mapper.h>
#include "api_user.h"
#include "Users.h"
#include <jwt-cpp/jwt.h>
#include <random>
#include <string>

/**
 * 这里仅是做一个示例，生成16位随机字符串
 * @return
 */
std::string generateSecretKey() {
    std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);
    std::string secretKey;

    for (int i = 0; i < 16; ++i) {
        secretKey += characters[distribution(generator)];
    }

    return secretKey;
}

/**
 * 生成token，使用jwt-cpp库
 * @param key
 * @param username
 * @param userId
 * @return
 */
std::string generateToken(const std::string &key, const std::string &username, const std::string &userId) {
    auto token = jwt::create()
            .set_issuer("auth0")
            .set_type("JWS")
            .set_payload_claim("username", jwt::claim(username))
            .set_payload_claim("userId", jwt::claim(userId))
            .sign(jwt::algorithm::hs256{key});

    return token;
}

using namespace api;

/**
 * 用户登录，数据校验，返回token和用户信息
 * @param req
 * @param callback
 * @param username
 * @param password
 */
void user::login(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                 const std::string &username, const std::string &password) const {

//    LOG_DEBUG << "username: " << username;
//    LOG_DEBUG << "password: " << password;

    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Users> mapper(client);
    std::vector<drogon_model::simple12306::Users> userFind = mapper.orderBy(
            drogon_model::simple12306::Users::Cols::_username).findAll();



    for (drogon_model::simple12306::Users user: userFind) {
        if (*(user.getUsername()) == username) {
            LOG_DEBUG << "find user: " << *(user.getUsername());
            if (*(user.getPassword()) == password) {
                Json::Value json;
                json["code"] = 200;
                json["msg"] = "登录成功";
                // 生成token
                std::string token = generateToken(generateSecretKey(), *(userFind.at(0).getUsername()),
                                                  std::to_string(*(userFind.at(0).getUserId())));

                //返回用户数据，包括用户名，用户id，是否验证，是否学生
                Json::Value data;
                data["username"] = *(userFind.at(0).getUsername());
                data["userId"] = *(userFind.at(0).getUserId());
                data["isVerified"] = *(userFind.at(0).getIsverified());
                data["isStudent"] = *(userFind.at(0).getIsstudent());
                json["data"] = data;
                auto resp = HttpResponse::newHttpJsonResponse(json);

                // 设置token到header
                resp->addHeader("Authorization", token);
                callback(resp);
                return;
            }
        }
    }
    Json::Value json;
    json["code"] = 401;
    json["msg"] = "用户名或密码错误";
    json["data"] = "";
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

/**
 * 用户注册，这里仅需提供用户名和密码，其他信息后续通过update完善
 * @param req
 * @param callback
 * @param username
 * @param password
 */
void user::reg(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                 const std::string &username, const std::string &password) const {
    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Users> mapper(client);
    drogon_model::simple12306::Users user;
    user.setUsername(username);
    user.setPassword(password);
    // 默认未验证，非学生
    user.setIsverified(false);
    user.setIsstudent(false);
    // 插入数据，异常处理返回信息
    try {
        mapper.insert(user);
        Json::Value json;
        json["code"] = 200;
        json["msg"] = "注册成功";
        // 返回用户数据，包括用户名，用户id，是否验证，是否学生
        Json::Value data;
        data["username"] = *(user.getUsername());
        data["userId"] = *(user.getUserId());
        data["isVerified"] = *(user.getIsverified());
        data["isStudent"] = *(user.getIsstudent());
        json["data"] = data;
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    } catch (const std::exception &e) {
        LOG_DEBUG << e.what();
        Json::Value json;
        json["code"] = 500;
        json["msg"] = "服务器内部错误，注册失败";
        json["data"] = "";
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }

}
