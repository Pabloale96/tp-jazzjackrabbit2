#include "../../include/server_src/game/game_comandos.h"

#include "../../include/server_src/game/game_class.h"

Comando::Comando(): toggle(false) {}

Comando::Comando(uint16_t client_id, bool toggle): client_id(client_id), toggle(toggle) {}

void Comando::set_client_id(uint16_t client_id) { this->client_id = client_id; }

void Comando::set_toggle(bool toggle) { this->toggle = toggle; }

// **** DISPARAR ****

Disparar::Disparar(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void Disparar::ejecutar(Game& game) {
    if (toggle) {
        // game.atacar_enemigo(client_id);
    }
}

// **** ACCION ESPECIAL ****
AccionEspecial::AccionEspecial(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void AccionEspecial::ejecutar(Game& game) {
    if (toggle) {
        game.accion_especial(client_id);
    }
}


// **** MOVER ****

MoverDerecha::MoverDerecha(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void MoverDerecha::ejecutar(Game& game) {
    if (toggle) {
        game.mover("derecha", client_id);
    }
}

MoverDerechaRapido::MoverDerechaRapido(uint16_t client_id, bool toggle):
        Comando(client_id, toggle) {}

void MoverDerechaRapido::ejecutar(Game& game) {
    if (toggle) {
        game.mover("derecha_rapido", client_id);
    }
}

MoverIzquierda::MoverIzquierda(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void MoverIzquierda::ejecutar(Game& game) {
    if (toggle) {
        game.mover("izquierda", client_id);
    }
}

MoverIzquierdaRapido::MoverIzquierdaRapido(uint16_t client_id, bool toggle):
        Comando(client_id, toggle) {}

void MoverIzquierdaRapido::ejecutar(Game& game) {
    if (toggle) {
        game.mover("izquierda_rapido", client_id);
    }
}

// **** SALTAR ****

Saltar::Saltar(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void Saltar::ejecutar(Game& game) {
    if (toggle) {
        game.mover("saltar", client_id);
    }
}


Saltando::Saltando(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void Saltando::ejecutar(Game& game) {
    if (toggle) {
        game.mover("saltando", client_id);
    }
}

Cayendo::Cayendo(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void Cayendo::ejecutar(Game& game) {
    if (toggle) {
        game.mover("cayendo", client_id);
    }
}


// **** Kill all ****

KillAll::KillAll(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void KillAll::ejecutar(Game& game) {
    if (toggle) {
        game.mover("saltar", client_id);
    }
}
