#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <exception>
#include <memory>

#include <SDL2pp/SDL2pp.hh>

#include "animaciones.h"

using namespace SDL2pp;
class Personaje {
    protected:
        Renderer & renderer;
        Surface spaz{Surface(IMG_PATH "/spaz.png")}; //inicializo cualquier cosa en total se pisa a crear un personaje
        Texture sprites{Texture(renderer, spaz.SetColorKey(true, SDL_MapRGB(spaz.Get()->format, 44, 102, 150)))};//inicializo cualquier cosa en total se pisa a crear un personaje
        Animacion movimiento{Animacion(std::ref(renderer),std::ref(sprites))};//inicializo cualquier cosa en total se pisa a crear un personaje
    public:
        Personaje(Renderer & renderer):renderer(renderer){}
        ~Personaje(){}
        virtual void animacion(int){}
};

class Spaz : public Personaje {
    private:
        Surface spaz{Surface(IMG_PATH "/spaz.png")};
        Texture sprites{Texture(renderer, spaz.SetColorKey(true, SDL_MapRGB(spaz.Get()->format, 44, 102, 150)))};
        AnimacionDerecha movDer{AnimacionDerecha(std::ref(renderer),std::ref(sprites))};
        //Animacion movimiento{Animacion(std::ref(renderer),std::ref(sprites))};
        
    public:
        Spaz(Renderer &);
        ~Spaz();
        void animacion(int);
};


#endif