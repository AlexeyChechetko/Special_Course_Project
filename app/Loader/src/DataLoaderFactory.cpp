#include "DataLoaderFactory.hpp"

#include "FileLoader.hpp"

DataLoader* DataLoaderFactory::create_loader(Request* request)
{
    if (request->get_download_method() == "file")
    {
        return new FileLoader(request->get_params());
    }
    else
    {
        return new FileLoader(request->get_params());
    }
}