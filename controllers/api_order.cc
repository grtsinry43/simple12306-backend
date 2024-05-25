#include <drogon/orm/Mapper.h>
#include "api_order.h"
#include "Orders.h"
#include "Tickets.h"
#include "api_tickets.h"


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
    int type = (*json)["type"].asInt();
    auto userInfo = (*json)["userInfo"];
    std::string name = userInfo["name"].asString();
    std::string phone = userInfo["phone"].asString();
    std::string idCard = userInfo["idCard"].asString();
    if (!tickets::haveTicket(ticketId, type)) {
        Json::Value json1;
        json1["code"] = 405;
        json1["msg"] = "票已售完";
        auto resp = HttpResponse::newHttpJsonResponse(json1);
        callback(resp);
        return;
    }
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
        tickets::buyTicket(ticketId, type);
        Json::Value json1;
        json1["code"] = 200;
        json1["msg"] = "";
        Json::Value data;
        data["created_at"] = order.getCreatedAt()->toCustomedFormattedString("%Y-%m-%d %H:%M:%S");
        data["id"] = order.getValueOfId();
        data["status"] = order.getValueOfStatus();
        data["ticket_id"] = order.getValueOfTicketId();
        data["user_id"] = order.getValueOfUserId();
        Json::Value userInfo1;
        Json::Reader reader;
        reader.parse(order.getValueOfUserInfo(), userInfo1);
        data["userInfo"] = userInfo1;
        json1["data"] = data;
        auto resp = HttpResponse::newHttpJsonResponse(json1);
        callback(resp);
    } catch (const std::exception &e) {
        Json::Value json1;
        json1["code"] = 500;
        LOG_DEBUG << e.what();
        json1["msg"] = "服务器错误，订单创建失败";
        auto resp = HttpResponse::newHttpJsonResponse(json1);
        callback(resp);
    }
}

void
order::payOrder(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                const std::string &orderId) const {
    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Orders> mapper(client);
    std::vector<drogon_model::simple12306::Orders> ordersFind = mapper.orderBy(
            drogon_model::simple12306::Orders::Cols::_id).findAll();
    for (auto &order: ordersFind) {
        if (order.getValueOfId() == std::stoi(orderId)) {
            if (order.getValueOfStatus() == 1) {
                Json::Value json1;
                json1["code"] = 403;
                json1["msg"] = "订单已支付";
                auto resp = HttpResponse::newHttpJsonResponse(json1);
                callback(resp);
                return;
            } else {
                try {
                    order.setStatus(1);
                    mapper.update(order);
                    Json::Value json1;
                    json1["code"] = 200;
                    json1["msg"] = "";
                    Json::Value data;
                    data["created_at"] = order.getCreatedAt()->toCustomedFormattedString("%Y-%m-%d %H:%M:%S");
                    data["id"] = order.getValueOfId();
                    data["status"] = order.getValueOfStatus();
                    data["ticket_id"] = order.getValueOfTicketId();
                    data["user_id"] = order.getValueOfUserId();
                    Json::Value userInfo1;
                    Json::Reader reader;
                    reader.parse(order.getValueOfUserInfo(), userInfo1);
                    data["userInfo"] = userInfo1;
                    json1["data"] = data;
                    auto resp = HttpResponse::newHttpJsonResponse(json1);
                    callback(resp);
                    return;
                } catch (const std::exception &e) {
                    Json::Value json1;
                    json1["code"] = 500;
                    LOG_DEBUG << e.what();
                    json1["msg"] = "服务器错误，订单支付失败";
                    auto resp = HttpResponse::newHttpJsonResponse(json1);
                    callback(resp);
                    return;
                }
            }
        }
    }
}

