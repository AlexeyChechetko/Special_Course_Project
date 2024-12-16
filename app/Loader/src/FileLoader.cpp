#include "FileLoader.hpp"

#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>

FileLoader::FileLoader(std::string path_to_file)
{
    this->path_to_file = path_to_file;
}

std::vector<std::string>* FileLoader::separating_a_line_by_commas(std::string line)
{
    std::vector<std::string>* tokens = new std::vector<std::string>(); 
    std::string token;

    std::stringstream ss(line);

    while (std::getline(ss, token, ',')) 
    {
        tokens->push_back(token); 
    }

    return tokens;
}

std::vector<Data>* FileLoader::load()
{
    std::ifstream file(path_to_file);

    std::vector<Data>* _Data_vec = new std::vector<Data>();
    std::string line;
    std::vector<std::string>* tokens;

    std::getline(file, line);
    while(std::getline(file, line))
    {
        tokens = separating_a_line_by_commas(line);
        _Data_vec->push_back(Data((*tokens)[0], (*tokens)[1], (*tokens)[2], (*tokens)[3], 
                                  atof((*tokens)[4].c_str()), atoi((*tokens)[5].c_str())));
    }
    file.close();
    
    tokens->clear();
    delete tokens;

    return _Data_vec;
}
