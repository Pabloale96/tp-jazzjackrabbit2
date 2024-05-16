#include "../server_src/server_enemigo.h"

#include <iostream>

Enemigo::Enemigo(): vivo(true), iteraciones(0) {}

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
