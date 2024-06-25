#ifndef VIDAGUI_H
#define VIDAGUI_H

#include <exception>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "defines_msg.h"
#include "gui_clase_texturas.h"
#include "gui_frame.h"
#include "msgToSent.h"
#include "protocol_utils.h"

class VidaGui {
protected:
    ClaseTexturas& texturas;

    uint16_t vida = 0;
    uint16_t tipo = 0;

public:
    explicit VidaGui(ClaseTexturas& texturas, uint16_t vida, uint8_t tipo);
    ~VidaGui();

    void run();
    void show_icon();
    void show_vida();
    void setVida(uint16_t);
    uint16_t getVida() const;
};
#endif
