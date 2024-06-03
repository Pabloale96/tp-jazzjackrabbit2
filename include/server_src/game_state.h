#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <cstdint>
#include <iostream>
#include <map>
#include <string>

#include "game_enemigo.h"
#include "game_personaje.h"


class GameState {
private:
    uint16_t partida_id;
    bool jugando;
    std::map<uint16_t, Personaje> diccionario_de_personajes;
    std::map<uint16_t, Enemigo> diccionario_de_enemigos;

public:
    explicit GameState(uint16_t partida_id, bool jugando);

    bool obtener_estado_de_la_partida();

    std::map<uint16_t, Personaje>& obtener_diccionario_de_personajes();

    std::map<uint16_t, Enemigo>& obtener_diccionario_de_enemigos();

    Personaje obtener_personaje(uint16_t client_id);

    bool getJugando() { return jugando; }

    int getSizePersonajes() { return diccionario_de_personajes.size(); }

    void setGameState(const uint8_t& state_partida) { jugando = (state_partida == 0x01); }
    void pushPersonajes(uint16_t* msgpers) {
        Personaje personaje(msgpers);
        diccionario_de_personajes.emplace(personaje.obtener_personaje_id(), personaje);
    }

    void imprimir_mensaje();

    ~GameState();
};

#endif
