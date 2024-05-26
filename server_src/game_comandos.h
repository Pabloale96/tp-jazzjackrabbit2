#ifndef _GAME_COMANDOS_H_
#define _GAME_COMANDOS_H_

#include "../server_src/game_class.h"

class Comando {
public:
    uint16_t client_id;
    virtual bool ejecutar(Game& game) = 0;
    virtual ~Comando() {}

    void set_client_id(uint16_t client_id) { this->client_id = client_id; }
};

class Disparar: public Comando {
public:
    bool ejecutar(Game& game) override;
};

class MoverDerecha: public Comando {
public:
    bool ejecutar(Game& game) override;
};

class MoverDerechaRapido: public Comando {
public:
    bool ejecutar(Game& game) override;
};

class MoverIzquierda: public Comando {
public:
    bool ejecutar(Game& game) override;
};

class MoverIzquierdaRapido: public Comando {
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

class Saltar: public Comando {
public:
    bool ejecutar(Game& game) override;
};

#endif
