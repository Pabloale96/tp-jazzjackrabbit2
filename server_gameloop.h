#ifndef Gameloop_H
#define Gameloop_H

#include <list>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#include "common_protocol.h"
#include "common_thread.h"
#include "common_functor.h"
#include "common_thread.h"
#include "server_logicaEnemigos.h"
#include "common_vectorProtected.h"

class Gameloop : public Thread {

    private:
    Socket skt_accept;
    logicaEnemigos enemigos;
    bool * server_is_down;
    AcceptFunc * accept;
    Queue<unsigned char> queue = Queue<unsigned char>(10);
    VectorProtected<Queue<msg_client_t> *> client_queue;
    std::mutex mtx;
    std::condition_variable wait_queue;

    public:
    explicit Gameloop(Socket && skt, bool * server_is_down);
    ~Gameloop();

    virtual void run() override;

    void sleep(int timeInms){
        auto milliseconds_to_sleep = std::chrono::milliseconds(timeInms);
        std::this_thread::sleep_for(milliseconds_to_sleep);
    }
};
#endif
