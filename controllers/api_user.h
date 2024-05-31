#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api {
    class user : public drogon::HttpController<user> {
    public:
        METHOD_LIST_BEGIN
            // use METHOD_ADD to add your custom processing function here;
            // METHOD_ADD(user::get, "/{2}/{1}", Get); // path is /api/user/{arg2}/{arg1}
            // METHOD_ADD(user::your_method_name, "/{1}/{2}/list", Get); // path is /api/user/{arg1}/{arg2}/list
            // ADD_METHOD_TO(user::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
            METHOD_ADD(user::login, "/login?username={1}&password={2}", Post);
            METHOD_ADD(user::reg, "/reg?username={1}&password={2}", Post);
            METHOD_ADD(user::deleteUser, "/del?username={1}&password={2}", Delete);
            METHOD_ADD(user::getInfo, "/info?username={1}", Get, "LoginFilter");
            METHOD_ADD(user::updateUser, "/update?username={1}&phone={2}&email={3}&region={4}&gender={5}", Put,
                       "LoginFilter");
            METHOD_ADD(user::verify, "/verify?username={1}", Post, "LoginFilter");
            METHOD_ADD(user::verifyEdu, "/edu?username={1}", Post, "LoginFilter");

        METHOD_LIST_END

        // your declaration of processing function maybe like this:
        // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
        // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
        void login(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                   const std::string &username, const std::string &password) const;

        //获取用户信息
        void getInfo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                     const std::string &username);

        void reg(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                 const std::string &username, const std::string &password) const;

        void deleteUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                        const std::string &username, const std::string &password) const;

        void updateUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                        const std::string &username, const std::string &phone, const std::string &email,
                        const std::string &region, const std::string &gender) const;

        void verify(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                    const std::string &username) const;

        void verifyEdu(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                       const std::string &username) const;

    };
}
