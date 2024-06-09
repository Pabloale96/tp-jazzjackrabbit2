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
    Comando(uint16_t client_id, bool toggle);

    void set_client_id(uint16_t client_id);
    void set_toggle(bool toggle);
};

class MoverDerecha: public Comando {
public:
    MoverDerecha(uint16_t client_id, bool toggle);
    void ejecutar(Game& game) override;
};

class MoverDerechaRapido: public Comando {
public:
    MoverDerechaRapido(uint16_t client_id, bool toggle);
    void ejecutar(Game& game) override;
};

class MoverIzquierda: public Comando {
public:
    MoverIzquierda(uint16_t client_id, bool toggle);
    void ejecutar(Game& game) override;
};

class MoverIzquierdaRapido: public Comando {
public:
    MoverIzquierdaRapido(uint16_t client_id, bool toggle);
    void ejecutar(Game& game) override;
};

class Saltar: public Comando {
public:
    Saltar(uint16_t client_id, bool toggle);
    void ejecutar(Game& game) override;
};


class Disparar: public Comando {
public:
    Disparar(uint16_t client_id, bool toggle);

    // TODO: Necesito la dirección en la q esta mirando
    void ejecutar(Game& game) override;
};

class AccionEspecial: public Comando {
public:
    AccionEspecial(uint16_t client_id, bool toggle);
    void ejecutar(Game& game) override;
};

class KillAll: public Comando {
public:
    KillAll(uint16_t client_id, bool toggle);
    void ejecutar(Game& game) override;
};

#endif
