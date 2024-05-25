//
// Created by grtsinry43 on 24-5-19.
//

#include <drogon/HttpAppFramework.h>
#include "UserFilter.h"

class LoginFilter : public drogon::HttpFilter<LoginFilter> {
public:
    void doFilter(const drogon::HttpRequestPtr &req,
                  drogon::FilterCallback &&fcb,
                  drogon::FilterChainCallback &&fccb) override {
        //从req的请求头中获取用户的token
        auto token = req->getHeader("token");
        LOG_DEBUG << "token:" << token;
        if (token.empty()) {
            //如果token为空，返回401错误
            Json::Value json;
            json["code"] = 401;
            json["msg"] = "未登录或登录已过期";
            auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
            fcb(resp);
        }
    };
};