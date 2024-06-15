#include "../../include/server_src/game/game_comandos.h"

#include "../../include/server_src/game/game_class.h"

Comando::Comando(): toggle(false) {}

Comando::Comando(uint16_t client_id, bool toggle): client_id(client_id), toggle(toggle) {}

void Comando::set_client_id(uint16_t client_id) { this->client_id = client_id; }

void Comando::set_toggle(bool toggle) { this->toggle = toggle; }

// **** DISPARAR ****
Disparar::Disparar(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void Disparar::ejecutar(Game& game) {
    // Para no estar todo el tiempo buscando el personaje, lo busco una sola vez y lo guardo
    Personaje& personaje = game.obtener_personaje(client_id);
    if (toggle) {
        personaje.obtener_estados().setDisparando(true);
        personaje.disparar();
    } else {
        personaje.obtener_estados().setDisparando(false);
        // No lo seteo en idle devuelta, porque capaz estaba corriendo o saltando
    }
}


// **** ACCION ESPECIAL ****
AccionEspecial::AccionEspecial(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void AccionEspecial::ejecutar(Game& game) {
    // Para no estar todo el tiempo buscando el personaje, lo busco una sola vez y lo guardo
    Personaje& personaje = game.obtener_personaje(client_id);
    if (toggle) {
        personaje.obtener_estados().reset();
        personaje.obtener_estados().setAccionEspecial(true);
        personaje.accion_especial();
    } else {
        personaje.obtener_estados().setAccionEspecial(false);
        personaje.obtener_estados().setIdle(true);
        personaje.obtener_velocidad().idle();
    }
}


// **** MOVER ****
MoverDerecha::MoverDerecha(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void MoverDerecha::ejecutar(Game& game) {
    // Para no estar todo el tiempo buscando el personaje, lo busco una sola vez y lo guardo
    Personaje& personaje = game.obtener_personaje(client_id);
    if (toggle) {
        personaje.obtener_estados().reset();
        personaje.obtener_estados().setCorriendo(true);
        personaje.obtener_velocidad().correrDerecha();
    } else {
        personaje.obtener_estados().setCorriendo(false);
        personaje.obtener_estados().setIdle(true);
        personaje.obtener_velocidad().idle();
    }
}

MoverDerechaRapido::MoverDerechaRapido(uint16_t client_id, bool toggle):
        Comando(client_id, toggle) {}

void MoverDerechaRapido::ejecutar(Game& game) {
    // Para no estar todo el tiempo buscando el personaje, lo busco una sola vez y lo guardo
    Personaje& personaje = game.obtener_personaje(client_id);
    if (toggle) {
        personaje.obtener_estados().reset();
        personaje.obtener_estados().setCorriendoMuyRapido(true);
        personaje.obtener_velocidad().correrDerechaRapido();
    } else {
        personaje.obtener_estados().setCorriendoMuyRapido(false);
        personaje.obtener_estados().setIdle(true);
        personaje.obtener_velocidad().idle();
    }
}

MoverIzquierda::MoverIzquierda(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void MoverIzquierda::ejecutar(Game& game) {
    // Para no estar todo el tiempo buscando el personaje, lo busco una sola vez y lo guardo
    Personaje& personaje = game.obtener_personaje(client_id);
    if (toggle) {
        personaje.obtener_estados().reset();
        personaje.obtener_estados().setCorriendo(true);
        personaje.obtener_velocidad().correrIzquierda();
    } else {
        personaje.obtener_estados().setCorriendo(false);
        personaje.obtener_estados().setIdle(true);
        personaje.obtener_velocidad().idle();
    }
}

MoverIzquierdaRapido::MoverIzquierdaRapido(uint16_t client_id, bool toggle):
        Comando(client_id, toggle) {}

void MoverIzquierdaRapido::ejecutar(Game& game) {
    // Para no estar todo el tiempo buscando el personaje, lo busco una sola vez y lo guardo
    Personaje& personaje = game.obtener_personaje(client_id);
    if (toggle) {
        personaje.obtener_estados().reset();
        personaje.obtener_estados().setCorriendoMuyRapido(true);
        personaje.obtener_velocidad().correrIzquierdaRapido();
    } else {
        personaje.obtener_estados().setCorriendoMuyRapido(false);
        personaje.obtener_estados().setIdle(true);
        personaje.obtener_velocidad().idle();
    }
}

// **** SALTAR ****

Saltar::Saltar(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void Saltar::ejecutar(Game& game) {
    // Para no estar todo el tiempo buscando el personaje, lo busco una sola vez y lo guardo
    Personaje& personaje = game.obtener_personaje(client_id);
    if (toggle) {
        personaje.obtener_estados().reset();
        personaje.obtener_estados().setSaltando(true);
        personaje.obtener_velocidad().saltar();
    } else {
        personaje.obtener_estados().setSaltando(false);
        personaje.obtener_estados().setIdle(true);
        personaje.obtener_velocidad().idle();
    }
}


// **** CAMBIAR DE ARMA ****
CambiarArma::CambiarArma(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void CambiarArma::ejecutar(Game& game) {
    if (toggle) {
        game.obtener_personaje(client_id).cambiar_arma();
    }
}


// **** Kill all ****
KillAll::KillAll(uint16_t client_id, bool toggle): Comando(client_id, toggle) {}

void KillAll::ejecutar(Game& game) {
    if (toggle) {
        game.cheat_matar_todos_los_enemigos();
    }
}
