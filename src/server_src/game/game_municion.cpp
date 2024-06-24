#include "game_municion.h"

#include <cstdint>

Municion::Municion(float x, float y, float velocidad_x, uint8_t tipo_bala, uint16_t id):
        // Se asume que las balas salen en linea recta (es decir, y=0)
        posicion(x, y),
        velocidad(velocidad_x, 0.0f),
        tipo_bala(tipo_bala),
        id(id) {}

uint8_t Municion::obtener_tipo_bala() const { return tipo_bala; }

uint16_t Municion::obtener_x() const { return posicion.get_posicion_x(); }

uint16_t Municion::obtener_y() const { return posicion.get_posicion_y(); }

Velocidad Municion::obtener_velocidad() const { return velocidad; }

void Municion::mover() { posicion.mover(velocidad); }

Posicion Municion::obtener_posicion() const { return posicion; }

uint16_t Municion::obtener_id() const { return id; }

bool Municion::choco_con_pared(std::vector<Plataforma>& plataformas) {
    bool colisiono = false;
    for (auto& plataforma: plataformas) {
        colisiono = plataforma.estoy_adentro_de_la_plataforma(posicion.get_posicion_x(),
                                                              posicion.get_posicion_y());
    }
    return colisiono;
}
