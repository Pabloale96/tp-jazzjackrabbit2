#ifndef __CLIENT_GAME_RESPUESTA_H__
#define __CLIENT_GAME_RESPUESTA_H__

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

struct Respuesta {
    uint8_t estado_de_la_partida;
    uint16_t id_personaje;
    uint16_t posicion_x;
    uint16_t posicion_y;
    uint16_t puntos;
    uint16_t vida;
    uint16_t municion;
    std::string nombre_arma;

    Respuesta(uint8_t estado_de_la_partida, uint16_t id_personaje, uint16_t posicion_x, uint16_t posicion_y, uint16_t puntos,
              uint16_t vida, uint16_t municion, const std::string& nombre_arma):
            estado_de_la_partida(estado_de_la_partida),
            id_personaje(id_personaje),
            posicion_x(posicion_x),
            posicion_y(posicion_y),
            puntos(puntos),
            vida(vida),
            municion(municion),
            nombre_arma(nombre_arma) {}
    
    uint8_t obtnener_estado_de_la_partida() {
        return estado_de_la_partida;
    }
};

class ClientGameRespuesta {
private:
    std::vector<Respuesta> estado_juego;

public:
    ClientGameRespuesta();

    void agregar_respuesta(Respuesta& respuesta);

    uint8_t obtener_estado_de_la_partida();

    void imprimir_respuesta();
    
    ~ClientGameRespuesta();
};

#endif
