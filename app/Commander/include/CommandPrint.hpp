#pragma once 

#include <Command.hpp>

class CommandPrint : public Command
{
public:
    CommandPrint(std::string path_to_exe,
                std::string name  = "print", 
                std::string info = "select * from table"
               );
    void execute(std::string params_of_command) override; 
};