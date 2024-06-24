#ifndef STRUCTMSG_H
#define STRUCTMSG_H

#define TOGGLE_OFF 0x00

#define MSG_HEADER 0x06
#define TIPO_PERSONAJE_NULO 0x00

#include <cstdint>
#include <cstring>  // para usar memset()

#include <arpa/inet.h>  // para usar htons()

#include "defines_msg.h"
#include "game_platform.h"
#include "game_state.h"
#include "protocol_utils.h"

struct msgAccion {
    uint8_t accion;
    uint8_t toggle;

    msgAccion(): accion(static_cast<uint8_t>(acciones::NULO)), toggle(TOGGLE_OFF) {}
    msgAccion(uint8_t acc, uint8_t tog): toggle(tog) {
        switch (static_cast<acciones>(acc)) {
            case acciones::NULO:
                accion = static_cast<uint8_t>(acciones::NULO);
                break;
            case acciones::MOVER_DERECHA:
                accion = static_cast<uint8_t>(acciones::MOVER_DERECHA);
                break;
            case acciones::MOVER_DERECHA_RAPIDO:
                accion = static_cast<uint8_t>(acciones::MOVER_DERECHA_RAPIDO);
                break;
            case acciones::MOVER_IZQUIERDA:
                accion = static_cast<uint8_t>(acciones::MOVER_IZQUIERDA);
                break;
            case acciones::MOVER_IZQUIERDA_RAPIDO:
                accion = static_cast<uint8_t>(acciones::MOVER_IZQUIERDA_RAPIDO);
                break;
            case acciones::SALTAR:
                accion = static_cast<uint8_t>(acciones::SALTAR);
                break;
            case acciones::DISPARAR:
                accion = static_cast<uint8_t>(acciones::DISPARAR);
                break;
            case acciones::ACCION_ESPECIAL:
                accion = static_cast<uint8_t>(acciones::ACCION_ESPECIAL);
                break;
            case acciones::KILL_ALL:
                accion = static_cast<uint8_t>(acciones::KILL_ALL);
                break;
            default:
                accion = static_cast<uint8_t>(acciones::NULO);
                break;
        }
    }
} __attribute__((packed));

struct msgGameState {
    uint8_t header;
    uint8_t state_partida;
    uint16_t client_id;
    uint16_t tiempo;
    uint16_t cantidad_personajes;
    uint16_t cantidad_enemigos;
    uint16_t cantidad_colecionables;
    uint16_t cantidad_balas;

    msgGameState() {
        memset(this, 0, sizeof(*this));
        header = MSG_HEADER;
        state_partida = 0x00;
        client_id = 0x00;
        cantidad_personajes = 0x01;
        cantidad_enemigos = 0x00;
    }

    msgGameState(GameState& gameState, uint16_t cantidadBalas, uint16_t tiempo,
                 uint16_t client_id) {
        memset(this, 0, sizeof(*this));
        header = MSG_HEADER;
        state_partida = gameState.getJugando() ? 0x01 : 0x00;
        this->client_id = htons(client_id);
        this->tiempo = htons(tiempo);
        cantidad_personajes = htons(gameState.getSizePersonajes());
        cantidad_enemigos = htons(gameState.get_cantidad_de_enemigos());
        // cantidad_colecionables = htons(gameState.obtener_cantidad_de_colecionables());
        cantidad_balas = htons(cantidadBalas);
    }
} __attribute__((packed));

struct msgPersonaje {
    uint8_t tipo_personaje;
    uint8_t tipo_arma;
    uint8_t estado;
    uint16_t personaje[SIZE_ARRAY_PERSONAJE];

    msgPersonaje() {
        memset(this, 0, sizeof(*this));
        tipo_personaje = TIPO_PERSONAJE_NULO;
        tipo_arma = 0x00;
        estado = static_cast<uint8_t>(efectos::IDLE);
    }

    msgPersonaje(uint16_t id, Personaje& pers) {
        memset(this, 0, sizeof(*this));
        tipo_personaje = pers.obtener_tipo_personaje();
        tipo_arma = pers.obtener_nombre_arma();
        estado = pers.obtener_estado_actual();  // accion -->animacion
        personaje[POS_ID_PERSONAJE] = htons(id);
        // Se multiplica por 100 y se castea a uint16 para enviar la posición con dos decimales
        personaje[POS_POSX_PERSONAJE] =
                htons((uint16_t)((pers.obtener_posicion().get_posicion_x()) * 100));
        personaje[POS_POSY_PERSONAJE] =
                htons((uint16_t)((pers.obtener_posicion().get_posicion_y()) * 100));
        personaje[POS_PUNTOS_PERSONAJE] = htons(pers.obtener_puntos());
        personaje[POS_VIDA_PERSONAJE] = htons(pers.obtener_vida());
        personaje[POS_MUNICION_PERSONAJE] = htons(pers.obtener_municion());
    }
} __attribute__((packed));


struct msgColecionables {
    uint8_t tipo_coleccionable = 0x00;
    uint16_t colecionables[SIZE_ARRAY_COLECCIONABLE] = {0};

    msgColecionables() {}

    explicit msgColecionables(Municion& muni): tipo_coleccionable(muni.obtener_tipo_bala()) {
        colecionables[POS_POSX_COLECCIONABLE] = htons(muni.obtener_x());
        colecionables[POS_POSY_COLECCIONABLE] = htons(muni.obtener_y());
    }
} __attribute__((packed));


struct msgBalas {
    uint8_t tipo_bala = 0x00;
    uint16_t balas[SIZE_ARRAY_BALA] = {0};

    msgBalas() {}

    explicit msgBalas(Municion& muni): tipo_bala(muni.obtener_tipo_bala()) {
        balas[POS_POSX_BALA] = htons(muni.obtener_x());
        balas[POS_POSY_BALA] = htons(muni.obtener_y());
    }
} __attribute__((packed));


struct msgEnemigo {
    uint8_t tipo = 0x00;
    uint16_t enemigo[SIZE_ARRAY_ENEMIGO] = {0};

    msgEnemigo() {}

    msgEnemigo(uint16_t id, const Enemigo& enemi): tipo((uint8_t)enemi.get_tipo_enemigo()) {
        enemigo[POS_ID_ENEMIGO] = htons(id);
        enemigo[POS_TIPO_ENEMIGO] = htons((uint16_t)enemi.get_tipo_enemigo());
        // Se multiplica por 100 y se castea a uint16 para enviar la posición con dos decimales
        enemigo[POS_POSX_ENEMIGO] =
                htons((uint16_t)((enemi.get_posicion_enemigo().get_posicion_x()) * 100));
        enemigo[POS_POSY_ENEMIGO] =
                htons((uint16_t)((enemi.get_posicion_enemigo().get_posicion_y()) * 100));
    }
} __attribute__((packed));

struct msgEscenario {
    uint16_t cantidad_plataformas = 0;

    explicit msgEscenario(const uint16_t& cantidad) { cantidad_plataformas = htons(cantidad); }
} __attribute__((packed));

struct msgPlataforma {
    uint8_t tipo_plataforma = 0;
    uint8_t flip = 0x00;
    uint16_t plataforma[SIZE_ARRAY_PLATAFORMA] = {0};

    msgPlataforma() {}

    explicit msgPlataforma(const Platform& pla):
            tipo_plataforma(pla.obtener_tipo()), flip(pla.obtener_flip()) {
        plataforma[POS_POSX_PLATAFORMA] = pla.obtener_posicion_x();
        plataforma[POS_POSY_PLATAFORMA] = pla.obtener_posicion_y();
        plataforma[POS_WIDTH_PLATAFORMA] = pla.obtener_width();
        plataforma[POS_HEIGHT_PLATAFORM] = pla.obtener_height();
    }
} __attribute__((packed));


#endif
