#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_frame.h"
#include "gui_platform.h"
#include "vector_monitor.h"

using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;

class Escenario {
private:
    VectorMonitor<std::shared_ptr<PlatformGui>>& platforms;

public:
    explicit Escenario(VectorMonitor<std::shared_ptr<PlatformGui>>&);
    ~Escenario();

    void show(int dif_x, int dif_y);
};

#endif
