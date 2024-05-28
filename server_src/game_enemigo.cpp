#include "../server_src/game_enemigo.h"

#include <iostream>

Enemigo::Enemigo():
        vivo(true),
        iteraciones(0),
        vidas(VIDAS_INICIALES),
        danio(DANIO_INICIAL)
// cppcheck-suppress readability/multiline_comment
/*,
puntos(PUNTOS_INICIALES),
time_revive(TIME_REVIVE_INICIAL),
prob_municion(0.0f),
prob_vida(0.0f)
*/
{}

// Enemigo1 constructor
Enemigo1::Enemigo1() {}

// Enemigo2 constructor
Enemigo2::Enemigo2() {}

// Enemigo3 constructor
Enemigo3::Enemigo3() {}

void Enemigo::matar_enemigo() {
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
