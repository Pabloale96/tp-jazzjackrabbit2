#ifndef __SERVER_JUEGO_MENSAJE_H__
#define __SERVER_JUEGO_MENSAJE_H__

#include <cstdint>
#include <iostream>
#include <string>

#include "../server_src/personaje.h"

class ServerJuegoMensaje {
private:
    Personaje personaje;

public:
    explicit ServerJuegoMensaje(Personaje personaje);

    Personaje obtener_personaje();

    void imprimir_mensaje();

    ~ServerJuegoMensaje();
};

#endif
