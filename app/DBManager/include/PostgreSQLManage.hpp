#pragma once

#include <string>
#include "libpq-fe.h"
#include "DBManage.hpp"

class PostgreSQLManage : public DBManage
{
public:
    PostgreSQLManage(std::string data_base_name, std::string user_name, 
                     std::string user_password, std::string host, std::string port);
    void show() override;
    void _delete() override;
    void print() override;
private:
    std::string connection_info;
}; 