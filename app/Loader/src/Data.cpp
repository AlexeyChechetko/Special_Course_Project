#include "Data.hpp"

Data::Data(std::string ticker, std::string per,
         std::string date, std::string time,
         double close, int vol)
{
    this->ticker = ticker;
    this->per = per;
    this->date = date;
    this->time = time;
    this->close = close;
    this->vol = vol;
}