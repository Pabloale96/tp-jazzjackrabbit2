#ifndef DEFINE_MSG_H
#define DEFINE_MSG_H


enum class TIPO_PERSONAJE: uint16_t {JAZZ=0,LORI=1,SPAZZ=2};

// los 3 modos que puede estar la plataforma:
enum class ROTATE_PLATFORM: uint16_t {ROTATE_0=0,ROTATE_45=1,ROTATE_90=2};

// tipo de plataforma usado de gui para la interfaz:
enum class TYPE_PLATFORM: uint16_t{TYPE_1=0,TYPE_2=1,TYPE_3=2};


// definiciones del arreglo de personaje
#define SIZE_ARRAY_PERSONAJE 8
#define POS_ID_PERSONAJE 0
#define POS_POSX_PERSONAJE 1
#define POS_POSY_PERSONAJE 2
#define POS_PUNTOS_PERSONAJE 3
#define POS_VIDA_PERSONAJE 4
#define POS_MUNICION_PERSONAJE 5
#define POS_ARMA_PERSONAJE 6
#define POS_TIPO_PERSONAJE 7

// definiciones del arreglo de plataforma
#define SIZE_ARRAY_PLATAFORMA 6
#define POS_POSX_PLATAFORMA 0
#define POS_POSY_PLATAFORMA 1
#define POS_TIPO_PLATAFORMA 2
#define POS_ROTATE_PLATAFORM 3
#define POS_WIDTH_PLATAFORMA 4
#define POS_HEIGHT_PLATAFORM 5

#define SIZE_ARRAY_ENEMIGO 4
#define POS_ID_ENEMIGO 0
#define POS_TIPO_ENEMIGO 1
#define POS_POSX_ENEMIGO 2
#define POS_POSY_ENEMIGO 3

#endif
