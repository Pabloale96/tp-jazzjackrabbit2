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

class Colecionables {
protected:
    ClaseTexturas& texturas;
    int pos_x;
    int pos_y;
    int speed;
    Animacion animacion;
    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;

public:
    Colecionables(ClaseTexturas& texturas, int x, int y);
    ~Colecionables();
    void show();
};

class MunicionGui: public Colecionables {
private:
public:
    MunicionGui(ClaseTexturas& texturas, int x, int y);
    ~MunicionGui();
};

class Zanahoria: public Colecionables {
private:
public:
    Zanahoria(ClaseTexturas& texturas, int x, int y);
    ~Zanahoria();
};

class Moneda: public Colecionables {
private:
public:
    Moneda(ClaseTexturas& texturas, int x, int y);
    ~Moneda();
};

class Gema: public Colecionables {
private:
public:
    Gema(ClaseTexturas& texturas, int x, int y);
    ~Gema();
};
#endif
