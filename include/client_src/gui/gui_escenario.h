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
    Renderer& renderer;
    Surface beach{Surface(
            IMG_PATH
            "/beach.png")};  // inicializo cualquier cosa en total se pisa a crear un personaje
    Texture sprites{Texture(
            renderer,
            beach.SetColorKey(true, SDL_MapRGB(beach.Get()->format, 87, 0,
                                               203)))};  // inicializo cualquier cosa en total se
                                                         // pisa a crear un personaje


    std::vector<PlatformGui> platforms;

public:
    explicit Escenario(Renderer&);
    ~Escenario();

    void show(int dif_x, int dif_y);
};

#endif
