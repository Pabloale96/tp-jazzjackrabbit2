#ifndef __SERVER_JUEGO_MENSAJE_H__
#define __SERVER_JUEGO_MENSAJE_H__

#include <cstdint>
#include <iostream>
#include <string>

#define MATAR 0x04
#define REVIVIR 0x05

class ServerJuegoMensaje {
private:
    uint8_t accion;
    uint16_t enemigos_vivos;
    uint16_t enemigos_muertos;

public:
    ServerJuegoMensaje(uint8_t accion, uint16_t enemigos_vivos, uint16_t enemigos_muertos);

    void imprimir_mensaje();

    uint8_t obtener_accion();

    uint16_t obtener_enemigos_vivos();

    uint16_t obtener_enemigos_muertos();

    ~ServerJuegoMensaje();
};

#endif
