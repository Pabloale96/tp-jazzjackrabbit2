#include "../server_src/server_comandos.h"
#include "../server_src/server_game.h"

bool Atacar::ejecutar(Game& game) {
    return game.matar_enemigo();
}
