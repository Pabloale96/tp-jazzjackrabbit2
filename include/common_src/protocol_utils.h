#ifndef _COMMON_PROTOCOL_UTILS_H_
#define _COMMON_PROTOCOL_UTILS_H_

#include <cstdint>

#define CREAR_PARTIDA 0x01
#define UNIRSE_A_PARTIDA 0x02

#define HEIGHT_PLATFORM_TYPE_1 29
#define WIDTH_PLATFORM_TYPE_1 192

#define SCALING_VALUE_PIXEL_X 100
#define SCALING_VALUE_PIXEL_Y 64

// tipo de plataforma usado de gui para la interfaz:
enum class platform : uint8_t { HORIZONTAL = 0, DIAGONAL = 1, VERTICAL = 2 };

enum class balas : uint8_t { BALA_TIPO1 = 0, BALA_TIPO2 = 1 };

enum class coleccionables : uint8_t { MONEDA_TIPO = 0, GEMAS_TIPO = 1, ZANAHORIA_TIPO = 2 };

// tipo de enemigos usado de gui para la interfaz:
enum class enemigos : uint8_t { ENEMIGO1 = 0, ENEMIGO2 = 1, ENEMIGO3 = 2 };

enum class personajes : uint8_t { JAZZ = 0x01, SPAZZ = 0x02, LORI = 0x03 };

enum class TipoEnemigo : uint8_t { ENEMIGO1, ENEMIGO2, ENEMIGO3 };

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
    SALTAR_DISPARANDO = 0X08,

    //   >> Cambio de armas
    CAMBIAR_ARMA = 0x09,

    // Cheats
    KILL_ALL = 0x010
};

enum class efectos : uint8_t {
    IDLE = 0x01,

    // Acciones comunes
    DISPARANDO = 0x02,
    CORRIENDO = 0x03,
    CORRIENDO_RAPIDO = 0x04,
    SALTANDO = 0x05,
    CAYENDO = 0x06,

    // Estados
    INTOXICADO = 0x07,
    HERIDO = 0x08,
    MUERTO = 0x09,

    // Acciones especiales
    ACCION_ESPECIAL = 0x10,

    // Combinaciones
    //      con disparar
    DISPARANDO_CORRIENDO = 0x11,
    DISPARANDO_SALTANDO = 0x12,
    DISPARANDO_CAYENDO = 0x13,
    //      con correr
    CORRIENDO_SALTANDO = 0x14
};

enum class armas : uint8_t { ARMA_INICIAL = 0x01, ARMA_1 = 0x02, ARMA_2 = 0x03 };

#endif
