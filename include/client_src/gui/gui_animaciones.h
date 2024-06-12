#ifndef ANIMACIONES_H
#define ANIMACIONES_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_frame.h"

class Animacion {
private:
    bool flip = false;
    int contador = 0;

public:
    Animacion();
    ~Animacion();

    void run(int pos_x, int pos_y, int speed, std::shared_ptr<std::vector<Frame>> frames,
             std::vector<Frame>::iterator& it);
    void setFlip(bool);
};

#endif
