#include "Controller.hpp"

#include "Data.hpp"
#include "DataLoader.hpp"
#include "DataLoaderFactory.hpp"
#include "DBSave.hpp"
#include "PosgreSQLSave.hpp"

#include <iostream>

void Controller::handle_request(Request* request)
{
    DataLoaderFactory* _DataLoaderFactory = new DataLoaderFactory();
    DataLoader* _DataLoader = _DataLoaderFactory->create_loader(request);

    std::vector<Data>* _Data = _DataLoader->load();

    DBSave* _DBSave = new PostgreSQLSave("mydb", "postgres", "postgres", "db", "5432");

    _DBSave->create_table();
    _DBSave->save(_Data);

    delete _DataLoaderFactory;
    delete _DataLoader;
    _Data->clear();
    delete _Data;
    delete _DBSave;
}