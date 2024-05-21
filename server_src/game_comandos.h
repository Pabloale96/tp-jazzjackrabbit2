#ifndef _GAME_COMANDOS_H_
#define _GAME_COMANDOS_H_

#include "../server_src/game_class.h"

class Comando {
public:
    virtual bool ejecutar(Game& game) = 0;
    virtual ~Comando() {}
};

class Atacar: public Comando {
public:
    bool ejecutar(Game& game) override;
};

class MoverDerecha: public Comando {
public:
    bool ejecutar(Game& game) override;
};

class MoverIzquierda: public Comando {
public:
    bool ejecutar(Game& game) override;
};

class MoverArriba: public Comando {
public:
    bool ejecutar(Game& game) override;
};

class MoverAbajo: public Comando {
public:
    bool ejecutar(Game& game) override;
};

#endif
