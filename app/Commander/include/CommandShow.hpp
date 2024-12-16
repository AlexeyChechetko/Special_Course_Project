#pragma once 

#include <Command.hpp>

class CommandShow : public Command
{
public:
    CommandShow(std::string path_to_exe,
                std::string name  = "show", 
                std::string info = "Show tables from DataBase"
               );
    void execute(std::string params_of_command) override; 
};