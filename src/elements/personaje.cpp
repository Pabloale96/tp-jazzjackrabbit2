#include <iostream>
#include <exception>

#include <SDL2pp/SDL2pp.hh>
#include "../../include/personaje.h"

Spaz::Spaz(Renderer & renderer):Personaje(renderer){
    sprites.SetBlendMode(SDL_BLENDMODE_BLEND);
}
Spaz::~Spaz(){}

void Spaz::animacion(int animacion){
    switch (animacion)
    {
        /*case 0:
            movimiento.standing();
            break;*/
        case 1:
            movDer.run();
            break;
        /*case 2:
            movimiento.moverIzquierda();
            break;*/
        default:
            break;
    }
}