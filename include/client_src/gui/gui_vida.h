#ifndef VIDAGUI_H
#define VIDAGUI_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "defines_msg.h"
#include "gui_frame.h"
#include "gui_clase_texturas.h"
#include "msgToSent.h"
#include "protocol_utils.h"

class VidaGui {
protected:
    ClaseTexturas & texturas;

    uint16_t vida = 0;

    int speed = 0;

    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;

public:
    explicit VidaGui(uint16_t vida, std::shared_ptr<std::vector<Frame>> frame);
    ~VidaGui();

    void run(int speed);
};
#endif
