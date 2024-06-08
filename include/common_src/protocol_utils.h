#ifndef _COMMON_PROTOCOL_UTILS_H_
#define _COMMON_PROTOCOL_UTILS_H_

#define CREAR_PARTIDA 0x01
#define UNIRSE_A_PARTIDA 0x02

enum class TIPO_PERSONAJE: uint8_t {JAZZ=0x00,LORI=0x01,SPAZZ=0x02};

// los 3 modos que puede estar la plataforma:
enum class ROTATE_PLATFORM: uint8_t {ROTATE_0=0,ROTATE_45=1,ROTATE_90=2};

// tipo de plataforma usado de gui para la interfaz:
enum class TYPE_PLATFORM: uint8_t{TYPE_1=0,TYPE_2=1,TYPE_3=2};


#define DISPARAR 0x01
#define MOVER_DERECHA 0x02
#define MOVER_DERECHA_RAPIDO 0x03
#define MOVER_IZQUIERDA 0x04
#define MOVER_IZQUIERDA_RAPIDO 0x05
#define MOVER_ARRIBA 0x06
#define MOVER_ABAJO 0x07
#define SALTAR 0x08

#define ARMA_INICIAL 0x01
#define ARMA_SECUNDARIA 0x02


#endif
