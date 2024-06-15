#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <exception>
#include <iostream>

#include <SDL2pp/SDL2pp.hh>
#include <arpa/inet.h>  // para usar htons()

#include "defines_msg.h"
#include "gui_animaciones.h"
#include "protocol_utils.h"

class EnemigosGui {
private:
    uint16_t id;
    uint16_t tipo;
    uint16_t pos_x;
    uint16_t pos_y;
    Animacion enemigo;

public:
    explicit EnemigosGui(uint16_t*);
    ~EnemigosGui();
    uint16_t get_id_enemigo() { return id; }
};

#endif
