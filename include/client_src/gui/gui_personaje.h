#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_animaciones.h"
#include "gui_clase_texturas.h"
#include "gui_vida.h"
#include "gui_defines_frames.h"
#include "gui_frame.h"
#include "msgToSent.h"


using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;
using SDL2pp::Window;

class PersonajeGui {
protected:
    ClaseTexturas& texturas;
    float pos_x;
    float pos_y;
    uint8_t tipo;
    int speed = 0;
    uint8_t estado;
    VidaGui vida;
    Animacion animacion;
    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;

public:
    PersonajeGui(ClaseTexturas&, float, float, uint8_t, int, std::shared_ptr<std::vector<Frame>>&);
    explicit PersonajeGui(ClaseTexturas&, msgPersonaje&);
    float obtener_posicion_x() const { return pos_x; }
    float obtener_posicion_y() const { return pos_y; }
    uint8_t obtener_estado_actual() const { return estado; }
    uint8_t obtener_tipo_personaje() const { return tipo; }
    ~PersonajeGui();
    void show(bool con_vida);
    virtual void setFrames();
    void setAnimacion(uint8_t estado, bool flip);
    void setPosicion(float x, float y);
    void actualizar_personaje(const PersonajeGui&);
};

class SpazGui: public PersonajeGui {
private:
public:
    SpazGui(ClaseTexturas&, float, float, uint8_t, int, std::shared_ptr<std::vector<Frame>>&);
    explicit SpazGui(ClaseTexturas&, msgPersonaje&);
    ~SpazGui();

    void setFrames() override;
};

class JazzGui: public PersonajeGui {
private:
public:
    JazzGui(ClaseTexturas&, float, float, uint8_t, int, std::shared_ptr<std::vector<Frame>>&);
    explicit JazzGui(ClaseTexturas&, msgPersonaje&);
    ~JazzGui();

    void setFrames() override;
};

class LoriGui: public PersonajeGui {
private:
public:
    LoriGui(ClaseTexturas&, float, float, uint8_t, int, std::shared_ptr<std::vector<Frame>>&);
    explicit LoriGui(ClaseTexturas&, msgPersonaje&);
    ~LoriGui();

    void setFrames() override;
};
#endif
