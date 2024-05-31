#include <drogon/drogon.h>

int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 5555);
    //Load config file
    drogon::app().loadConfigFile("../config.yaml");

    // Add a new preprocessor
    drogon::app().registerPreHandlingAdvice([](const drogon::HttpRequestPtr &req,
                                               drogon::AdviceCallback &&acb,
                                               drogon::AdviceChainCallback &&nextCallback) {
        // Add CORS headers

        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->addHeader("Access-Control-Allow-Origin", "*");

        nextCallback();

    });

    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();

    return 0;
}