#include <Command.hpp>

Command::Command(std::string path_to_exe, std::string name, std::string info)
{
    this->path_to_exe = path_to_exe;
    this->name = name;
    this->info = info;
}

std::string Command::get_name()
{
    return name;
}

std::string Command::get_info()
{
    return info;
}