#ifndef GUI_PLATFORM_H
#define GUI_PLATFORM_H

#include <exception>
#include <iostream>
#include <memory>

#include <SDL2pp/SDL2pp.hh>

#include "../../common_src/defines_msg.h"
#include "gui_clase_texturas.h"
#include "../../common_src/msgToSent.h"

#include "gui_frame.h"

using SDL2pp::Renderer;
using SDL2pp::Texture;

class PlatformGui {
private:
    ClaseTexturas& texturas;
    int pos_x;
    int pos_y;
    int rotate;
    bool flip = false;
    int type;
    int height;
    int width;
    //Frame platform{Frame(renderer, sprites, 0, 2496, 500, 27)};

public:
    PlatformGui(ClaseTexturas&, int, int,int,bool,int,int,int);
    PlatformGui(ClaseTexturas&, const msgPlataforma&);
    ~PlatformGui();

    void show(int, int);
};

#endif
