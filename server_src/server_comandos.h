#ifndef SERVER_COMANDOS_H
#define SERVER_COMANDOS_H

#include "../server_src/server_game_loop.h"

class Comando {
public:
    virtual void ejecutar(GameLoop& game_loop) = 0;
    virtual ~Comando() {}
};

class Atacar: public Comando {
public:
    void ejecutar(GameLoop& game_loop) override { game_loop.atacar(); }
};

#endif
