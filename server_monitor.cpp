#include "server_monitor.h"

#include <algorithm>

ServerMonitor::ServerMonitor(/* args */) {}

void ServerMonitor::agregar_queue(Queue<ServerJuegoMensaje>* nueva_queue) {
    std::unique_lock<std::mutex> lock(m);
    vector_de_server_msg.push_back(nueva_queue);
}

void ServerMonitor::broadcastear(const ServerJuegoMensaje& msg) {
    std::unique_lock<std::mutex> lck(m);
    for (size_t i = 0; i < vector_de_server_msg.size(); ++i) {
        try {
            vector_de_server_msg[i]->try_push(msg);
        } catch (const ClosedQueue&) {
            borrar_queue(vector_de_server_msg[i]);
        }
    }
}

void ServerMonitor::borrar_queue(Queue<ServerJuegoMensaje>* queue) {
    std::unique_lock<std::mutex> lock(m);
    vector_de_server_msg.erase(
            std::remove(vector_de_server_msg.begin(), vector_de_server_msg.end(), queue),
            vector_de_server_msg.end());
}

ServerMonitor::~ServerMonitor() {}
