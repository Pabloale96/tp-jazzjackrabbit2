#ifndef PLATFORM_H
#define PLATFORM_H

#include <cmath>
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
               uint8_t angulo);

    platform obtener_tipo_plataforma() const;
    Posicion obtener_vertice_izq_abajo() const;
    Posicion obtener_vertice_izq_arriba() const;
    Posicion obtener_vertice_der_abajo() const;
    Posicion obtener_vertice_der_arriba() const;
    float obtener_borde_izquierdo() const;
    float obtener_borde_derecho() const;
    float obtener_borde_superior() const;
    float obtener_borde_inferior() const;
    Posicion obtener_centro() const;
    uint8_t obtener_angulo() const;

    void chequear_colisiones(float prox_pos_x, float prox_pos_y, bool& colisiona_en_x, bool& colisiona_en_y) const;
    bool estoy_adentro_de_la_plataforma(float prox_pos_x, float prox_pos_y) const;

    bool es_plataforma_cercana_en_y_abajo(float y) const;
    bool es_plataforma_cercana_en_y_arriba(float y) const;
    bool es_plataforma_cercana_en_x_izquierda(float x) const;
    bool es_plataforma_cercana_en_x_derecha(float x) const;

    ~Plataforma();
};

#endif
