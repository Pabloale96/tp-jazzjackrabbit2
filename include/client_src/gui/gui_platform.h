#ifndef GUI_PLATFORM_H
#define GUI_PLATFORM_H

#include <exception>
#include <iostream>
#include <memory>

#include <SDL2pp/SDL2pp.hh>

#include "../../common_src/defines_msg.h"
#include "../../common_src/msgToSent.h"

#include "gui_clase_texturas.h"
#include "gui_frame.h"

using SDL2pp::Renderer;
using SDL2pp::Texture;

class PlatformGui {
private:
    int pos_x;
    int pos_y;
    bool flip = false;
    int type = 0;
    int height;
    int width;
    int w_window;
    int h_window;
    std::shared_ptr<Frame> platform;

public:
    PlatformGui(const msgPlataforma&);
    ~PlatformGui();

    void show(int dif_x, int dif_y);
    float rotateToFloat();
    void setFrame(std::shared_ptr<Frame>&,int ,int );

    int getW() {return width;}
    int getH() {return height;}
    int getX() {return pos_x;}
    int getY() {return pos_y;}
};

#endif
