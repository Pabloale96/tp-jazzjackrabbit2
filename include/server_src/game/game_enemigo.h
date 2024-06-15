#ifndef _GAME_ENEMIGO_H_
#define _GAME_ENEMIGO_H_

#include <cstdint>

#include "game_posicion.h"
#include "protocol_utils.h"


class Enemigo {

private:
    uint16_t id_enemigo;
    TipoEnemigo tipo_enemigo;
    Posicion posicion_enemigo;
    Velocidad velocidad_enemigo;

    unsigned int iteraciones;

    uint16_t vidas;
    uint16_t danio_al_jugador;
    uint16_t puntos;
    // int time_revive;
    // float prob_municion;
    // float prob_vida;

public:
    // Constructor
    // Inicializa vivo en true y las iteraciones en 0
    explicit Enemigo(uint16_t id_enemigo);

    // Constructor para el cliente
    explicit Enemigo(uint16_t* datos_enemigo);

    void set_enemigo_id(uint16_t id_enemigo);
    void set_tipo_enemigo(TipoEnemigo tipo_enemigo);
    void set_posicion_enemigo(uint16_t x, uint16_t y);
    void set_vidas(uint16_t vidas);
    void set_danio_al_jugador(uint16_t danio_al_jugador);
    void set_puntos(uint16_t puntos);

    uint16_t get_id_enemigo() const;
    TipoEnemigo get_tipo_enemigo() const;
    Posicion get_posicion_enemigo() const;
    uint16_t get_vidas() const;
    uint16_t get_danio_al_jugador() const;
    uint16_t get_puntos() const;

    void actualizar();

    // reduce vida al enemigo
    void recibir_disparo(uint8_t danio);

    // Aumenta las iteraciones del enemigo. Si llega a 15 llama a revivir_enemigo
    void aumentar_iteraciones();

    void matar();

    // Revive al enemigo
    virtual void revivir_enemigo();

    // Devuelve true si el enemigo esta vivo
    bool esta_vivo();

    // Destructor
    virtual ~Enemigo() = default;
};


// ************  ENEMIGO 1 ("nombre")  ************
class Enemigo1: public Enemigo {
public:
    explicit Enemigo1(uint16_t id);

    // Revive al enemigo
    void revivir_enemigo() override;
};


// ************  ENEMIGO 2 ("nombre")  ************
class Enemigo2: public Enemigo {
public:
    explicit Enemigo2(uint16_t id);

    // Revive al enemigo
    void revivir_enemigo() override;
};


// ************  ENEMIGO 3 ("nombre")  ************
class Enemigo3: public Enemigo {
public:
    explicit Enemigo3(uint16_t id);

    // Revive al enemigo
    void revivir_enemigo() override;
};

#endif
