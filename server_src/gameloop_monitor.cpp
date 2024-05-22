#include "gameloop_monitor.h"

GameloopMonitor::GameloopMonitor(): gameloop_id(ID_INICIAL) {}

uint16_t GameloopMonitor::agregar_gameloop() {
    try {
        std::unique_lock<std::mutex> lock(m);
        uint16_t nuevo_gameloop_id = gameloop_id;
        gameloop_id++;
        GameLoop* nuevo_gameloop = new GameLoop(nuevo_gameloop_id);
        nuevo_gameloop->start();
        diccionario_de_gameloops.insert(std::make_pair(nuevo_gameloop_id, nuevo_gameloop));
        return nuevo_gameloop_id;
    } catch (const std::exception& e) {
        std::cerr << "Error al agregar gameloop: " << e.what() << std::endl;
        throw;
    }
}

GameLoop* GameloopMonitor::obtener_gameloop(uint16_t gameloop_id) {
    std::unique_lock<std::mutex> lock(m);
    auto it = diccionario_de_gameloops.find(gameloop_id);
    if (it == diccionario_de_gameloops.end()) {
        throw std::out_of_range("No se encontró el GameLoop ID");
    }
    return it->second;
}

Queue<std::shared_ptr<Comando>>& GameloopMonitor::obtener_queue_de_client_commands(
        uint16_t gameloop_id) {
    return obtener_gameloop(gameloop_id)->obtener_queue_de_client_commands();
}

GameloopMonitor::~GameloopMonitor() {
    std::unique_lock<std::mutex> lock(m);
    // cppcheck-suppress unusedVariable
    for (auto& [id, gameloop]: diccionario_de_gameloops) {
        gameloop->stop();
        gameloop->join();
        delete gameloop;
    }
}
