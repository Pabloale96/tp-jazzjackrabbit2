#ifndef _GAME_COMANDOS_H_
#define _GAME_COMANDOS_H_

#include "game_class.h"

class Comando {
public:
    uint16_t client_id;
    bool toggle;
    virtual void ejecutar(Game& game) = 0;
    virtual ~Comando() {}

    Comando();
    void set_client_id(uint16_t client_id);
    void set_toggle(bool toggle);
};

class Disparar: public Comando {
public:
    // TODO: Necesito la dirección en la q esta mirando
    void ejecutar(Game& game) override;
};

class MoverDerecha: public Comando {
public:
    void ejecutar(Game& game) override;
};

class MoverDerechaRapido: public Comando {
public:
    void ejecutar(Game& game) override;
};

class MoverIzquierda: public Comando {
public:
    void ejecutar(Game& game) override;
};

class MoverIzquierdaRapido: public Comando {
public:
    void ejecutar(Game& game) override;
};

class MoverArriba: public Comando {
public:
    void ejecutar(Game& game) override;
};

class MoverAbajo: public Comando {
public:
    void ejecutar(Game& game) override;
};

class Saltar: public Comando {
public:
    void ejecutar(Game& game) override;
};

#endif
