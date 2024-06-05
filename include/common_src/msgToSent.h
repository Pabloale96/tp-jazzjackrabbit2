#ifndef STRUCTMSG_H
#define STRUCTMSG_H

#include <cstdint>
#include <arpa/inet.h>   // para usar htons()

#include "defines_msg.h"
#include "game_state.h"
#include "game_platform.h"

struct msgAccion {
    uint8_t accion = 0x00;
    uint8_t toggle = 0x00;

    msgAccion(): accion(0x00), toggle(0x00) {}
    msgAccion(uint8_t acc, uint8_t tog): accion(acc), toggle(tog) {}

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
            client_id(htons(client_id)),
            cantidad_personajes(htons(gameState.getSizePersonajes())) {}
} __attribute__((packed));

struct msgPersonaje {
    uint16_t personaje[SIZE_ARRAY_PERSONAJE] = {0};

    msgPersonaje() {}

    msgPersonaje(uint16_t id, const Personaje& pers) {
        personaje[POS_ID_PERSONAJE] = htons(id);
        personaje[POS_POSX_PERSONAJE] = htons(pers.obtener_posicion().get_posicion_x());
        personaje[POS_POSY_PERSONAJE] = htons(pers.obtener_posicion().get_posicion_y());
        personaje[POS_PUNTOS_PERSONAJE] = htons(pers.obtener_puntos());
        personaje[POS_VIDA_PERSONAJE] = htons(pers.obtener_vida());
        personaje[POS_MUNICION_PERSONAJE] = htons(pers.obtener_municion());
        personaje[POS_ARMA_PERSONAJE] = htons(pers.obtener_nombre_arma());
    }

};

struct msgEscenario {
    uint16_t cantidad_plataformas = 0;
    
    msgEscenario(const uint16_t& cantidad) {
        cantidad_plataformas = htons(cantidad);
    }

};

struct msgPlataforma {
    uint16_t plataforma[SIZE_ARRAY_PLATAFORMA] = {0};

    msgPlataforma() {}

    msgPlataforma(const Platform& pla) {
        plataforma[POS_POSX_PLATAFORMA] = pla.obtener_posicion_x();
        plataforma[POS_POSY_PLATAFORMA] = pla.obtener_posicion_y();
        plataforma[POS_TIPO_PLATAFORMA] = pla.obtener_tipo();
        plataforma[POS_ROTATE_PLATAFORM] = pla.obtener_rotate();
        plataforma[POS_WIDTH_PLATAFORMA] = pla.obtener_width();
        plataforma[POS_HEIGHT_PLATAFORM] = pla.obtener_height();
    }
};


#endif
