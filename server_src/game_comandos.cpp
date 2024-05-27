#include "../server_src/game_comandos.h"

#include "../server_src/game_class.h"

bool Disparar::ejecutar(Game& game) { return game.matar_enemigo(); }

bool MoverDerecha::ejecutar(Game& game) { return game.mover("derecha", client_id); }

bool MoverDerechaRapido::ejecutar(Game& game) { return game.mover("derecha_rapido", client_id); }

bool MoverIzquierda::ejecutar(Game& game) { return game.mover("izquierda", client_id); }

bool MoverIzquierdaRapido::ejecutar(Game& game) {
    return game.mover("izquierda_rapido", client_id);
}

bool Saltar::ejecutar(Game& game) { return game.mover("saltar", client_id); }

// Arriba y abajo creo que no hay, sería saltar y agacharse?
bool MoverArriba::ejecutar(Game& game) { return game.mover("arriba", client_id); }

bool MoverAbajo::ejecutar(Game& game) { return game.mover("abajo", client_id); }
