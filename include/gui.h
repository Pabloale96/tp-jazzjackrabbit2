#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <exception>

#include <SDL2pp/SDL2pp.hh>


class Gui {
private:
    //Escenario escenario;
    //Personaje personaje;
    //Enemigos enemigos;
    // Background background; objeto del fondo, por ahora no es necesario.
public:
    Gui();
    ~Gui();
    void run();
};

#endif