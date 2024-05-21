#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <cstdint>
#include <iostream>
#include <string>

#include "../server_src/game_personaje.h"

class GameState {
private:
    Personaje personaje;

public:
    explicit GameState(Personaje personaje);

    Personaje obtener_personaje();

    void imprimir_mensaje();

    ~GameState();
};

#endif
