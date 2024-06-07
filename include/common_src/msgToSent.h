#ifndef STRUCTMSG_H
#define STRUCTMSG_H

#define ACCION_NULA 0x00
#define TOGGLE_OFF 0x00

#define MSG_HEADER 0x06

#include <cstdint>

#include <arpa/inet.h>  // para usar htons()

#include "defines_msg.h"
#include "game_platform.h"
#include "game_state.h"

struct msgAccion {
    uint8_t accion;
    uint8_t toggle;

    msgAccion(): accion(ACCION_NULA), toggle(TOGGLE_OFF) {}
    msgAccion(uint8_t acc, uint8_t tog): accion(acc), toggle(tog) {}

} __attribute__((packed));

struct msgGameState {
    uint8_t header;
    uint8_t state_partida;
    uint16_t client_id;
    // uint16_t tiempo;
    uint16_t cantidad_personajes;
    uint16_t cantidad_enemigos;

    msgGameState(): header(MSG_HEADER), cantidad_personajes(1) {}

    msgGameState(GameState& gameState, uint16_t client_id):
            header(MSG_HEADER),
            state_partida(gameState.getJugando() ? 0x01 : 0x00),
            client_id(htons(client_id)),
            cantidad_personajes(htons(gameState.getSizePersonajes())),
            cantidad_enemigos(htons(gameState.get_cantidad_de_enemigos())) {}

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
        personaje[POS_TIPO_PERSONAJE] = htons(pers.obtener_tipo_personaje());
    }
};

struct msgEnemigo {
    uint16_t enemigo[SIZE_ARRAY_ENEMIGO] = {0};

    msgEnemigo() {}

    msgEnemigo(uint16_t id, const Enemigo& enemi) {
        enemigo[POS_ID_ENEMIGO] = htons(id);
        enemigo[POS_TIPO_ENEMIGO] = htons((uint16_t)enemi.get_tipo_enemigo());
        enemigo[POS_POSX_ENEMIGO] = htons(enemi.get_posicion_enemigo().get_posicion_x());
        enemigo[POS_POSY_ENEMIGO] = htons(enemi.get_posicion_enemigo().get_posicion_y());
    }
};

struct msgEscenario {
    uint16_t cantidad_plataformas = 0;

    explicit msgEscenario(const uint16_t& cantidad) { cantidad_plataformas = htons(cantidad); }
};

struct msgPlataforma {
    uint16_t plataforma[SIZE_ARRAY_PLATAFORMA] = {0};

    msgPlataforma() {}

    explicit msgPlataforma(const Platform& pla) {
        plataforma[POS_POSX_PLATAFORMA] = pla.obtener_posicion_x();
        plataforma[POS_POSY_PLATAFORMA] = pla.obtener_posicion_y();
        plataforma[POS_TIPO_PLATAFORMA] = pla.obtener_tipo();
        plataforma[POS_ROTATE_PLATAFORM] = pla.obtener_rotate();
        plataforma[POS_WIDTH_PLATAFORMA] = pla.obtener_width();
        plataforma[POS_HEIGHT_PLATAFORM] = pla.obtener_height();
    }
};


#endif
