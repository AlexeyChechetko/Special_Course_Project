#include "PostgreSQLManage.hpp"

#include <iostream>

PostgreSQLManage::PostgreSQLManage(std::string data_base_name, std::string user_name, 
                     std::string user_password, std::string host, std::string port)
{
    this->connection_info = "dbname=" + data_base_name + 
                                  " user="   + user_name + 
                                  " password=" + user_password + 
                                  " host=" + host +
                                  " port=" + port;
}

void PostgreSQLManage::show()
{
    PGconn *connection = PQconnectdb(connection_info.c_str());

    // Проверка на успешное подключение
    if (PQstatus(connection) != CONNECTION_OK) 
    {
        std::cerr << "Ошибка подключения: " << PQerrorMessage(connection) << std::endl;
        PQfinish(connection);
        return;
    }

    // Выполняем SQL-запрос для получения всех таблиц
    PGresult *result = PQexec(connection, "SELECT tablename FROM pg_tables WHERE schemaname = 'public';");

    // Проверяем, успешно ли выполнен запрос
    if (PQresultStatus(result) != PGRES_TUPLES_OK) 
    {
        std::cerr << "Ошибка выполнения запроса: " << PQerrorMessage(connection) << std::endl;
        PQclear(result);
        return;
    }

    // Выводим названия таблиц
    int rows = PQntuples(result);
    std::cout << "Таблицы в базе данных:" << std::endl;
    for (int i = 0; i < rows; ++i) 
    {
        // Получаем значение из первой колонки
        std::cout << PQgetvalue(result, i, 0) << std::endl; 
    }

    // Освобождаем память
    PQclear(result);

    PQfinish(connection);
}

void PostgreSQLManage::_delete()
{
    PGconn *connection = PQconnectdb(connection_info.c_str());

    // Проверка на успешное подключение
    if (PQstatus(connection) != CONNECTION_OK) 
    {
        std::cerr << "Ошибка подключения: " << PQerrorMessage(connection) << std::endl;
        PQfinish(connection);
        return;
    }

    std::string delete_table = "DROP TABLE data;";

    // Выполняем SQL-запрос для получения всех таблиц
    PGresult *result = PQexec(connection, delete_table.c_str());

    // Проверяем, успешно ли выполнен запрос
    if (PQresultStatus(result) != PGRES_COMMAND_OK) 
    {
        std::cerr << "Ошибка выполнения запроса: " << PQerrorMessage(connection) << std::endl;
        PQclear(result);
        return;
    }

    // Освобождаем память
    PQclear(result);

    PQfinish(connection);
}

void PostgreSQLManage::print()
{
    PGconn *connection = PQconnectdb(connection_info.c_str());

    // Проверка на успешное подключение
    if (PQstatus(connection) != CONNECTION_OK) 
    {
        std::cerr << "Ошибка подключения: " << PQerrorMessage(connection) << std::endl;
        PQfinish(connection);
        return;
    }   

    std::string print_table = "SELECT * FROM data;";

    // Выполняем SQL-запрос для получения всех таблиц
    PGresult *result = PQexec(connection, print_table.c_str());

    // Проверяем, успешно ли выполнен запрос
    if (PQresultStatus(result) != PGRES_TUPLES_OK) 
    {
        std::cerr << "Ошибка выполнения запроса: " << PQerrorMessage(connection) << std::endl;
        PQclear(result);
        return;
    }

    // Выводим названия столбцов
    int columns = PQnfields(result);
    for (int i = 0; i < columns; ++i)
    {
        std::cout << PQfname(result, i) << "   ";
    }
    std::cout << "\n";

    // Выводим строки таблицы
    int rows = PQntuples(result);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j)
        {        
            std::cout << PQgetvalue(result, i, j) << "   ";
        }
        std::cout << "\n"; 
    }

    // Освобождаем память
    PQclear(result);

    PQfinish(connection);
}