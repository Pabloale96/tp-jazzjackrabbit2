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
    int pos_x;
    int pos_y;
    Animacion animacion;


public:
    explicit PersonajeGui(ClaseTexturas&, int, int);
    PersonajeGui(int, int);
    ~PersonajeGui();
    virtual void show(int);
};

class SpazGui: public PersonajeGui {
private:
public:
    explicit SpazGui(ClaseTexturas&, int, int);
    SpazGui(int, int);
    ~SpazGui();

    void show(int) override;
};


class JazzGui: public PersonajeGui {
private:
public:
    explicit JazzGui(ClaseTexturas&, int, int);
    JazzGui(int, int);
    ~JazzGui();

    void show(int) override;
};

class LoriGui: public PersonajeGui {
private:
public:
    explicit LoriGui(ClaseTexturas&, int, int);
    LoriGui(int, int);
    ~LoriGui();

    void show(int) override;
};
#endif
