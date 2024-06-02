#ifndef STRUCTMSG_H
#define STRUCTMSG_H

#include <cstdint>

#include "game_state.h"

struct msgAccion {
    uint8_t accion = 0x06;
    uint8_t toggle = 0x00;

    msgAccion(): accion(0x00), toggle(false) {}
    msgAccion(uint8_t acc, bool tog): accion(acc), toggle(tog) {}

    msgAccion& operator=(const msgAccion& other) {
        if (this != &other) {  // Evita autoasignación
            accion = other.accion;
            toggle = other.toggle;
        }
        return *this;
    }

} __attribute__((packed));

struct msgGameState {
    uint8_t header = 0x06;  // la idea seria no editar esto.
    uint8_t state_partida;
    uint16_t client_id;
    // uint16_t tiempo;
    uint16_t cantidad_personajes = 1;

    msgGameState() {}

    msgGameState(GameState& gameState, uint16_t client_id):
            state_partida(gameState.getJugando() ? 0x01 : 0x00),
            client_id(client_id),
            cantidad_personajes(gameState.getSizePersonajes()) {}

    msgGameState& operator=(const msgGameState& other) {
        if (this != &other) {  // Evita autoasignación
            state_partida = other.state_partida;
            // tiempo = other.tiempo;
            cantidad_personajes = other.cantidad_personajes;
        }
        return *this;
    }
} __attribute__((packed));

struct msgPersonaje {
    uint16_t personaje[7] = {0};  // id - posx - posy - puntos - vida - municion - arma

    msgPersonaje() {}

    msgPersonaje(uint16_t id, const Personaje& pers) {
        personaje[0] = id;
        personaje[1] = pers.obtener_posicion().get_posicion_x();
        personaje[2] = pers.obtener_posicion().get_posicion_y();
        personaje[3] = pers.obtener_puntos();
        personaje[4] = pers.obtener_vida();
        personaje[5] = pers.obtener_municion();
        personaje[6] = pers.obtener_nombre_arma();
    }

    msgPersonaje& operator=(const msgPersonaje& other) {
        if (this != &other) {  // Evita autoasignación
            for (size_t i = 0; i < sizeof(personaje) / sizeof(personaje[0]); i++) {
                personaje[i] = other.personaje[i];
            }
        }
        return *this;
    }
};

#endif
