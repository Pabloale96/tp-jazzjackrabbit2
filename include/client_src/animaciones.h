#ifndef ANIMACIONES_H
#define ANIMACIONES_H

#include <exception>
#include <iostream>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "frame.h"

using SDL2pp::Renderer;
using SDL2pp::Texture;

class Animacion {
private:
    bool flip = false;
    int scr_x = 0;

public:
    Animacion();
    ~Animacion();

    void run(int, int, std::vector<Frame>&);
    void setFlip(bool);
};

#endif
