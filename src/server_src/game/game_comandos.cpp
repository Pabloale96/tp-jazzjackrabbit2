#include "../../include/server_src/game/game_comandos.h"

#include "../../include/server_src/game/game_class.h"

Comando::Comando(): toggle(false) {}

void Comando::set_client_id(uint16_t client_id) { this->client_id = client_id; }

void Comando::set_toggle(bool toggle) { this->toggle = toggle; }

void Disparar::ejecutar(Game& game) {
    if (toggle) {
        game.atacar_enemigo(client_id);
    }
}

void MoverDerecha::ejecutar(Game& game) {
    if (toggle) {
        game.mover("derecha", client_id);
    }
}

void MoverDerechaRapido::ejecutar(Game& game) {
    if (toggle) {
        game.mover("derecha_rapido", client_id);
    }
}

void MoverIzquierda::ejecutar(Game& game) {
    if (toggle) {
        game.mover("izquierda", client_id);
    }
}

void MoverIzquierdaRapido::ejecutar(Game& game) {
    if (toggle) {
        game.mover("izquierda_rapido", client_id);
    }
}

void Saltar::ejecutar(Game& game) {
    if (toggle) {
        game.mover("saltar", client_id);
    }
}

// Arriba y abajo creo que no hay, sería saltar y agacharse?
void MoverArriba::ejecutar(Game& game) {
    if (toggle) {
        game.mover("arriba", client_id);
    }
}

void MoverAbajo::ejecutar(Game& game) {
    if (toggle) {
        game.mover("abajo", client_id);
    }
}
