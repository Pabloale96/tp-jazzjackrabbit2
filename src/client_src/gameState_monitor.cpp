#include "../../include/client_src/gameState_monitor.h"

#include <algorithm>

GameStateMonitorClient::GameStateMonitorClient(): gamestate(0, true) {}


std::map<uint16_t, std::shared_ptr<Personaje>>
        GameStateMonitorClient::obtener_diccionario_de_personajes() {
    std::unique_lock<std::mutex> lock(m);
    return gamestate.obtener_diccionario_de_personajes();
}

std::map<uint16_t, Enemigo> GameStateMonitorClient::obtener_diccionario_de_enemigos() {
    std::unique_lock<std::mutex> lock(m);
    return gamestate.obtener_diccionario_de_enemigos();
}

bool GameStateMonitorClient::getJugando() {
    std::unique_lock<std::mutex> lock(m);
    return gamestate.getJugando();
}

std::shared_ptr<Personaje>& GameStateMonitorClient::obtener_personaje(uint16_t client_id) {
    std::unique_lock<std::mutex> lock(m);
    return gamestate.obtener_personaje(client_id);
}

void GameStateMonitorClient::setGameState(const uint8_t& state_partida) {
    std::unique_lock<std::mutex> lock(m);
    gamestate.setGameState(state_partida);
}

void GameStateMonitorClient::pushPersonajes(msgPersonaje& msg) {
    std::unique_lock<std::mutex> lock(m);
    gamestate.pushPersonajes(msg);
}

void GameStateMonitorClient::pushEnemigos(uint16_t* msg) {
    std::unique_lock<std::mutex> lock(m);
    gamestate.pushEnemigos(msg);
}

GameStateMonitorClient::~GameStateMonitorClient() {}
