#ifndef PLATFORM_H
#define PLATFORM_H

#include <exception>
#include <iostream>
#include <memory>

#include "defines_msg.h"

class Platform {
private:
    uint16_t pos_x;
    uint16_t pos_y;
    uint16_t rotate = ROTATE_0;
    uint16_t width=0;
    uint16_t height=0;
    uint16_t type=0;
    
public:
    Platform(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
    ~Platform();

    uint16_t obtener_posicion_x() const;
    uint16_t obtener_posicion_y()const;
    uint16_t obtener_tipo() const;
    uint16_t obtener_rotate() const;
    uint16_t obtener_width() const;
    uint16_t obtener_height() const;
    
};

#endif
