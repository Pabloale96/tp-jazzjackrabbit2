#include "../server_src/server_monitor.h"

#include <algorithm>

ServerMonitor::ServerMonitor(/* args */) {}

void ServerMonitor::agregar_queue(Queue<std::shared_ptr<ServerJuegoMensaje>>& nueva_queue) {
    std::unique_lock<std::mutex> lock(m);
    vector_de_server_msg.push_back(&nueva_queue);
}

void ServerMonitor::broadcastear(const ServerJuegoMensaje& msg) {
    std::unique_lock<std::mutex> lck(m);
    for (size_t i = 0; i < vector_de_server_msg.size(); ++i) {
        try {
            vector_de_server_msg[i]->try_push(std::make_shared<ServerJuegoMensaje>(msg));
        } catch (const ClosedQueue&) {
            vector_de_server_msg.erase(
                    std::remove(vector_de_server_msg.begin(), vector_de_server_msg.end(),
                                vector_de_server_msg[i]),
                    vector_de_server_msg.end());
            // --i;
        }
    }
}

void ServerMonitor::borrar_queue(Queue<std::shared_ptr<ServerJuegoMensaje>>& queue) {
    std::unique_lock<std::mutex> lock(m);
    vector_de_server_msg.erase(
            std::remove(vector_de_server_msg.begin(), vector_de_server_msg.end(), &queue),
            vector_de_server_msg.end());
}

ServerMonitor::~ServerMonitor() {}
