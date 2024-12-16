#include "Request.hpp"

Request::Request(std::string download_method, std::string params)
{
    this->download_method = download_method;
    this->params = params;
}

std::string Request::get_download_method()
{
    return download_method;
}

std::string Request::get_params()
{
    return params;
}