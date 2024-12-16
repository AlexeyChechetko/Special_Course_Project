#pragma once

#include <vector>
#include "Data.hpp"

class DataLoader
{
public:
    virtual std::vector<Data>* load() = 0;
};