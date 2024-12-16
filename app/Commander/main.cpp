#include <iostream>
#include <string>
#include <cstdlib>


#include <Controller.hpp>

int main(int argc, char* argv[])
{
    Controller* _Controller = new Controller();
    _Controller->create_commands();
    
    std::string command;

    bool flag = true;
    while (flag)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        flag = _Controller->hanlde_command(command);
    } 

    delete _Controller;

    return 0;
}