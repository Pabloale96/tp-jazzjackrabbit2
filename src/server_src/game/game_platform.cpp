#include "../../include/server_src/game/game_platform.h"

Platform::Platform(uint16_t pos_x, uint16_t pos_y, uint16_t rotate, uint16_t width, uint16_t height,
                   uint16_t type, bool flip):
        pos_x(pos_x), pos_y(pos_y), rotate(rotate), width(width), height(height), type(type), flip(flip) {}
Platform::~Platform() {}

uint16_t Platform::obtener_posicion_x() const { return pos_x; }
uint16_t Platform::obtener_posicion_y() const { return pos_y; }
uint16_t Platform::obtener_tipo() const { return type; }
uint16_t Platform::obtener_rotate() const { return rotate; }
uint16_t Platform::obtener_width() const { return width; }
uint16_t Platform::obtener_height() const { return height; }
bool Platform::obtener_flip() const { return flip; }
