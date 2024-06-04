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
    PlatformGui platform_7{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 21 + 700,
                                 renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform_6{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 21 + 600,
                                 renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform_5{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 21 + 500,
                                 renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform_4{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 21 + 400,
                                 renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform_3{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 21 + 300,
                                 renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform_2{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 21 + 200,
                                 renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform_1{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 21 + 100,
                                 renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform1{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 21,
                                renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform2{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 121,
                                renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform3{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 221,
                                renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform4{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 321,
                                renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform5{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 421,
                                renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform6{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 521,
                                renderer.GetOutputHeight() / 2 - 21 + 75)};
    PlatformGui platform7{PlatformGui(renderer, sprites, renderer.GetOutputWidth() / 2 - 621,
                                renderer.GetOutputHeight() / 2 - 21 + 75)};

public:
    explicit Escenario(Renderer&);
    ~Escenario();

    void show(int dif_x, int dif_y);
};

#endif
