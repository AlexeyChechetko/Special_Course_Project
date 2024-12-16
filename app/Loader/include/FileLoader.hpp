#pragma once

#include "DataLoader.hpp"
#include <string>

class FileLoader : public DataLoader
{
public:
    FileLoader(std::string path_to_file);
    std::vector<Data>* load() override;
private:
    std::vector<std::string>* separating_a_line_by_commas(std::string line);
private:
    std::string path_to_file;
};