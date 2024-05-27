#include "../server_src/game_state.h"

#include "../server_src/game_personaje.h"

GameState::GameState(): diccionario_de_personajes() {}

std::map<uint16_t, Personaje>& GameState::obtener_diccionario_de_personajes() {
    return diccionario_de_personajes;
}

Personaje GameState::obtener_personaje(uint16_t client_id) {
    auto it = diccionario_de_personajes.find(client_id);
    if (it != diccionario_de_personajes.end()) {
        return it->second;
    }
    throw std::out_of_range("No se encontró el personaje en gamestate");
}

void GameState::imprimir_mensaje() {
    for (const auto& pair: diccionario_de_personajes) {
        const Personaje& personaje = pair.second;
        std::cout << "En la partida " << personaje.obtener_partida_id() << " el personaje "
                  << personaje.obtener_personaje_id() << " tiene:" << std::endl;
        std::cout << "  - Posición: (" << personaje.obtener_posicion().get_posicion_x() << ", "
                  << personaje.obtener_posicion().get_posicion_y() << ")." << std::endl;
        std::cout << "  - Puntos: " << personaje.obtener_puntos() << std::endl;
        std::cout << "  - Vida: " << personaje.obtener_vida() << std::endl;
        std::cout << "  - Municion: " << personaje.obtener_municion() << std::endl;
        std::cout << "  - Arma: " << personaje.obtener_nombre_arma() << std::endl;
    }
    // TODO: Deberia de hacer lo mismo con los enemigos
}

GameState::~GameState() {}
