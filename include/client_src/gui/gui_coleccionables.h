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

class ColecionablesGui {
protected:
    ClaseTexturas& texturas;
    int pos_x;
    int pos_y;
    int speed;
    Animacion animacion;
    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;

public:
    ColecionablesGui(ClaseTexturas& texturas, int x, int y);
    ColecionablesGui(ClaseTexturas& texturas, msgColecionables& msg);
    ~ColecionablesGui();
    void show();
    void setPosicion(float x, float y);
    float obtener_posicion_x();
    float obtener_posicion_y();
};

class MunicionGui: public ColecionablesGui {
private:
public:
    MunicionGui(ClaseTexturas& texturas, int x, int y);
    ~MunicionGui();
};

class ZanahoriaGui: public ColecionablesGui {
private:
public:
    ZanahoriaGui(ClaseTexturas& texturas, int x, int y);
    ZanahoriaGui(ClaseTexturas& texturas, msgColecionables& msg);
    ~ZanahoriaGui();
};

class MonedaGui: public ColecionablesGui {
private:
public:
    MonedaGui(ClaseTexturas& texturas, int x, int y);
    MonedaGui(ClaseTexturas& texturas, msgColecionables& msg);
    ~MonedaGui();
};

class GemaGui: public ColecionablesGui {
private:
public:
    GemaGui(ClaseTexturas& texturas, int x, int y);
    GemaGui(ClaseTexturas& texturas, msgColecionables& msg);
    ~GemaGui();
};
#endif
