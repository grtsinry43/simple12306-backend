#include <drogon/orm/Mapper.h>
#include "api_user.h"
#include "Users.h"

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
    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Users> mapper(client);
    std::vector<drogon_model::simple12306::Users> userFind = mapper.orderBy(
            drogon_model::simple12306::Users::Cols::_username).findAll();

    if (userFind.empty() || *(userFind.at(0).getPassword()) != password) {
        Json::Value json;
        json["code"] = 401;
        json["msg"] = "用户名或密码错误";
        json["data"] = "";
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
        return;
    } else {
        Json::Value json;
        json["code"] = 200;
        json["msg"] = "登录成功";
        // 生成token

        //返回用户数据，包括用户名，用户id，是否验证，是否学生
        Json::Value data;
        data["username"] = *(userFind.at(0).getUsername());
        data["userId"] = *(userFind.at(0).getUserId());
        data["isVerified"] = *(userFind.at(0).getIsverified());
        data["isStudent"] = *(userFind.at(0).getIsstudent());
        json["data"] = data;
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
}