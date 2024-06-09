#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_frame.h"
#include "gui_platform.h"

using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;

class Escenario {
private:
    std::vector<PlatformGui>& platforms;

public:
    explicit Escenario(std::vector<PlatformGui>&);
    ~Escenario();

    void show();
};

#endif
