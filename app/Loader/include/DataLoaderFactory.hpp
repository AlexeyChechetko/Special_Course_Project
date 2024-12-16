#pragma once

#include "Request.hpp"
#include "DataLoader.hpp"

class DataLoaderFactory
{
public:
    DataLoader* create_loader(Request* request);
};