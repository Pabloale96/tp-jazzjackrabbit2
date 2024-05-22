#include "../server_src/game_comandos.h"

#include "../server_src/game_class.h"

bool Disparar::ejecutar(Game& game) { return game.matar_enemigo(); }

bool MoverDerecha::ejecutar(Game& game) { return game.mover("derecha"); }

bool MoverDerechaRapido::ejecutar(Game& game) { return game.mover("derecha_rapido"); }

bool MoverIzquierda::ejecutar(Game& game) { return game.mover("izquierda"); }

bool MoverIzquierdaRapido::ejecutar(Game& game) { return game.mover("izquierda_rapido"); }

bool Saltar::ejecutar(Game& game) { return game.mover("saltar"); }

// Arriba y abajo creo que no hay, sería saltar y agacharse?
bool MoverArriba::ejecutar(Game& game) { return game.mover("arriba"); }

bool MoverAbajo::ejecutar(Game& game) { return game.mover("abajo"); }
