#include "../../include/server_src/game/game_enemigo.h"

#include <iostream>
#define ITERACIONES_PARA_REVIVIR 15
#define TIME_REVIVE_INICIAL 50

Enemigo::Enemigo():
        iteraciones(0)
// cppcheck-suppress readability/multiline_comment
/*
time_revive(TIME_REVIVE_INICIAL),
prob_municion(0.0f),
prob_vida(0.0f)
*/
{}

void Enemigo::set_enemigo_id(uint16_t id_enemigo) { this->id_enemigo = id_enemigo; }
void Enemigo::set_tipo_enemigo(TipoEnemigo tipo_enemigo) { this->tipo_enemigo = tipo_enemigo; }
void Enemigo::set_posicion_enemigo(uint16_t x, uint16_t y) { posicion_enemigo.set_posicion(x, y); }
void Enemigo::set_vidas(uint16_t vidas) { this->vidas = vidas; }
void Enemigo::set_danio_al_jugador(uint16_t danio_al_jugador) {
    this->danio_al_jugador = danio_al_jugador;
}
void Enemigo::set_puntos(uint16_t puntos) { this->puntos = puntos; }


uint16_t Enemigo::get_id_enemigo() const { return id_enemigo; }
TipoEnemigo Enemigo::get_tipo_enemigo() const { return tipo_enemigo; }
Posicion Enemigo::get_posicion_enemigo() const { return posicion_enemigo; }
uint16_t Enemigo::get_vidas() const { return vidas; }
uint16_t Enemigo::get_danio_al_jugador() const { return danio_al_jugador; }
uint16_t Enemigo::get_puntos() const { return puntos; }


void Enemigo::recibir_disparo() {
    if (esta_vivo()) {
        vidas--;
    }
}

void Enemigo::aumentar_iteraciones() {
    if (iteraciones < ITERACIONES_PARA_REVIVIR) {
        iteraciones++;
    }

    if (iteraciones == ITERACIONES_PARA_REVIVIR) {
        revivir_enemigo();
        iteraciones = 0;
    }
}

void Enemigo::revivir_enemigo() {}

bool Enemigo::esta_vivo() {
    if (vidas > 0) {
        return true;
    }
    return false;
}


// ************  ENEMIGO 1 ("nombre")  ************
#define POS_x_INICIAL_ENEMIGO_1 5
#define POS_y_INICIAL_ENEMIGO_1 0
#define VIDAS_ENEMIGO_1 1
#define DANIO_ENEMIGO_1 1
#define PUNTOS_ENEMIGO_1 1

// Enemigo1 constructor
Enemigo1::Enemigo1() {
    set_tipo_enemigo(TipoEnemigo::ENEMIGO1);
    set_posicion_enemigo(POS_x_INICIAL_ENEMIGO_1, POS_y_INICIAL_ENEMIGO_1);
    set_vidas(VIDAS_ENEMIGO_1);
    set_danio_al_jugador(DANIO_ENEMIGO_1);
    set_puntos(PUNTOS_ENEMIGO_1);
}

void Enemigo1::revivir_enemigo() {
    if (!esta_vivo()) {
        set_vidas(VIDAS_ENEMIGO_1);
    }
}

// ************  ENEMIGO 2 ("nombre")  ************
#define POS_x_INICIAL_ENEMIGO_2 15
#define POS_y_INICIAL_ENEMIGO_2 0
#define VIDAS_ENEMIGO_2 2
#define DANIO_ENEMIGO_2 2
#define PUNTOS_ENEMIGO_2 2

// Enemigo2 constructor
Enemigo2::Enemigo2() {
    set_tipo_enemigo(TipoEnemigo::ENEMIGO2);
    set_posicion_enemigo(POS_x_INICIAL_ENEMIGO_2, POS_y_INICIAL_ENEMIGO_2);
    set_vidas(VIDAS_ENEMIGO_2);
    set_danio_al_jugador(DANIO_ENEMIGO_2);
    set_puntos(PUNTOS_ENEMIGO_2);
}

void Enemigo2::revivir_enemigo() {
    if (!esta_vivo()) {
        set_vidas(VIDAS_ENEMIGO_2);
    }
}

// ************  ENEMIGO 3 ("nombre")  ************
#define POS_x_INICIAL_ENEMIGO_3 30
#define POS_y_INICIAL_ENEMIGO_3 5  // volador
#define VIDAS_ENEMIGO_3 3
#define DANIO_ENEMIGO_3 3
#define PUNTOS_ENEMIGO_3 3

// Enemigo3 constructor
Enemigo3::Enemigo3() {
    set_tipo_enemigo(TipoEnemigo::ENEMIGO3);
    set_posicion_enemigo(POS_x_INICIAL_ENEMIGO_3, POS_y_INICIAL_ENEMIGO_3);
    set_vidas(VIDAS_ENEMIGO_3);
    set_danio_al_jugador(DANIO_ENEMIGO_3);
    set_puntos(PUNTOS_ENEMIGO_3);
}

void Enemigo3::revivir_enemigo() {
    if (!esta_vivo()) {
        set_vidas(VIDAS_ENEMIGO_3);
    }
}