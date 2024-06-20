#ifndef PLATFORM_H
#define PLATFORM_H

#include <exception>
#include <iostream>
#include <memory>

#include "defines_msg.h"
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

#endif
