#include <Controller.hpp>

#include <CommandDelete.hpp>
#include <CommandLoad.hpp>
#include <CommandOption.hpp>
#include <CommandShow.hpp>
#include <CommandPrint.hpp>

#include <iostream>
#include <sstream>

void Controller::create_commands()
{
    CommandDelete* _CommandDelete = new CommandDelete("");
    CommandLoad* _CommandLoad = new CommandLoad("");
    CommandOption* _CommandOption = new CommandOption("");
    CommandShow* _CommandShow = new CommandShow("");
    CommandPrint* _CommandPrint = new CommandPrint("");

    this->commands.push_back(_CommandDelete);
    this->commands.push_back(_CommandLoad);
    this->commands.push_back(_CommandOption);
    this->commands.push_back(_CommandShow);  
    this->commands.push_back(_CommandPrint); 
}

bool Controller::hanlde_command(std::string command)
{
    if (command == "exit")
    {
        return false;
    }
    else if (command == "info")
    {
        std::cout << "\n";
        for (int i = 0; i < commands.size(); ++i)
        {
            std::cout << commands[i]->get_name() << ": " << commands[i]->get_info() << std::endl;
        }
        std::cout << "\n";
        return true;
    }
    else
    {
        std::vector<std::string>* split_command = parse_command(command);
        std::string first_word = (*split_command)[0];
        split_command->erase(split_command->begin());
        std::string _params;

        if (split_command->size() != 0)
        {
            _params = *concat_params(split_command);
        }
        else
        {
            _params = first_word;
        }

        for (int i = 0; i < commands.size(); ++i)
        {
            if (commands[i]->get_name() == first_word)
            {
                commands[i]->execute(_params);
                return true;
            }
        }
        
        split_command->clear();
        delete split_command;

        return false;
    }    
}

Controller::~Controller()
{
    for (int i = 0; i < commands.size(); ++i)
    {
        delete commands[i];
    }
    commands.clear();
}

std::vector<std::string>* Controller::parse_command(std::string command)
{
    std::vector<std::string>* split_command = new std::vector<std::string>();
    std::stringstream ss(command);
    std::string word;

    while (ss >> word) 
    {
        split_command->push_back(word);
    }

    return split_command;
}

std::string* Controller::concat_params(std::vector<std::string>* params)
{
    std::string* result = new std::string("");
    for (int i = 0; i < params->size(); ++i)
    {
        result->append((*params)[i]);
        result->append(" ");
    }
    result->erase(result->end() - 1);
    
    return result;
}