#ifndef __MONITOR_SERVER_H__
#define __MONITOR_SERVER_H__

#include <string>
#include <vector>

#include "common_queue.h"
#include "server_juego_mensaje.h"

class ServerMonitor {
private:
    std::mutex m;
    std::vector<Queue<ServerJuegoMensaje>*> vector_de_server_msg;

public:
    ServerMonitor();

    void agregar_queue(Queue<ServerJuegoMensaje>* queue);

    void broadcastear(const ServerJuegoMensaje& msg);

    void borrar_queue(Queue<ServerJuegoMensaje>* queue);

    ~ServerMonitor();
};

#endif
