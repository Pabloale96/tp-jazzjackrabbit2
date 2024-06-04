#ifndef GUI_PLATFORM_H
#define GUI_PLATFORM_H

#include <exception>
#include <iostream>
#include <memory>

#include <SDL2pp/SDL2pp.hh>

#include "gui_frame.h"
#include "../../common_src/defines_platform.h"

using SDL2pp::Renderer;
using SDL2pp::Texture;

class PlatformGui {
private:
    Renderer& renderer;
    Texture& sprites;
    int pos_x;
    int pos_y;
    int rotate = ROTATE_0;
    bool flip = false;
    Frame platform{Frame(renderer, sprites, 0, 2496, 500, 27)};

public:
    PlatformGui(Renderer&, Texture&, int, int);
    ~PlatformGui();

    void show(int, int);
};

#endif
