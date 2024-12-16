#pragma once

#include <string>

class Request
{
public:
    Request(std::string command);
    std::string get_command();
private:
    std::string command;
};