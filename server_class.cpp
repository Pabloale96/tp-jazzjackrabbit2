#include <string>
#include <sstream>
#include <list>
#include <iostream>
#include <utility>
#include <vector>

#include "server_class.h"
#include "common_functor.h"
#include "common_vectorProtected.h"
#include "common_thread.h"

Server::~Server(){}

Server::Server(char * servername):skt_accept(servername){
}
 
void Server::run(){

    // variable que controla que el servidor siga corriendo
    bool server_is_down = false; 

    char c;

    // threads para acceptar sockets:
    Thread * game = new Gameloop(std::move(skt_accept),&server_is_down);
    game->start();

    while (std::cin.get(c)){
        if (c == 'q') {
            break;
        }
    }
    server_is_down =true;
    game->join();
    delete game;
}
