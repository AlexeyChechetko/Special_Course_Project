#pragma once 

#include <Command.hpp>

class CommandLoad : public Command
{
public:
    CommandLoad(std::string path_to_exe,
                std::string name  = "load", 
                std::string info = "Save data to DataBase"
               );
    void execute(std::string params_of_command) override; 
};