#include "Request.hpp"

Request::Request(std::string command)
{
    this->command = command;
}

std::string Request::get_command()
{
    return command;
}