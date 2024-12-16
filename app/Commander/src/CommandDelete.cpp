#include <CommandDelete.hpp>
#include <iostream>
#include <cstdlib>

CommandDelete::CommandDelete(std::string path_to_exe, std::string name, std::string info) : Command(path_to_exe, name, info)
{

}

void CommandDelete::execute(std::string params_of_command)
{
    std::string command = "./build/DBManager/DBManager ";
    command += params_of_command;

    std::system(command.c_str());
}