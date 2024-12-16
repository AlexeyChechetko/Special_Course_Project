#pragma once 

#include <Command.hpp>

class CommandOption : public Command
{
public:
    CommandOption(std::string path_to_exe,
                  std::string name  = "option", 
                  std::string info = "Count price of option"
                 );
    void execute(std::string params_of_command) override; 
};