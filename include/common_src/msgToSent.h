#ifndef STRUCTMSG_H
#define STRUCTMSG_H

#include <cstdint>

#include "game_state.h"
#include "game_platform.h"


#define SIZE_ARRAY_PERSONAJE 7
#define POS_ID_PERSONAJE 0
#define POS_POSX_PERSONAJE 1
#define POS_POSY_PERSONAJE 2
#define POS_PUNTOS_PERSONAJE 3
#define POS_VIDA_PERSONAJE 4
#define POS_MUNICION_PERSONAJE 5
#define POS_ARMA_PERSONAJE 6

#define SIZE_ARRAY_PLATAFORMA 6
#define POS_POSX_PLATAFORMA 0
#define POS_POSY_PLATAFORMA 1
#define POS_TIPO_PLATAFORMA 2
#define POS_ROTATE_PLATAFORM 3
#define POS_WIDTH_PLATAFORMA 4
#define POS_HEIGHT_PLATAFORM 5

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
    uint16_t personaje[SIZE_ARRAY_PERSONAJE] = {0};

    msgPersonaje() {}

    msgPersonaje(uint16_t id, const Personaje& pers) {
        personaje[POS_ID_PERSONAJE] = id;
        personaje[POS_POSX_PERSONAJE] = pers.obtener_posicion().get_posicion_x();
        personaje[POS_POSY_PERSONAJE] = pers.obtener_posicion().get_posicion_y();
        personaje[POS_PUNTOS_PERSONAJE] = pers.obtener_puntos();
        personaje[POS_VIDA_PERSONAJE] = pers.obtener_vida();
        personaje[POS_MUNICION_PERSONAJE] = pers.obtener_municion();
        personaje[POS_ARMA_PERSONAJE] = pers.obtener_nombre_arma();
    }

    msgPersonaje& operator=(const msgPersonaje& other) {
        if (this != &other) {  // Evita autoasignación
            for (size_t i = 0; i < SIZE_ARRAY_PERSONAJE; i++) {
                personaje[i] = other.personaje[i];
            }
        }
        return *this;
    }
};

struct msgPlataforma {
    uint16_t plataforma[SIZE_ARRAY_PLATAFORMA] = {0};

    msgPlataforma() {}

    msgPlataforma(uint16_t id, const Platform& pla) {
        plataforma[POS_POSX_PLATAFORMA] = pla.obtener_posicion_x();
        plataforma[POS_POSY_PLATAFORMA] = pla.obtener_posicion_y();
        plataforma[POS_TIPO_PLATAFORMA] = pla.obtener_tipo();
        plataforma[POS_ROTATE_PLATAFORM] = pla.obtener_rotate();
        plataforma[POS_WIDTH_PLATAFORMA] = pla.obtener_width();
        plataforma[POS_HEIGHT_PLATAFORM] = pla.obtener_height();

    }

    msgPlataforma& operator=(const msgPlataforma& other) {
        if (this != &other) {  // Evita autoasignación
            for (size_t i = 0; i < SIZE_ARRAY_PLATAFORMA; i++) {
                plataforma[i] = other.plataforma[i];
            }
        }
        return *this;
    }
};


#endif
