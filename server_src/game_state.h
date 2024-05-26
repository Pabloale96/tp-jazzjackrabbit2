#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <cstdint>
#include <iostream>
#include <map>
#include <string>

#include "../server_src/game_personaje.h"

class GameState {
private:
    std::map<uint16_t, Personaje> diccionario_de_personajes;

public:
    GameState();

    std::map<uint16_t, Personaje>& obtener_diccionario_de_personajes();

    Personaje obtener_personaje(uint16_t client_id);

    void imprimir_mensaje();

    ~GameState();
};

#endif
