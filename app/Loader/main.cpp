#include <iostream>

#include "Controller.hpp"

int main(int argc, char* argv[])
{
    Request* request = new Request(argv[1], argv[2]);

    Controller* _Controller = new Controller();
    _Controller->handle_request(request);

    delete request;
    delete _Controller;

    return 0;
}