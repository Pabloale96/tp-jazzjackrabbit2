#include "gameloop_monitor.h"

GameloopMonitor::GameloopMonitor() : gameloop_id(ID_INICIAL) {}

uint16_t GameloopMonitor::agregar_gameloop() {
    std::unique_lock<std::mutex> lock(m);
    uint16_t nuevo_gameloop_id = gameloop_id;
    gameloop_id++;
    GameLoop nuevo_gameloop;
    std::cout << "GameLoop antes de start" << std::endl;
    nuevo_gameloop.start();
    std::cout << "GameLoop después de start" << std::endl;
    // diccionario_de_gameloops.insert(std::make_pair(nuevo_gameloop_id, std::move(nuevo_gameloop)));
    diccionario_de_gameloops.emplace(nuevo_gameloop_id, std::move(nuevo_gameloop));
    std::cout << "GameLoop post emplace" << std::endl;
    return nuevo_gameloop_id;
}

GameLoop& GameloopMonitor::obtener_gameloop(uint16_t gameloop_id) {
    std::unique_lock<std::mutex> lock(m);
    auto it = diccionario_de_gameloops.find(gameloop_id);
    if (it == diccionario_de_gameloops.end()) {
        throw std::out_of_range("No se encontró el GameLoop ID");
    }
    return it->second;
}

Queue<std::shared_ptr<Comando>>& GameloopMonitor::obtener_queue_de_client_commands(uint16_t gameloop_id) {
    return obtener_gameloop(gameloop_id).obtener_queue_de_client_commands();
}

GameloopMonitor::~GameloopMonitor() {
    std::unique_lock<std::mutex> lock(m);
    for (auto& [id, gameloop] : diccionario_de_gameloops) {
        gameloop.stop();
        // gameloop.join();
    }
}