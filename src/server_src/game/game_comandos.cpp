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
        game.obtener_personaje(client_id).obtener_estados().reset();
        game.obtener_personaje(client_id).obtener_estados().setDisparando(true);
        game.disparar_municion(client_id);
    } else {
        game.obtener_personaje(client_id).obtener_estados().setDisparando(false);
        game.obtener_personaje(client_id).obtener_estados().setIdle(true);
    }
}

// **** ACCION ESPECIAL ****
AccionEspecial::AccionEspecial(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void AccionEspecial::ejecutar(Game& game) {
    if (toggle) {
        game.obtener_personaje(client_id).obtener_estados().reset();
        game.obtener_personaje(client_id).obtener_estados().setAccionEspecial(true);
        game.accion_especial(client_id);
    } else {
        game.obtener_personaje(client_id).obtener_estados().setAccionEspecial(false);
        game.obtener_personaje(client_id).obtener_estados().setIdle(true);
    }
}


// **** MOVER ****

MoverDerecha::MoverDerecha(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void MoverDerecha::ejecutar(Game& game) {
    if (toggle) {
        game.obtener_personaje(client_id).obtener_estados().reset();
        game.obtener_personaje(client_id).obtener_estados().setCorriendo(true);
        game.mover("derecha", client_id);
    } else {
        game.obtener_personaje(client_id).obtener_estados().setCorriendo(false);
        game.obtener_personaje(client_id).obtener_estados().setIdle(true);
    }
}

MoverDerechaRapido::MoverDerechaRapido(uint16_t client_id, bool toggle):
        Comando(client_id, toggle) {}

void MoverDerechaRapido::ejecutar(Game& game) {
    if (toggle) {
        game.obtener_personaje(client_id).obtener_estados().reset();
        game.obtener_personaje(client_id).obtener_estados().setCorriendoMuyRapido(true);
        game.mover("derecha_rapido", client_id);
    } else {
        game.obtener_personaje(client_id).obtener_estados().setCorriendoMuyRapido(false);
        game.obtener_personaje(client_id).obtener_estados().setIdle(true);
    }
}

MoverIzquierda::MoverIzquierda(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void MoverIzquierda::ejecutar(Game& game) {
    if (toggle) {
        game.obtener_personaje(client_id).obtener_estados().reset();
        game.obtener_personaje(client_id).obtener_estados().setCorriendo(true);
        game.mover("izquierda", client_id);
    } else {
        game.obtener_personaje(client_id).obtener_estados().setCorriendo(false);
        game.obtener_personaje(client_id).obtener_estados().setIdle(true);
    }
}

MoverIzquierdaRapido::MoverIzquierdaRapido(uint16_t client_id, bool toggle):
        Comando(client_id, toggle) {}

void MoverIzquierdaRapido::ejecutar(Game& game) {
    if (toggle) {
        game.obtener_personaje(client_id).obtener_estados().reset();
        game.obtener_personaje(client_id).obtener_estados().setCorriendoMuyRapido(true);
        game.mover("izquierda_rapido", client_id);
    } else {
        game.obtener_personaje(client_id).obtener_estados().setCorriendoMuyRapido(false);
        game.obtener_personaje(client_id).obtener_estados().setIdle(true);
    }
}

// **** SALTAR ****

Saltar::Saltar(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void Saltar::ejecutar(Game& game) {
    if (toggle) {
        game.obtener_personaje(client_id).obtener_estados().reset();
        game.obtener_personaje(client_id).obtener_estados().setSaltando(true);
        game.mover("saltar", client_id);
        // game.obtener_personaje(client_id).obtener_estados().setSaltando(false);
        // game.obtener_personaje(client_id).obtener_estados().setCayendo(true);
        // game.mover("cayendo", client_id);
    } else {
        game.obtener_personaje(client_id).obtener_estados().setSaltando(false);
    }
}


Saltando::Saltando(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void Saltando::ejecutar(Game& game) {
    if (toggle) {
        game.obtener_personaje(client_id).obtener_estados().reset();
        game.obtener_personaje(client_id).obtener_estados().setSaltando(true);
        game.mover("saltando", client_id);
    } else {
        game.obtener_personaje(client_id).obtener_estados().setSaltando(false);
    }
}

Cayendo::Cayendo(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void Cayendo::ejecutar(Game& game) {
    if (toggle) {
        game.obtener_personaje(client_id).obtener_estados().reset();
        game.obtener_personaje(client_id).obtener_estados().setCayendo(true);
        game.mover("cayendo", client_id);
    } else {
        game.obtener_personaje(client_id).obtener_estados().setCayendo(false);
    }
}


// **** Kill all ****

KillAll::KillAll(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void KillAll::ejecutar(Game& game) {
    if (toggle) {
        game.mover("saltar", client_id);
    }
}
