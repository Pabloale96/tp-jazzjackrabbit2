#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <exception>
#include <memory>

#include <SDL2pp/SDL2pp.hh>

#include "frame.h"

using namespace SDL2pp;
class Platform {
private:
    Renderer & renderer;
    Texture & sprites;
    int pos_x;
    int pos_y;
    bool flip = false;
    Frame platform{Frame(renderer,sprites,0,2496,500,27)};

public:
    Platform(Renderer &, Texture &,int,int);
    ~Platform();

    void show(int , int );
};

#endif