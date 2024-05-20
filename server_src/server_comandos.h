#ifndef SERVER_COMANDOS_H
#define SERVER_COMANDOS_H

#include "../server_src/server_game.h"

class Comando {
public:
    virtual bool ejecutar(Game& game) = 0;
    virtual ~Comando() {}
};

class Atacar: public Comando {
public:
    bool ejecutar(Game& game) override;
};

#endif
