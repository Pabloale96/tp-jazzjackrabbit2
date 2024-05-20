#include "../server_src/server_game.h"

#include <memory>
#include <string>

#include "../server_src/server_enemigo.h"

Game::Game(): personaje(), enemigos(NUMERO_INICIAL_ENEMIGOS) {}

Personaje Game::obtener_personaje() {
    return personaje;
}

bool Game::matar_enemigo() {
    for (auto& enemigo: enemigos) {
        if (enemigo.esta_vivo()) {
            enemigo.matar_enemigo();
            return true;
        }
    }
    return false;
}

bool Game::mover(std::string direccion) {
    if (direccion != "derecha" && direccion != "izquierda") {
        return false;
    } else {
        personaje.mover(direccion);
        return true;
    }
}

bool Game::aumentar_iteraciones() {
    for (auto& enemigo: enemigos) {
        if (!enemigo.esta_vivo()) {
            enemigo.aumentar_iteraciones();
            if (enemigo.esta_vivo()) {
                return true;
            }
        }
    }
    return false;
}

uint16_t Game::obtener_cant_vivos() {
    uint16_t cant_vivos = 0;
    for (auto& enemigo: enemigos) {
        if (enemigo.esta_vivo()) {
            cant_vivos++;
        }
    }
    return cant_vivos;
}

uint16_t Game::obtener_cant_muertos() {
    uint16_t cant_muertos = 0;
    for (auto& enemigo: enemigos) {
        if (!enemigo.esta_vivo()) {
            cant_muertos++;
        }
    }
    return cant_muertos;
}

Game::~Game() {}
