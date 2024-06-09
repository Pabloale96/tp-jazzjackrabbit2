#ifndef FRAME_H
#define FRAME_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_defines_frames.h"

using SDL2pp::NullOpt;
using SDL2pp::Rect;
using SDL2pp::Renderer;
using SDL2pp::Texture;


class Frame {
private:
    Renderer& renderer;
    Texture& sprite;
    std::vector<int> vec_frames;

public:
    Frame(Renderer&, Texture&);
    Frame(Renderer&, Texture&, int, int, int, int);
    ~Frame();
    void copy(bool, int, int);
    void copy(bool, int, int, int, int);
    void setFrame(int, int, int, int);
    int getX();
    int getY();
    int getW();
    int getH();
    Frame& operator=(const Frame& other);
};

#endif
