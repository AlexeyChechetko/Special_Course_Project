#pragma once

#include <string>
#include <vector>
#include "DBSave.hpp"

class PostgreSQLSave : public DBSave
{
public:
    PostgreSQLSave(std::string data_base_name, std::string user_name, 
                     std::string user_password, std::string host, std::string port);
    void save(std::vector<Data>* _Data) override;
    void create_table() override;
private:
    std::string connection_info;
};