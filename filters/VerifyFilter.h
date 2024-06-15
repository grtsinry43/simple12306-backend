/**
 *
 *  VerifyFilter.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>

using namespace drogon;


class VerifyFilter : public HttpFilter<VerifyFilter> {
public:
    VerifyFilter() = default;

    void doFilter(const HttpRequestPtr &req,
                  FilterCallback &&fcb,
                  FilterChainCallback &&fccb) override;
};

