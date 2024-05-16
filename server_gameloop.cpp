#include "server_gameloop.h"

#include <utility>


Gameloop::Gameloop(Socket && skt, 
            bool * server_is_down):
            skt_accept(std::move(skt)),
            server_is_down(server_is_down){
    // threads para acceptar sockets:

    accept = new AcceptFunc(std::ref(skt_accept),
                                &queue,
                                std::ref(client_queue));
    accept->start();
}


Gameloop::~Gameloop(){
    accept->join();
    delete accept;
}

void Gameloop::run(){
    while (!*server_is_down){
        unsigned char value = 0x00;
        if (queue.try_pop(value))
        {
            enemigos.changedOneEnemytoDied(&client_queue);
        }

        enemigos.changedEnemisToAlive(&client_queue);
        this->sleep(200);
    }
    accept->close();
}
