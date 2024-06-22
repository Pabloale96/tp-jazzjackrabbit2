#include "../../include/client_src/game_state_client.h"

#include <iostream>
#include <memory>

#include "../../common_src/msgToSent.h"

GameStateClient::GameStateClient(bool jugando): jugando(jugando) {}

GameStateClient::GameStateClient(): jugando(true), diccionario_de_personajes(), diccionario_de_enemigos() {}


bool GameStateClient::obtener_estado_de_la_partida() { return jugando; }

std::map<uint16_t, PersonajeGui> GameStateClient::obtener_diccionario_de_personajes() const{
    return diccionario_de_personajes;
}

std::map<uint16_t, EnemigosGui> GameStateClient::obtener_diccionario_de_enemigos() const{
    return diccionario_de_enemigos;
}

PersonajeGui& GameStateClient::obtener_personaje(uint16_t client_id) {
    auto it = diccionario_de_personajes.find(client_id);
    if (it != diccionario_de_personajes.end()) {
        return std::ref(it->second);
    }
    throw std::out_of_range("No se encontró el personaje en gamestate");
}

void GameStateClient::pushPersonajes(ClaseTexturas& texturas, msgPersonaje& msgpers) {
    std::shared_ptr<PersonajeGui> personaje;
    uint8_t tipo = msgpers.tipo_personaje;
    switch (tipo) {
        case static_cast<uint8_t>(personajes::JAZZ):
            personaje = std::make_shared<JazzGui>(texturas, msgpers);
            break;
        case static_cast<uint8_t>(personajes::SPAZZ):
            personaje = std::make_shared<SpazGui>(texturas, msgpers);
            break;
        case static_cast<uint8_t>(personajes::LORI):
            personaje = std::make_shared<LoriGui>(texturas, msgpers);
            break;
        default:
            std::cerr << "Error: Tipo de personaje no válido" << std::endl;
            return;
    }
    diccionario_de_personajes.emplace(ntohs(msgpers.personaje[POS_ID_PERSONAJE]), std::move(*personaje));
    
}

void GameStateClient::actualizar_gamestate( const GameStateClient & other) {

        for (const auto& [id, personaje]: other.obtener_diccionario_de_personajes()) {    
            if (!this->diccionario_de_personajes.empty())  {
                auto it = this->diccionario_de_personajes.find(id);
                if (it != diccionario_de_personajes.end()) {
                    it->second.actualizar_personaje(personaje);
                } else {
                    diccionario_de_personajes.emplace(id, std::move(personaje));
                }
            } else {
                this->diccionario_de_personajes = other.obtener_diccionario_de_personajes();
            }
        }
        /*for (auto& [id, enemigo]: other.obtener_diccionario_de_enemigos()) {        
            auto it = this->obtener_diccionario_de_enemigos.find(id);
            if (it != diccionario_de_enemigos.end()) {
                it->second.actualizar_enemigo(enemigo);
            } else {
                diccionario_de_enemigos.emplace(ntohs(id, std::move(enemigo));
            }
        }*/
}

GameStateClient::~GameStateClient() {}
