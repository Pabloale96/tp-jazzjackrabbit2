#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "animaciones.h"
#include "frame.h"
#include "clase_texturas.h"

using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;
using SDL2pp::Window;

class PersonajeGui {
    protected:
        ClaseTexturas & texturas;
        Animacion animacion;  
    public:
        PersonajeGui(ClaseTexturas & texturas):texturas(texturas),animacion(){}
        ~PersonajeGui(){}
        virtual void show(int){}
};

class SpazGui : public PersonajeGui {
    private:
        
    public:
        SpazGui(ClaseTexturas & texturas):PersonajeGui(texturas){}
        ~SpazGui(){}
        
        void show(int){}
};


class JazzGui : public PersonajeGui {
    private:        
        
    public:
        JazzGui(ClaseTexturas & texturas):PersonajeGui(texturas){}
        ~JazzGui(){}
        
        void show(int){}
};

class LoriGui : public PersonajeGui {
    private:
             
    public:
        LoriGui(ClaseTexturas & texturas):PersonajeGui(texturas){}
        ~LoriGui(){}
        
        void show(int){}
};
#endif
