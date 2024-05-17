#ifndef _SERVER_GAME_H_
#define _SERVER_GAME_H_

#include <vector>
#include <cstdint>
#include <memory>

// #include "../server_src/personaje.h"
#include "../server_src/server_enemigo.h"

#define NUMERO_INICIAL_ENEMIGOS 5

class Game {
private:
    //Personaje personaje;
    std::vector<Enemigo> enemigos;
    
public:
    Game();

    bool ejecutar_accion(std::shared_ptr<std::string> accion);

    bool matar_enemigo();

    bool aumentar_iteraciones();

    uint16_t obtener_cant_vivos();

    uint16_t obtener_cant_muertos();

    ~Game();
};

#endif
