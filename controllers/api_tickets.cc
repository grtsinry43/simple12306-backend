#include <drogon/orm/Mapper.h>
#include "api_tickets.h"
#include "Tickets.h"

using namespace api;


std::string formatDate(trantor::Date date) {
    return date.toCustomedFormattedString("%Y-%m-%d %H:%M:%S");
}

void tickets::getTickets(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Tickets> mapper(client);
    std::vector<drogon_model::simple12306::Tickets> tickets = mapper.orderBy(
            drogon_model::simple12306::Tickets::Cols::_title).findAll();

    LOG_DEBUG << "getTickets: " << tickets.size();

    //返回数据列表
    Json::Value json;
    json["code"] = 200;
    json["msg"] = "";
    Json::Value data;
    for (auto &ticket: tickets) {
        Json::Value item;
        item["title"] = *(ticket.getTitle());
        item["from"] = *(ticket.getFrom());
        item["to"] = *(ticket.getTo());
        item["price"] = *(ticket.getPrice());
        //时间戳要转换成字符串
        item["start_date"] = formatDate(*(ticket.getStartDate()));
        item["end_date"] = formatDate(*(ticket.getEndDate()));
        item["train_type"] = *(ticket.getTrainType());
        item["type_1"] = ticket.getValueOfType1();
        item["type_2"] = ticket.getValueOfType2();
        item["type_3"] = ticket.getValueOfType3();
        item["type_4"] = ticket.getValueOfType4();
        data.append(item);
    }
    json["data"] = data;
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

bool tickets::haveTicket(int ticketId, int typeId) {
    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Tickets> mapper(client);
    std::vector<drogon_model::simple12306::Tickets> ticketsFind = mapper.orderBy(
            drogon_model::simple12306::Tickets::Cols::_id).findAll();
    if (ticketsFind.empty()) {
        return false;
    } else {
        for (auto &ticket: ticketsFind) {
            if (ticket.getValueOfId() == ticketId) {
                switch (typeId) {
                    case 1:
                        return ticket.getValueOfType1() > 0;
                    case 2:
                        return ticket.getValueOfType2() > 0;
                    case 3:
                        return ticket.getValueOfType3() > 0;
                    case 4:
                        return ticket.getValueOfType4() > 0;
                    default:
                        return false;
                }
            }
        }
    }
}

void tickets::buyTicket(int ticketId, int typeId) {
    drogon::orm::DbClientPtr client = drogon::app().getDbClient();
    drogon::orm::Mapper<drogon_model::simple12306::Tickets> mapper(client);
    std::vector<drogon_model::simple12306::Tickets> ticketsFind = mapper.orderBy(
            drogon_model::simple12306::Tickets::Cols::_id).findAll();
    if (ticketsFind.empty()) {
        return;
    } else {
        for (auto &ticket: ticketsFind) {
            //对的id才匹配
            if (ticket.getValueOfId() == ticketId) {
                switch (typeId) {
                    case 1:
                        ticket.setType1(ticket.getValueOfType1() - 1);
                        break;
                    case 2:
                        ticket.setType2(ticket.getValueOfType2() - 1);
                        break;
                    case 3:
                        ticket.setType3(ticket.getValueOfType3() - 1);
                        break;
                    case 4:
                        ticket.setType4(ticket.getValueOfType4() - 1);
                        break;
                    default:
                        return;
                }
                mapper.update(ticket);
            }
        }
    }
}
