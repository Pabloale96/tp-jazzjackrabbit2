#include "../../include/game_state.h"

#include <iostream>
#include <memory>

#include "../../include/game_enemigo.h"
#include "../../include/game_personaje.h"

GameState::GameState(uint16_t partida_id, bool jugando):
    partida_id(partida_id), jugando(jugando), diccionario_de_personajes() {}

bool GameState::obtener_estado_de_la_partida() {
    return jugando;
}

std::map<uint16_t, Personaje>& GameState::obtener_diccionario_de_personajes() {
    return diccionario_de_personajes;
}

std::map<uint16_t, Enemigo>& GameState::obtener_diccionario_de_enemigos() {
    return diccionario_de_enemigos;
}

Personaje GameState::obtener_personaje(uint16_t client_id) {
    auto it = diccionario_de_personajes.find(client_id);
    if (it != diccionario_de_personajes.end()) {
        return it->second;
    }
    throw std::out_of_range("No se encontró el personaje en gamestate");
}

void GameState::imprimir_mensaje() {
    std::cout << " PARTIDA " << partida_id << " :" << std::endl;
    for (const auto& pair: diccionario_de_personajes) {
        const Personaje& personaje = pair.second;
        std::cout << " >> Personaje " << personaje.obtener_personaje_id() << " :" << std::endl;
        std::cout << "     - Posición: (" << personaje.obtener_posicion().get_posicion_x() << ", "
                  << personaje.obtener_posicion().get_posicion_y() << ")." << std::endl;
        std::cout << "     - Puntos: " << personaje.obtener_puntos() << std::endl;
        std::cout << "     - Vida: " << personaje.obtener_vida() << std::endl;
        std::cout << "     - Municion: " << personaje.obtener_municion() << std::endl;
        std::cout << "     - Arma: " << personaje.obtener_nombre_arma() << std::endl;
    }

    for (const auto& pair: diccionario_de_enemigos) {
        const Enemigo& enemigo = pair.second;
        std::cout << " >> Enemigo " << enemigo.get_id_enemigo() << " :" << std::endl;
        std::cout << "     - Posición: (" << enemigo.get_posicion_enemigo().get_posicion_x() << ", "
                  << enemigo.get_posicion_enemigo().get_posicion_y() << ")." << std::endl;
        std::cout << "     - Puntos: " << enemigo.get_puntos() << std::endl;
        std::cout << "     - Vida: " << enemigo.get_vidas() << std::endl;
    }
}


GameState::~GameState() {}
