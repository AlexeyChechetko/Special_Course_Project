#include <CommandLoad.hpp>
#include <iostream>
#include <cstdlib>

CommandLoad::CommandLoad(std::string path_to_exe, std::string name, std::string info) : Command(path_to_exe, name, info)
{

}

void CommandLoad::execute(std::string params_of_command)
{
    std::string command = "./build/Loader/Loader ";
    command += params_of_command;

    std::system(command.c_str());
}