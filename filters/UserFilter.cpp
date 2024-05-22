//
// Created by grtsinry43 on 24-5-19.
//

#include <drogon/HttpAppFramework.h>
#include "UserFilter.h"

class LoginFilter:public drogon::HttpFilter<LoginFilter>
{
public:
    void doFilter(const drogon::HttpRequestPtr &req,
                  drogon::FilterCallback &&fcb,
                  drogon::FilterChainCallback &&fccb) override {
        //从req的请求头中获取用户的token
        auto token = req->getHeader("token");
        LOG_DEBUG << "token:" << token;
    };
};