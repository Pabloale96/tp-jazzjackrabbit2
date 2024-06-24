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
    ClaseTexturas& texturas;
    float pos_x;
    float pos_y;
    int speed = 5;
    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;
    Animacion animacion;


public:
    BalasGui(ClaseTexturas&, msgBalas&);
    ~BalasGui();
    void show();
    void setPosicion(float, float);
    float obtener_posicion_x();
    float obtener_posicion_y();
};

class BalasGui1: public BalasGui {
protected:
public:
    BalasGui1(ClaseTexturas&, msgBalas&);
    ~BalasGui1();
};


class BalasGui2: public BalasGui {
protected:
public:
    BalasGui2(ClaseTexturas&, msgBalas&);
    ~BalasGui2();
};


#endif
