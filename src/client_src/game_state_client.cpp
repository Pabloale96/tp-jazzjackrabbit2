#include "../../include/client_src/game_state_client.h"

#include <iostream>
#include <memory>

#include "../../common_src/msgToSent.h"

GameStateClient::GameStateClient(uint16_t partida_id, bool jugando):
        partida_id(partida_id), jugando(jugando), diccionario_de_personajes() {}

bool GameStateClient::obtener_estado_de_la_partida() { return jugando; }

std::map<uint16_t, std::shared_ptr<PersonajeGui>>&
        GameStateClient::obtener_diccionario_de_personajes() {
    return diccionario_de_personajes;
}

std::map<uint16_t, EnemigosGui>& GameStateClient::obtener_diccionario_de_enemigos() {
    return diccionario_de_enemigos;
}

std::shared_ptr<PersonajeGui>& GameStateClient::obtener_personaje(uint16_t client_id) {
    auto it = diccionario_de_personajes.find(client_id);
    if (it != diccionario_de_personajes.end()) {
        return std::ref(it->second);
    }
    throw std::out_of_range("No se encontró el personaje en gamestate");
}

void GameStateClient::pushPersonajes(msgPersonaje& msgpers) {
    std::shared_ptr<PersonajeGui> personaje;
    uint8_t tipo = msgpers.tipo_personaje;
    switch (tipo) {
        case static_cast<uint8_t>(personajes::JAZZ):
            personaje = std::make_unique<JazzGui>(msgpers);
            break;
        case static_cast<uint8_t>(personajes::SPAZZ):
            personaje = std::make_unique<SpazGui>(msgpers);
            break;
        case static_cast<uint8_t>(personajes::LORI):
            personaje = std::make_unique<LoriGui>(msgpers);
            break;
        default:
            std::cerr << "Error: Tipo de personaje no válido" << std::endl;
            return;
    }

    diccionario_de_personajes.emplace(msgpers.personaje[POS_ID_PERSONAJE], std::move(personaje));
}

GameStateClient::~GameStateClient() {}
