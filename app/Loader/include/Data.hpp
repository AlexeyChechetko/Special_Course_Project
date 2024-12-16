#pragma once

#include <string>

struct Data
{
    Data(std::string ticker, std::string per,
         std::string date, std::string time,
         double close, int vol);

    std::string ticker;
    std::string per;
    std::string date;
    std::string time;
    double close;
    int vol; 
};