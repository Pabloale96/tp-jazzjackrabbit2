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
    std::vector<Frame>& frames;
    std::vector<Frame>::iterator it;


public:
    explicit PersonajeGui(ClaseTexturas&, int, int, std::vector<Frame>&);
    ~PersonajeGui();
    virtual void show(int);
    virtual void setFrames(int);
};

class SpazGui: public PersonajeGui {
private:
public:
    explicit SpazGui(ClaseTexturas&, int, int, std::vector<Frame>&);
    ~SpazGui();

    void show(int) override;
    virtual void setFrames(int) override;
};


class JazzGui: public PersonajeGui {
private:
public:
    explicit JazzGui(ClaseTexturas&, int, int, std::vector<Frame>&);
    ~JazzGui();

    void show(int) override;
    virtual void setFrames(int) override;
};

class LoriGui: public PersonajeGui {
private:
public:
    explicit LoriGui(ClaseTexturas&, int, int, std::vector<Frame>&);
    ~LoriGui();

    void show(int) override;
    virtual void setFrames(int) override;
};
#endif
