#pragma once

#include <vector>
#include "Data.hpp"

class DBSave
{
public:
    virtual void save(std::vector<Data>* _Data) = 0;
    virtual void create_table() = 0;
};