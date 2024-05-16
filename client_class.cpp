#include <map>
#include <string>
#include <sstream>
#include <list>
#include <iostream>
#include <vector>
#include "client_class.h"
#include "common_functor.h"

Client::Client(char * hostname, char * servername)
    :protocol(hostname, servername),
    action(&protocol,&was_closed) {}

Client::~Client(){}

void Client::run(){
    std::string lineFromCIN;
    while (std::getline(std::cin, lineFromCIN))
    {   
        if (lineFromCIN!="Salir") {
            action.setAction(lineFromCIN);
            action.doAction();
        } else {
            break;
        }
    }
    try
    {
        protocol.shutdown();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error shutdown: "<< e.what() << '\n';
    }
}
