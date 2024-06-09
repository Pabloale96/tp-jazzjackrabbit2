#include "../../include/client_src/gui/gui_personaje.h"

PersonajeGui::PersonajeGui(ClaseTexturas& texturas, int posx, int posy):
        texturas(texturas), pos_x(posx), pos_y(posy) {}

PersonajeGui::~PersonajeGui() {}

void PersonajeGui::show(int animacion) {}


SpazGui::SpazGui(ClaseTexturas& texturas, int posx, int posy): PersonajeGui(texturas, posx, posy) {}

SpazGui::~SpazGui() {}

void SpazGui::show(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(SPAZ_STAND)));
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(SPAZ_WALK)));
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(SPAZ_WALK)));
            break;
        case ANI_SALTAR:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(SPAZ_JUMP)));
            break;
        default:
            break;
    }
}

JazzGui::JazzGui(ClaseTexturas& texturas, int posx, int posy): PersonajeGui(texturas, posx, posy) {}

JazzGui::~JazzGui() {}

void JazzGui::show(int animacion_actual) {

    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(JAZZ_STAND)));
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(JAZZ_WALK)));
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(JAZZ_WALK)));
            break;
        case ANI_SALTAR:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(JAZZ_JUMP)));
            break;
        default:
            break;
    }
}

LoriGui::LoriGui(ClaseTexturas& texturas, int posx, int posy): PersonajeGui(texturas, posx, posy) {}

LoriGui::~LoriGui() {}

void LoriGui::show(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(LORI_STAND)));
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(LORI_WALK)));
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(LORI_WALK)));
            break;
        case ANI_SALTAR:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y, texturas.findFrame(std::string(LORI_JUMP)));
            break;
        default:
            break;
    }
}
