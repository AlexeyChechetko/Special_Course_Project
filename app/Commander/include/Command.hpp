#pragma once 

#include <vector>
#include <string>

class Command
{
public:
    Command(std::string path_to_exe, std::string name, std::string info);
    std::string get_name();
    std::string get_info();
    virtual void execute(std::string params_of_command) = 0;
private:
    std::string name;
    std::string info;
    std::string path_to_exe;
};