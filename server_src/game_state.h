#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <cstdint>
#include <iostream>
#include <map>
#include <string>

#include "../server_src/game_enemigo.h"
#include "../server_src/game_personaje.h"

class GameState {
private:
    uint16_t partida_id;
    std::map<uint16_t, Personaje> diccionario_de_personajes;
    std::map<uint16_t, Enemigo> diccionario_de_enemigos;

public:
    explicit GameState(uint16_t partida_id);

    std::map<uint16_t, Personaje>& obtener_diccionario_de_personajes();

    std::map<uint16_t, Enemigo>& obtener_diccionario_de_enemigos();

    Personaje obtener_personaje(uint16_t client_id);

    void imprimir_mensaje();

    ~GameState();
};

#endif
