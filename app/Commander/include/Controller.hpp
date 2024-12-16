#pragma once

#include <vector>
#include <string>
#include <Command.hpp>

class Controller
{
public:
    void create_commands();
    bool hanlde_command(std::string command);
    ~Controller();
private:
    std::vector<std::string>* parse_command(std::string command);
    std::string* concat_params(std::vector<std::string>* params);
private:
    std::vector<Command*> commands;
};