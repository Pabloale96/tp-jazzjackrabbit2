#ifndef _SERVER_GAME_H_
#define _SERVER_GAME_H_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "../server_src/personaje.h"
#include "../server_src/server_enemigo.h"

#define NUMERO_INICIAL_ENEMIGOS 5

class Game {
private:
    Personaje personaje;
    std::vector<Enemigo> enemigos;

public:
    Game();

    Personaje obtener_personaje();

    bool mover(const std::string direccion);

    bool matar_enemigo();

    bool aumentar_iteraciones();

    uint16_t obtener_cant_vivos();

    uint16_t obtener_cant_muertos();

    ~Game();
};

#endif
