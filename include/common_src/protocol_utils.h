#ifndef _COMMON_PROTOCOL_UTILS_H_
#define _COMMON_PROTOCOL_UTILS_H_

#include <cstdint>

#define CREAR_PARTIDA 0x01
#define UNIRSE_A_PARTIDA 0x02

enum class personajes : uint8_t {
    JAZZ = 0x01,
    SPAZZ = 0x02,
    LORI = 0x03
};

enum class acciones: uint8_t {

    NULO = 0x00,

    // Acciones del personaje
    //    >> Movimientos
    MOVER_DERECHA = 0x01,
    MOVER_DERECHA_RAPIDO = 0x02,
    MOVER_IZQUIERDA = 0x03,
    MOVER_IZQUIERDA_RAPIDO = 0x04,
    SALTAR = 0x05,
    //    >> Ataques
    DISPARAR = 0x06,
    ACCION_ESPECIAL = 0x07,

    // Cheats
    KILL_ALL = 0x08
};

enum class armas: uint8_t {
    ARMA_INICIAL = 0x01,
    ARMA_SECUNDARIA = 0x02
};

#endif
