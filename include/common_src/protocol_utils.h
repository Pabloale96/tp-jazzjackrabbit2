#ifndef _COMMON_PROTOCOL_UTILS_H_
#define _COMMON_PROTOCOL_UTILS_H_

#include <cstdint>

#define CREAR_PARTIDA 0x01
#define UNIRSE_A_PARTIDA 0x02

#define HEIGHT_PLATFORM_TYPE_1 29
#define WIDTH_PLATFORM_TYPE_1 192

#define SCALING_VALUE_PIXEL 10

// los 3 modos que puede estar la plataforma:
enum class rot_platform : uint8_t { ROTATE_0 = 0, ROTATE_45 = 1, ROTATE_90 = 2 };

// tipo de plataforma usado de gui para la interfaz:
enum class platform : uint8_t { TYPE_1 = 0, TYPE_2 = 1, TYPE_3 = 2 };

enum class personajes : uint8_t { JAZZ = 0x01, SPAZZ = 0x02, LORI = 0x03 };

enum class acciones : uint8_t {

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

enum class efectos : uint8_t {
    IDLE = 0x01,

    // Acciones comunes
    DISPARANDO = 0x02,
    CORRIENDO = 0x03,
    CORRIENDO_RAPIDO = 0x04,
    SALTANDO = 0x05,

    // Estados
    INTOXICADO = 0x06,
    HERIDO = 0x07,
    MUERTO = 0x08,

    // Acciones especiales
    ACCION_ESPECIAL = 0x09
};

enum class armas : uint8_t { ARMA_INICIAL = 0x01, ARMA_SECUNDARIA = 0x02 };

#endif
