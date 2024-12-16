#include "PosgreSQLSave.hpp"

#include <sstream>
#include <iostream>
#include "libpq-fe.h"

PostgreSQLSave::PostgreSQLSave(std::string data_base_name, std::string user_name, 
                     std::string user_password, std::string host, std::string port)
{
    this->connection_info = "dbname=" + data_base_name + 
                                  " user="   + user_name + 
                                  " password=" + user_password + 
                                  " host=" + host +
                                  " port=" + port;
}

void PostgreSQLSave::save(std::vector<Data>* _Data)
{
    PGconn *connection = PQconnectdb(connection_info.c_str());

    // Проверка на успешное подключение
    if (PQstatus(connection) != CONNECTION_OK) 
    {
        std::cerr << "Ошибка подключения: " << PQerrorMessage(connection) << std::endl;
        PQfinish(connection);
        return;
    }

    std::string save_to_db = "";
    for (int i = 0; i < _Data->size(); ++i)
    {
        save_to_db += "INSERT INTO data (ticker, per, date, time, close, vol) ";
        save_to_db += "VALUES (";

        save_to_db += "'";
        save_to_db += (*_Data)[i].ticker;
        save_to_db += "', ";

        save_to_db += "'";
        save_to_db += (*_Data)[i].per;
        save_to_db += "', ";

        save_to_db += "'";
        save_to_db += (*_Data)[i].date;
        save_to_db += "', ";

        save_to_db += "'";
        save_to_db += (*_Data)[i].time;
        save_to_db += "', ";

        std::ostringstream strs1;
        std::string tmp_str1;
        strs1 << (*_Data)[i].close;
        tmp_str1 = strs1.str();
        save_to_db += "'";
        save_to_db += tmp_str1;
        save_to_db += "', ";

        std::ostringstream strs2;
        std::string tmp_str2;
        strs2 << (*_Data)[i].vol;
        tmp_str2 = strs2.str();
        save_to_db += "'";
        save_to_db += tmp_str2;
        save_to_db += "');";

    // Выполняем SQL-запрос
    PGresult *res = PQexec(connection, save_to_db.c_str());

    // Проверяем результат выполнения запроса
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Ошибка при выполнении запроса: " << PQerrorMessage(connection) << std::endl;
        PQclear(res);
        PQfinish(connection);
        return;
    }

    // Освобождаем память и закрываем соединение
    PQclear(res);
    save_to_db = "";
    }
    PQfinish(connection);
}

void PostgreSQLSave::create_table()
{
    PGconn *connection = PQconnectdb(connection_info.c_str());

    // Проверка на успешное подключение
    if (PQstatus(connection) != CONNECTION_OK) 
    {
        std::cerr << "Ошибка подключения: " << PQerrorMessage(connection) << std::endl;
        PQfinish(connection);
        return;
    }

    std::string create_table_in_db = "CREATE TABLE IF NOT EXISTS data (ticker char(5) NOT NULL, per char(2) NOT NULL, date char(9) NOT NULL, time char(7) NOT NULL, close float NOT NULL, vol integer);";

    // Выполняем SQL-запрос
    PGresult *res = PQexec(connection, create_table_in_db.c_str());

    // Проверяем результат выполнения запроса
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Ошибка при выполнении запроса: " << PQerrorMessage(connection) << std::endl;
        PQclear(res);
        PQfinish(connection);
        return;
    }

    // Освобождаем память и закрываем соединение
    PQclear(res);
    PQfinish(connection);
}
