#include <drogon/orm/Mapper.h>
#include "api_order.h"
#include "Orders.h"
#include "Tickets.h"


using namespace api;

/**
 * 新建订单
 * @param req
 * @param callback
 */
void order::newOrder(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    auto json = req->getJsonObject();
    int userId = (*json)["userId"].asInt();
    int ticketId = (*json)["ticketId"].asInt();
    auto userInfo = (*json)["userInfo"];
    std::string name = userInfo["name"].asString();
    std::string phone = userInfo["phone"].asString();
    std::string idCard = userInfo["idCard"].asString();
    std::string type = userInfo["type"].asString();
    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Orders> mapper(client);
    drogon_model::simple12306::Orders order;
    order.setUserId(userId);
    order.setTicketId(ticketId);
    Json::Value info;
    info["name"] = name;
    info["phone"] = phone;
    info["idCard"] = idCard;
    info["type"] = type;
    order.setUserInfo(info.toStyledString());
    order.setCreatedAt(trantor::Date::date());
    order.setStatus(0);
    try {
        mapper.insert(order);
        Json::Value json1;
        json1["code"] = 200;
        json1["msg"] = "";
        json1["data"] = order.toJson();
        auto resp = HttpResponse::newHttpJsonResponse(json1);
        callback(resp);
    } catch (const std::exception &e) {
        Json::Value json1;
        json1["code"] = 500;
        json1["msg"] = e.what();
        auto resp = HttpResponse::newHttpJsonResponse(json1);
        callback(resp);
    }
}

bool order::haveTicket(int ticketId,int typeId) {
    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Tickets> mapper(client);
    auto ticket = mapper.findByPrimaryKey(ticketId);

}
