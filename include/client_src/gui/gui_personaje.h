#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_animaciones.h"
#include "gui_clase_texturas.h"
#include "gui_defines_frames.h"
#include "gui_frame.h"


using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;
using SDL2pp::Window;

class PersonajeGui {
protected:
    ClaseTexturas& texturas;
    Animacion animacion;

public:
    explicit PersonajeGui(ClaseTexturas&);
    ~PersonajeGui();
    virtual void show(int, int, int);
};

class SpazGui: public PersonajeGui {
private:
public:
    explicit SpazGui(ClaseTexturas&);
    ~SpazGui();

    void show(int, int, int);
};


class JazzGui: public PersonajeGui {
private:
public:
    explicit JazzGui(ClaseTexturas&);
    ~JazzGui();

    void show(int, int, int);
};

class LoriGui: public PersonajeGui {
private:
public:
    explicit LoriGui(ClaseTexturas&);
    ~LoriGui();

    void show(int, int, int);
};
#endif
