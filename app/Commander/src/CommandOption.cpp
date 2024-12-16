#include <CommandOption.hpp>
#include <iostream>

CommandOption::CommandOption(std::string path_to_exe, std::string name, std::string info) : Command(path_to_exe, name, info)
{

}

void CommandOption::execute(std::string params_of_command)
{
    std::string command = "./build/OptionPricer/OptionPricer ";
    command += params_of_command;

    std::system(command.c_str());
}