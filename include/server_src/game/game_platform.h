#ifndef PLATFORM_H
#define PLATFORM_H

#include <exception>
#include <iostream>
#include <memory>

#include "defines_msg.h"
#include "game_posicion.h"
#include "protocol_utils.h"

class Platform {
private:
    uint16_t pos_x;
    uint16_t pos_y;
    uint16_t width = 0;
    uint16_t height = 1;
    uint8_t type = 0;
    bool flip = false;

public:
    Platform(uint16_t, uint16_t, uint16_t, uint16_t, uint8_t, bool);
    ~Platform();

    uint16_t obtener_posicion_x() const;
    uint16_t obtener_posicion_y() const;
    uint8_t obtener_tipo() const;
    uint16_t obtener_width() const;
    uint16_t obtener_height() const;
    uint8_t obtener_flip() const;

    // Funciones para detectar colisiones
    uint16_t getBottom() const;
    uint16_t getTop() const;
    uint16_t getLeft() const;
    uint16_t getRight() const;
    uint8_t getFlip() const;
};

class Plataforma {
private:
    platform tipo_plataforma;
    Posicion vertice_izq_abajo;
    Posicion vertice_izq_arriba;
    Posicion vertice_der_abajo;
    Posicion vertice_der_arriba;
    Posicion centro;
    uint8_t angulo;

public:
    Plataforma(platform tipo_plataforma, float x_ver_izq_abajo, float y_ver_izq_abajo,
               float x_ver_izq_arriba, float y_ver_izq_arriba, float x_ver_der_abajo,
               float y_ver_der_abajo, float x_ver_der_arriba, float y_ver_der_arriba,
               uint8_t angulo):
            tipo_plataforma(tipo_plataforma),
            vertice_izq_abajo(x_ver_izq_abajo, y_ver_izq_abajo),
            vertice_izq_arriba(x_ver_izq_arriba, y_ver_izq_arriba),
            vertice_der_abajo(x_ver_der_abajo, y_ver_der_abajo),
            vertice_der_arriba(x_ver_der_arriba, y_ver_der_arriba),
            centro((x_ver_izq_abajo + x_ver_der_arriba) / 2,
                   (y_ver_izq_abajo + y_ver_der_arriba) / 2),
            angulo(angulo) {}

    ~Plataforma() {}

    platform obtener_tipo_plataforma() const { return tipo_plataforma; }
    Posicion obtener_vertice_izq_abajo() const { return vertice_izq_abajo; }
    Posicion obtener_vertice_izq_arriba() const { return vertice_izq_arriba; }
    Posicion obtener_vertice_der_abajo() const { return vertice_der_abajo; }
    Posicion obtener_vertice_der_arriba() const { return vertice_der_arriba; }
    Posicion obtener_centro() const { return centro; }
    uint8_t obtener_angulo() const { return angulo; }
};

#endif
