#ifndef __MONITOR_SERVER_H__
#define __MONITOR_SERVER_H__

#include <memory>
#include <vector>

#include "../common_src/common_queue.h"
#include "../server_src/server_juego_mensaje.h"

class ServerMonitor {
private:
    std::mutex m;
    std::vector<Queue<std::shared_ptr<ServerJuegoMensaje>>*> vector_de_server_msg;

public:
    ServerMonitor();

    void agregar_queue(Queue<std::shared_ptr<ServerJuegoMensaje>>& queue);

    void broadcastear(const ServerJuegoMensaje& msg);

    void borrar_queue(Queue<std::shared_ptr<ServerJuegoMensaje>>& queue);

    ~ServerMonitor();
};

#endif
