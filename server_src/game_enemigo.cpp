#include "../server_src/game_enemigo.h"

#include <iostream>

Enemigo::Enemigo():
        vivo(true),
        iteraciones(0)
// cppcheck-suppress readability/multiline_comment
/*,
vidas(VIDAS_INICIALES),
danio(SIN_DANIO_INICIAL),
puntos(PUNTOS_INICIALES),
time_revive(TIME_REVIVE_INICIAL),
prob_municion(0.0f),
prob_vida(0.0f)
*/
{}

void Enemigo::matar_enemigo() {
    if (vivo) {
        vivo = false;
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
    }
}

bool Enemigo::esta_vivo() { return vivo; }
