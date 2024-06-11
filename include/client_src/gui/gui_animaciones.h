#ifndef ANIMACIONES_H
#define ANIMACIONES_H

#include <exception>
#include <iostream>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_frame.h"

class Animacion {
private:
    bool flip = false;

public:
    Animacion();
    ~Animacion();

    void run(int pos_x, int pos_y,std::vector<Frame>& frames, std::vector<Frame>::iterator & it);
    void setFlip(bool);
};

#endif
