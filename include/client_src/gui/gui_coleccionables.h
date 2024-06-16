#ifndef COLLECTIONS_H
#define COLLECTIONS_H

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

class Collecionables {
protected:
    int pos_x;
    int pos_y;
    int speed;
    Animacion animacion;
    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;


public:
    Collecionables(int, int);
    ~Collecionables();
    void show();
};

class Municion: public Collecionables {
private:
public:
    Municion(int, int);
    ~Municion();

};

class Zanahoria: public Collecionables {
private:
public:
    Zanahoria(int, int);
    ~Zanahoria();
};

class Moneda: public Collecionables {
private:
public:
    Moneda(int, int);
    ~Moneda();
};

class Gema: public Collecionables {
private:
public:
    Gema(int, int);
    ~Gema();
};
#endif
