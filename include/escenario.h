#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <iostream>
#include <exception>
#include <memory>

#include <SDL2pp/SDL2pp.hh>

#include "frame.h"
#include "platform.h"

using namespace SDL2pp;
class Escenario {
private:
    Renderer & renderer;
    Surface beach{Surface(IMG_PATH "/beach.png")}; //inicializo cualquier cosa en total se pisa a crear un personaje
    Texture sprites{Texture(renderer, beach.SetColorKey(true, SDL_MapRGB(beach.Get()->format, 87, 0, 203)))};//inicializo cualquier cosa en total se pisa a crear un personaje


    std::vector<Platform> platforms;
    Platform platform_7{Platform(renderer,sprites,renderer.GetOutputWidth()/2-21+700,renderer.GetOutputHeight()/2-21+75)};
    Platform platform_6{Platform(renderer,sprites,renderer.GetOutputWidth()/2-21+600,renderer.GetOutputHeight()/2-21+75)};
    Platform platform_5{Platform(renderer,sprites,renderer.GetOutputWidth()/2-21+500,renderer.GetOutputHeight()/2-21+75)};
    Platform platform_4{Platform(renderer,sprites,renderer.GetOutputWidth()/2-21+400,renderer.GetOutputHeight()/2-21+75)};
    Platform platform_3{Platform(renderer,sprites,renderer.GetOutputWidth()/2-21+300,renderer.GetOutputHeight()/2-21+75)};
    Platform platform_2{Platform(renderer,sprites,renderer.GetOutputWidth()/2-21+200,renderer.GetOutputHeight()/2-21+75)};
    Platform platform_1{Platform(renderer,sprites,renderer.GetOutputWidth()/2-21+100,renderer.GetOutputHeight()/2-21+75)};
    Platform platform1{Platform(renderer,sprites,renderer.GetOutputWidth()/2-21,renderer.GetOutputHeight()/2-21+75)};
    Platform platform2{Platform(renderer,sprites,renderer.GetOutputWidth()/2-121,renderer.GetOutputHeight()/2-21+75)};
    Platform platform3{Platform(renderer,sprites,renderer.GetOutputWidth()/2-221,renderer.GetOutputHeight()/2-21+75)};
    Platform platform4{Platform(renderer,sprites,renderer.GetOutputWidth()/2-321,renderer.GetOutputHeight()/2-21+75)};
    Platform platform5{Platform(renderer,sprites,renderer.GetOutputWidth()/2-421,renderer.GetOutputHeight()/2-21+75)};
    Platform platform6{Platform(renderer,sprites,renderer.GetOutputWidth()/2-521,renderer.GetOutputHeight()/2-21+75)};
    Platform platform7{Platform(renderer,sprites,renderer.GetOutputWidth()/2-621,renderer.GetOutputHeight()/2-21+75)};

public:
    Escenario(Renderer &);
    ~Escenario();

    void show(int dif_x,int dif_y);
};

#endif