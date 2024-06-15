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
#include "msgToSent.h"


using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;
using SDL2pp::Window;

class PersonajeGui {
protected:
    std::shared_ptr<ClaseTexturas> texturas;
    int pos_x;
    int pos_y;
    int speed=0;
    Animacion animacion;
    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;


public:
    explicit PersonajeGui(std::shared_ptr<ClaseTexturas>, int, int, int, std::shared_ptr<std::vector<Frame>>&);
    PersonajeGui(msgPersonaje&);
    int obtener_posicion_x() {return pos_x;}
    int obtener_posicion_y() {return pos_y;}
    ~PersonajeGui();
    void show();
    virtual void setFrames(int,int);
};

class SpazGui: public PersonajeGui {
private:
public:
    explicit SpazGui(std::shared_ptr<ClaseTexturas>, int, int, int, std::shared_ptr<std::vector<Frame>>&);
    SpazGui(msgPersonaje&);
    ~SpazGui();

    void setFrames(int,int) override;
};

class JazzGui: public PersonajeGui {
private:
public:
    explicit JazzGui(std::shared_ptr<ClaseTexturas>, int, int, int, std::shared_ptr<std::vector<Frame>>&);
    ~JazzGui();
    JazzGui(msgPersonaje&);
    void setFrames(int,int) override;
};

class LoriGui: public PersonajeGui {
private:
public:
    explicit LoriGui(std::shared_ptr<ClaseTexturas>, int, int, int, std::shared_ptr<std::vector<Frame>>&);
    ~LoriGui();
    LoriGui(msgPersonaje&);
    void setFrames(int,int) override;
};
#endif
