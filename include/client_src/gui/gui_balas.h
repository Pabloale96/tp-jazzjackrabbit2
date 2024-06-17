#ifndef BALAS_H
#define BALAS_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_animaciones.h"
#include "gui_clase_texturas.h"
#include "gui_defines_frames.h"
#include "gui_frame.h"
#include "msgToSent.h"


using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;
using SDL2pp::Window;

class BalasGui {
protected:
    int pos_x;
    int pos_y;
    int speed = 5;
    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;
    Animacion animacion;


public:
    BalasGui(std::shared_ptr<std::vector<Frame>>, int, int);
    ~BalasGui();
    void show();
};

#endif
