#pragma once

#include <string>

class Request
{
public:
    Request(std::string download_method, std::string params);
    std::string get_download_method();
    std::string get_params();
private:
    std::string download_method;
    std::string params;
};