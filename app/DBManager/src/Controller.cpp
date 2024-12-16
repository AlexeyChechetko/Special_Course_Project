#include "Controller.hpp"

#include "DBManage.hpp"
#include "PostgreSQLManage.hpp"

void Controller::handle_request(Request* request)
{
    DBManage* _DBManage = new PostgreSQLManage("mydb", "postgres", "postgres", "db", "5432");
    if (request->get_command() == "show")
    {
        _DBManage->show();
    }
    else if (request->get_command() == "delete")
    {
        _DBManage->_delete();
    }
    else
    {
        _DBManage->print();
    }
    delete _DBManage;
}