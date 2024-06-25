#include "../../include/server_src/game/gameloop_monitor.h"

#define ID_CLIENTE_INICIAL 10

GameloopMonitor::GameloopMonitor():
        gameloop_id(ID_GAMELOOP_INICIAL), id_cliente(ID_CLIENTE_INICIAL) {}

uint16_t GameloopMonitor::crear_nuevo_id_cliente() {
    std::unique_lock<std::mutex> lock(m);
    uint16_t nuevo_id_cliente = id_cliente;
    id_cliente++;
    return nuevo_id_cliente;
}

uint16_t GameloopMonitor::crear_gameloop(std::string nombre_partida, uint16_t client_id,
                                         uint8_t personaje) {
    try {
        std::unique_lock<std::mutex> lock(m);
        uint16_t nuevo_gameloop_id = gameloop_id;
        gameloop_id++;
        // TODO: Podría usar smart_pointers()
        GameLoop* nuevo_gameloop =
                new GameLoop(nuevo_gameloop_id, nombre_partida, client_id, personaje);
        nuevo_gameloop->start();
        std::cout << "Partida " << nuevo_gameloop_id << " creada" << std::endl;
        diccionario_de_gameloops.insert(std::make_pair(nuevo_gameloop_id, nuevo_gameloop));
        return nuevo_gameloop_id;
    } catch (const std::exception& e) {
        std::cerr << "Error al agregar gameloop: " << e.what() << std::endl;
        throw;
    }
}

std::map<uint16_t, std::string> GameloopMonitor::obtener_partidas_disponibles() {
    std::unique_lock<std::mutex> lock(m);
    std::map<uint16_t, std::string> partidas_disponibles;
    for (const auto& pair: diccionario_de_gameloops) {
        uint16_t id = pair.first;
        GameLoop* gameLoop = pair.second;
        if (gameLoop) {
            partidas_disponibles[id] = gameLoop->obtener_nombre_partida();
        }
    }
    return partidas_disponibles;
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

void GameloopMonitor::agregar_cliente_al_gameloop(uint16_t gameloop_id, uint16_t client_id,
                                                  uint8_t personaje) {
    GameLoop* gameloop = obtener_gameloop(gameloop_id);
    gameloop->agregar_cliente(client_id, personaje);
}

void GameloopMonitor::agregar_queue_server_msg_de_cliente_aceptado(
        uint16_t gameloop_id, Queue<std::shared_ptr<GameState>>& server_msg) {
    GameLoop* gameloop = obtener_gameloop(gameloop_id);
    gameloop->agregar_queue_server_msg_de_cliente_aceptado(server_msg);
    return;
}

void GameloopMonitor::borrar_cliente_de_gameloop(uint16_t gameloop_id, uint16_t client_id) {
    // Este lock no hace falta porque obtener_gameloop ya tiene un lock (por lo que terminariamos en
    // deadlock) std::unique_lock<std::mutex> lock(m);
    GameLoop* gameloop = obtener_gameloop(gameloop_id);
    //gameloop->borrar_queue_server_msg_de_cliente_aceptado(queue_server_msg);
    gameloop->borrar_cliente(client_id);

    // std::unique_lock<std::mutex> lock(m);
    // borrar_partida_si_esta_vacia(gameloop);
}

void GameloopMonitor::borrar_partida_si_esta_vacia(GameLoop* gameloop) {
    if (gameloop->cantidad_de_clientes() == 0) {
        std::cout << "Partida " << gameloop->obtener_gameloop_id()
                  << " será borrada por no haber jugadores" << std::endl;
        diccionario_de_gameloops.erase(
                diccionario_de_gameloops.find(gameloop->obtener_gameloop_id()));
        gameloop->stop();
        gameloop->join();
        delete gameloop;
    }
}

GameloopMonitor::~GameloopMonitor() {
    std::unique_lock<std::mutex> lock(m);
    // cppcheck-suppress unassignedVariable
    for (auto& [id, gameloop]: diccionario_de_gameloops) {
        std::cout << "Borrando Partida " << id << std::endl;
        gameloop->stop();
        gameloop->join();
        delete gameloop;
    }
}
