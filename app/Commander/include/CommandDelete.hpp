#pragma once 

#include <Command.hpp>

class CommandDelete : public Command
{
public:
    CommandDelete(std::string path_to_exe,
                  std::string name  = "delete", 
                  std::string info = "Delete all tables from DataBase"
                 );
    void execute(std::string params_of_command) override; 
};