#ifndef _GAME_MUNICION_H_
#define _GAME_MUNICION_H_

#include "game_posicion.h"
#include "game_platform.h"

class Municion {
private:
    Posicion posicion;
    Velocidad velocidad;
    uint8_t tipo_bala;
    uint16_t id;

public:
    Municion(float x, float y, float velocidad_x, uint8_t tipo_bala, uint16_t id);

    uint8_t obtener_tipo_bala() const;

    uint16_t obtener_x() const;

    uint16_t obtener_y() const;

    Velocidad obtener_velocidad() const;

    Posicion obtener_posicion() const;

    void mover();

    uint16_t obtener_id() const;

    bool choco_con_pared(std::vector<Plataforma>& plataformas);
};

#endif
