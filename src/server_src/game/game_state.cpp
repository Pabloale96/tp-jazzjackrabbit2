#include "../../include/server_src/game/game_state.h"

#include <iostream>
#include <memory>

#include "../../common_src/msgToSent.h"

GameState::GameState(uint16_t partida_id, bool jugando):
        partida_id(partida_id),
        jugando(jugando),
        diccionario_de_personajes(),
        diccionario_de_enemigos(),
        diccionario_de_collectibles() {}

bool GameState::obtener_estado_de_la_partida() { return jugando; }

std::map<uint16_t, std::shared_ptr<Personaje>>& GameState::obtener_diccionario_de_personajes() {
    return diccionario_de_personajes;
}

std::map<uint16_t, std::shared_ptr<Enemigo>>& GameState::obtener_diccionario_de_enemigos() {
    return diccionario_de_enemigos;
}

std::map<uint16_t, std::shared_ptr<Collectible>>& GameState::obtener_diccionario_de_collectibles() {
    return diccionario_de_collectibles;
}

std::shared_ptr<Personaje>& GameState::obtener_personaje(uint16_t client_id) {
    auto it = diccionario_de_personajes.find(client_id);
    if (it != diccionario_de_personajes.end()) {
        return std::ref(it->second);
    }
    throw std::out_of_range("No se encontró el personaje en gamestate");
}

void GameState::pushPersonajes(msgPersonaje& msgpers) {
    std::shared_ptr<Personaje> personaje;
    uint8_t tipo = msgpers.tipo_personaje;
    switch (tipo) {
        case static_cast<uint8_t>(personajes::JAZZ):
            personaje = std::make_unique<Jazz>(msgpers);
            break;
        case static_cast<uint8_t>(personajes::SPAZZ):
            personaje = std::make_unique<Spazz>(msgpers);
            break;
        case static_cast<uint8_t>(personajes::LORI):
            personaje = std::make_unique<Lori>(msgpers);
            break;
        default:
            std::cerr << "Error: Tipo de personaje no válido" << std::endl;
            return;
    }

    diccionario_de_personajes.emplace(personaje->obtener_personaje_id(), std::move(personaje));
}

void GameState::imprimir_cliente() {
    for (const auto& pair: diccionario_de_personajes) {
        const std::shared_ptr<Personaje>& personaje = pair.second;
        std::cout << " >> Personaje " << personaje->obtener_personaje_id() << " :" << std::endl;
        std::cout << "     - Posición: (" << personaje->obtener_posicion().get_posicion_x() << ", "
                  << personaje->obtener_posicion().get_posicion_y() << ")." << std::endl;
        std::cout << "     - Estado: " << (unsigned)personaje->obtener_estado_actual() << std::endl;
    }
}

void GameState::imprimir_mensaje() {
    std::cout << " PARTIDA " << partida_id << " :" << std::endl;
    for (const auto& pair: diccionario_de_personajes) {
        const std::shared_ptr<Personaje>& personaje = pair.second;
        std::cout << " >> Personaje " << personaje->obtener_personaje_id() << " :" << std::endl;
        std::cout << "     - Tipo: " << (unsigned)personaje->obtener_tipo_personaje() << std::endl;
        std::cout << "     - Posición: (" << personaje->obtener_posicion().get_posicion_x() << ", "
                  << personaje->obtener_posicion().get_posicion_y() << ")." << std::endl;
        std::cout << "     - Estado: " << (unsigned)personaje->obtener_estado_actual() << std::endl;
        std::cout << "     - Velocidad: (" << personaje->obtener_velocidad().obtener_velocidad_x()
                  << ", " << personaje->obtener_velocidad().obtener_velocidad_y() << ")."
                  << std::endl;

        std::cout << "     - Puntos: " << personaje->obtener_puntos() << std::endl;
        std::cout << "     - Vida: " << personaje->obtener_vida() << std::endl;
        std::cout << "     - Municion: " << personaje->obtener_municion() << std::endl;
        std::cout << "     - Arma: " << (unsigned)personaje->obtener_nombre_arma() << std::endl;
        std::cout << "     - Balas disparadas: " << personaje->obtener_balas().size() << std::endl;

        for (const auto& municion: personaje->obtener_balas()) {
            std::cout << "         - Bala: " << (unsigned)municion.obtener_id() << std::endl;
            std::cout << "             - Posición: ("
                      << municion.obtener_posicion().get_posicion_x() << ", "
                      << municion.obtener_posicion().get_posicion_y() << ")." << std::endl;
            std::cout << "             - Velocidad: ("
                      << municion.obtener_velocidad().obtener_velocidad_x() << ", "
                      << municion.obtener_velocidad().obtener_velocidad_y() << ")." << std::endl;
            std::cout << "             - Tipo de bala: " << (unsigned)municion.obtener_tipo_bala()
                      << std::endl;
        }

        std::cout << "     - Tiempo restante de partida: "
                  << personaje->obtener_tiempo_restante_de_partida().count() << std::endl;
    }
    /*
    for (const auto& pair: diccionario_de_enemigos) {
        const std::shared_ptr<Enemigo>& enemigo = pair.second;
        std::cout << " >> Enemigo " << enemigo->get_id_enemigo() << " :" << std::endl;
        std::cout << "     - Posición: (" << enemigo->get_posicion_enemigo().get_posicion_x() << ","
                  << enemigo->get_posicion_enemigo().get_posicion_y() << ")." << std::endl;
        std::cout << "     - Puntos: " << enemigo->get_puntos() << std::endl;
        std::cout << "     - Vida: " << enemigo->get_vidas() << std::endl;
    }

    for (const auto& pair: diccionario_de_collectibles) {
        const std::shared_ptr<Collectible>& collectible = pair.second;
        std::cout << " >> Collectible " << collectible->obtener_id() << " :" << std::endl;
        std::cout << "     - Posición: (" << collectible->obtener_posicion().get_posicion_x()
                  << ", " << collectible->obtener_posicion().get_posicion_y() << ")." << std::endl;
        std::cout << "     - Tipo: " << (unsigned)collectible->obtener_tipo_coleccionable()
                  << std::endl;
    }
    */
}


GameState::~GameState() {}
