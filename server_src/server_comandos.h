#ifndef SERVER_COMANDOS_H
#define SERVER_COMANDOS_H

#include "../server_src/server_juego.h"

class Comando {
public:
    virtual void ejecutar(Juego& juego) = 0;
    virtual ~Comando() {}
};

class ComandoAtacar: public Comando {
public:
    void ejecutar(Juego& juego) override { juego.atacar(); }
};

#endif
