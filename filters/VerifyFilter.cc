/**
 *
 *  VerifyFilter.cc
 *
 */

#include <drogon/orm/DbClient.h>
#include <drogon/HttpAppFramework.h>
#include <drogon/orm/Mapper.h>
#include "VerifyFilter.h"
#include "Users.h"

using namespace drogon;

void VerifyFilter::doFilter(const HttpRequestPtr &req,
                           FilterCallback &&fcb,
                           FilterChainCallback &&fccb) {
    //req是个json，从中获取userId
    auto reqJson = req->getJsonObject();
    int userId = (*reqJson)["userId"].asInt();
    //如果对应用户的isVerified为true，放行
    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Users> mapper(client);
    std::vector<drogon_model::simple12306::Users> userFind = mapper.orderBy(
            drogon_model::simple12306::Users::Cols::_user_id).findAll();

    LOG_DEBUG << "实名验证过滤器:  " << userId;


    for (const drogon_model::simple12306::Users& user: userFind) {
        if (user.getValueOfUserId() == userId){
            LOG_DEBUG << "find user: " << *(user.getUsername());
            if (user.getIsVerified()) {
                fccb();
                return;
            }
        }
    }
    Json::Value json;
    json["code"] = 406;
    json["msg"] = "未实名认证，请先完成实名认证";
    json["data"] = "";
    auto resp = HttpResponse::newHttpJsonResponse(json);
    fcb(resp);
}
