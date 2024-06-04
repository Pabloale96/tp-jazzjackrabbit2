#include "../../include/client_src/gui/gui_personaje.h"

PersonajeGui::PersonajeGui(ClaseTexturas& texturas): texturas(texturas), animacion() {}

PersonajeGui::~PersonajeGui(){}

void PersonajeGui::show(int posx,int posy,int animacion){}


SpazGui::SpazGui(ClaseTexturas& texturas): PersonajeGui(texturas) {}

SpazGui::~SpazGui(){}

void SpazGui::show(int posx,int posy,int animacion_actual){
    switch (animacion_actual)
    {
        case ANI_STAND:
            animacion.setFlip(false);
            animacion.run(posx,posy,texturas.findFrame(std::string(SPAZ_STAND)));
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            animacion.run(posx,posy,texturas.findFrame(std::string(SPAZ_WALK)));
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            animacion.run(posx,posy,texturas.findFrame(std::string(SPAZ_WALK)));
            break;
        
        default:
            break;
    }
}

JazzGui::JazzGui(ClaseTexturas& texturas): PersonajeGui(texturas) {}

JazzGui::~JazzGui(){}

void JazzGui::show(int posx,int posy,int animacion_actual){

    switch (animacion_actual)
    {
        case ANI_STAND:
            animacion.setFlip(false);
            animacion.run(posx,posy,texturas.findFrame(std::string(JAZZ_STAND)));
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            animacion.run(posx,posy,texturas.findFrame(std::string(JAZZ_WALK)));
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            animacion.run(posx,posy,texturas.findFrame(std::string(JAZZ_WALK)));
            break;
        
        default:
            break;
    }
}

LoriGui::LoriGui(ClaseTexturas& texturas): PersonajeGui(texturas) {}

LoriGui::~LoriGui(){}

void LoriGui::show(int posx,int posy,int animacion_actual){
    switch (animacion_actual)
    {
        case ANI_STAND:
            animacion.setFlip(false);
            animacion.run(posx,posy,texturas.findFrame(std::string(LORI_STAND)));
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            animacion.run(posx,posy,texturas.findFrame(std::string(LORI_WALK)));
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            animacion.run(posx,posy,texturas.findFrame(std::string(LORI_WALK)));
            break;
        
        default:
            break;
    }
}