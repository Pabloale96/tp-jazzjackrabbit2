#include "../server_src/game_enemigo.h"

#include <iostream>

Enemigo::Enemigo():
        tipo_enemigo(TipoEnemigo::ENEMIGO1),  // Por defecto es enemigo1
        vivo(true),
        iteraciones(0),
        vidas(VIDAS_INICIALES),
        danio_al_jugador(DANIO_INICIAL),
        puntos(PUNTOS_INICIALES_ENEMIGO)
// cppcheck-suppress readability/multiline_comment
/*
time_revive(TIME_REVIVE_INICIAL),
prob_municion(0.0f),
prob_vida(0.0f)
*/
{}

// Enemigo1 constructor
Enemigo1::Enemigo1() { set_tipo_enemigo(TipoEnemigo::ENEMIGO1); }

// Enemigo2 constructor
Enemigo2::Enemigo2() { set_tipo_enemigo(TipoEnemigo::ENEMIGO2); }

// Enemigo3 constructor
Enemigo3::Enemigo3() { set_tipo_enemigo(TipoEnemigo::ENEMIGO3); }

void Enemigo::set_tipo_enemigo(TipoEnemigo tipo_enemigo) { this->tipo_enemigo = tipo_enemigo; }

uint16_t Enemigo::get_vidas() { return vidas; }

uint16_t Enemigo::get_danio_al_jugador() { return danio_al_jugador; }

uint16_t Enemigo::get_puntos() { return puntos; }

void Enemigo::atacar_enemigo() {
    if (vivo) {
        vidas--;
        if (vidas == 0) {
            vivo = false;
        }
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

void Enemigo::revivir_enemigo() {
    if (!vivo) {
        vivo = true;
        vidas = VIDAS_INICIALES;
    }
}

bool Enemigo::esta_vivo() { return vivo; }
