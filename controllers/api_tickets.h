#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api {
    class tickets : public drogon::HttpController<tickets> {
    public:
        METHOD_LIST_BEGIN
            // use METHOD_ADD to add your custom processing function here;
            // METHOD_ADD(tickets::get, "/{2}/{1}", Get); // path is /api/tickets/{arg2}/{arg1}
            // METHOD_ADD(tickets::your_method_name, "/{1}/{2}/list", Get); // path is /api/tickets/{arg1}/{arg2}/list
            // ADD_METHOD_TO(tickets::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
            METHOD_ADD(tickets::getTickets, "/list", Get);
            METHOD_ADD(tickets::searchTickets, "/search?from={1}&to={2}&startPrice={3}&endPrice={4}&date={5}", Get);

        METHOD_LIST_END

        // your declaration of processing function maybe like this:
        // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
        // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
        void getTickets(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const;

        static bool haveTicket(int ticketId, int typeId);

        static void buyTicket(int ticketId, int typeId);

        static void returnTicket(int ticketId, int typeId);

        void searchTickets(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                           const std::string &from, const std::string &to, const std::string &date,
                           const std::string &startPrice, const std::string &endPrice);
    };
}
