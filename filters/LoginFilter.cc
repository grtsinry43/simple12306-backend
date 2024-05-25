/**
 *
 *  LoginFilter.cc
 *
 */

#include "LoginFilter.h"

using namespace drogon;

void LoginFilter::doFilter(const HttpRequestPtr &req,
                           FilterCallback &&fcb,
                           FilterChainCallback &&fccb) {
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
    } else {
        //如果token不为空，放行
        fccb();
    }
}
