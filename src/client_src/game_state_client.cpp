#include "../../include/client_src/game_state_client.h"

#include <iostream>
#include <memory>

#include "../../common_src/msgToSent.h"

GameStateClient::GameStateClient(std::shared_ptr<ClaseTexturas> texturas,std::vector<PlatformGui>& vec_plataforma,bool jugando):
    texturas(texturas),
    vec_plataforma(vec_plataforma),
    jugando(jugando) {}

bool GameStateClient::obtener_estado_de_la_partida() { return jugando; }

std::map<uint16_t, PersonajeGui>& GameStateClient::obtener_diccionario_de_personajes() {
    return diccionario_de_personajes;
}

std::map<uint16_t, EnemigosGui>& GameStateClient::obtener_diccionario_de_enemigos() {
    return diccionario_de_enemigos;
}

std::vector<PlatformGui> & GameStateClient::obtener_vector_plataforma() {
    return vec_plataforma;
}

PersonajeGui& GameStateClient::obtener_personaje(uint16_t client_id) {
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
            personaje = std::make_shared<JazzGui>(*texturas, msgpers);
            break;
        case static_cast<uint8_t>(personajes::SPAZZ):
            personaje = std::make_shared<SpazGui>(*texturas, msgpers);
            break;
        case static_cast<uint8_t>(personajes::LORI):
            personaje = std::make_shared<LoriGui>(*texturas, msgpers);
            break;
        default:
            std::cerr << "Error: Tipo de personaje no válido" << std::endl;
            return;
    }
    auto it=diccionario_de_personajes.find(ntohs(msgpers.personaje[POS_ID_PERSONAJE]));
    if(it== diccionario_de_personajes.end()) { 
        diccionario_de_personajes.erase(it); 
    }
    diccionario_de_personajes.emplace(ntohs(msgpers.personaje[POS_ID_PERSONAJE]), *personaje);
}

GameStateClient::~GameStateClient() {}

