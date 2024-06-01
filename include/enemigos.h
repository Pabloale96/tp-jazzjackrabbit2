#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <exception>
#include <iostream>

#include <SDL2pp/SDL2pp.hh>

#include "animaciones.h"

class Enemigos {
private:
    Texture sprites;
    Animacion enemigo;

public:
    Enemigos();
    ~Enemigos();
};

#endif
