#include "../server_src/game_state.h"

GameState::GameState(const Personaje& personaje): personaje(personaje) {}

Personaje GameState::obtener_personaje() { return personaje; }

void GameState::imprimir_mensaje() {
    std::string msg = "El personaje esta en la posicion: (" +
                      std::to_string(personaje.obtener_posicion().get_posicion_x()) + ", " +
                      std::to_string(personaje.obtener_posicion().get_posicion_y()) + ")";
    std::cout << msg << std::endl;
}

GameState::~GameState() {}
