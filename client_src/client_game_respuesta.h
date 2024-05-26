#ifndef __CLIENT_GAME_RESPUESTA_H__
#define __CLIENT_GAME_RESPUESTA_H__

#include <cstdint>
#include <iostream>
#include <vector>

struct Respuesta {
    uint16_t id_personaje;
    uint16_t posicion_x;
    uint16_t posicion_y;

    Respuesta(uint16_t id_personaje, uint16_t posicion_x, uint16_t posicion_y):
            id_personaje(id_personaje), posicion_x(posicion_x), posicion_y(posicion_y) {}
};

class ClientGameRespuesta {
private:
    std::vector<Respuesta> estado_juego;

public:
    ClientGameRespuesta();
    void agregar_respuesta(Respuesta& respuesta);
    void imprimir_respuesta();
    ~ClientGameRespuesta();
};

#endif
