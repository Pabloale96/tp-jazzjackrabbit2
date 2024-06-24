#include "../../include/server_src/game/game_state_monitor.h"

#include <algorithm>

GameStateMonitor::GameStateMonitor(/* args */) {}

void GameStateMonitor::agregar_queue(Queue<std::shared_ptr<GameState>>& nueva_queue) {
    std::unique_lock<std::mutex> lock(m);
    vector_de_server_msg.push_back(&nueva_queue);
}

void GameStateMonitor::broadcastear(const GameState& msg) {
    std::unique_lock<std::mutex> lock(m);
    for (size_t i = 0; i < vector_de_server_msg.size(); ++i) {
        try {
            vector_de_server_msg[i]->try_push(std::make_shared<GameState>(msg));
        } catch (const ClosedQueue&) {
            vector_de_server_msg.erase(
                    std::remove(vector_de_server_msg.begin(), vector_de_server_msg.end(),
                                vector_de_server_msg[i]),
                    vector_de_server_msg.end());
            --i;
        }
    }
}

void GameStateMonitor::borrar_queue(Queue<std::shared_ptr<GameState>>& queue) {
    std::unique_lock<std::mutex> lock(m);
    vector_de_server_msg.erase(
            std::remove(vector_de_server_msg.begin(), vector_de_server_msg.end(), &queue),
            vector_de_server_msg.end());
}

GameStateMonitor::~GameStateMonitor() {}
