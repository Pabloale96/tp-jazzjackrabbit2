#include "../server_src/game_state.h"

#include "../server_src/game_class.h"

GameState::GameState(Game& game): game(game) {}

Personaje GameState::obtener_personaje(uint16_t client_id) {
    return game.obtener_personaje(client_id);
}

std::map<uint16_t, Personaje>& GameState::obtener_diccionario_de_personajes() {
    return diccionario_de_personajes;
}

void GameState::imprimir_mensaje() {
    std::vector<Personaje> personajes = game.obtener_vector_de_personajes();
    for (auto& personaje: personajes) {
        diccionario_de_personajes.insert(
                std::make_pair(personaje.obtener_personaje_id(), personaje));
        std::cout << "El personaje " << personaje.obtener_personaje_id()
                  << " está en la posición: (" << personaje.obtener_posicion().get_posicion_x()
                  << " ," << personaje.obtener_posicion().get_posicion_y() << " )." << std::endl;
        // std::cout << "Personaje vida: " << personaje.obtener_vida() << std::endl;
    }
    // Deberia de hacer lo mismo con los enemigos
}

GameState::~GameState() {}
