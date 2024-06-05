#include "../../include/server_src/game/gameloop_monitor.h"

GameloopMonitor::GameloopMonitor(): gameloop_id(ID_GAMELOOP_INICIAL) {}

uint16_t GameloopMonitor::crear_gameloop(std::string nombre_partida, uint16_t client_id,
                                         std::string& personaje) {
    try {
        std::unique_lock<std::mutex> lock(m);
        uint16_t nuevo_gameloop_id = gameloop_id;
        gameloop_id++;
        // TODO: Probar usar smart_pointers()
        GameLoop* nuevo_gameloop =
                new GameLoop(nuevo_gameloop_id, nombre_partida, client_id, personaje);
        nuevo_gameloop->start();
        diccionario_de_gameloops.insert(std::make_pair(nuevo_gameloop_id, nuevo_gameloop));
        return nuevo_gameloop_id;
    } catch (const std::exception& e) {
        std::cerr << "Error al agregar gameloop: " << e.what() << std::endl;
        throw;
    }
}

// TODO: Mando el map en vez de pasarlo por referencia
void GameloopMonitor::obtener_partidas_disponibles(
        std::map<uint16_t, std::string>& partidas_disponibles) {
    std::unique_lock<std::mutex> lock(m);
    partidas_disponibles.clear();
    for (const auto& pair: diccionario_de_gameloops) {
        uint16_t id = pair.first;
        GameLoop* gameLoop = pair.second;
        if (gameLoop) {
            partidas_disponibles[id] = gameLoop->obtener_nombre_partida();
        }
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

void GameloopMonitor::borrar_cliente_de_gameloop(uint16_t gameloop_id, uint16_t client_id) {
    std::unique_lock<std::mutex> lock(m);
    GameLoop* gameloop = obtener_gameloop(gameloop_id);
    gameloop->borrar_cliente(client_id);
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
