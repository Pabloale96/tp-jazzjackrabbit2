#include "../../include/client_src/gui/gui_personaje.h"

PersonajeGui::PersonajeGui(ClaseTexturas& texturas, int posx, int posy, std::vector<Frame>& frames):
        texturas(texturas), pos_x(posx), pos_y(posy), frames(frames) {
    it = frames.begin();
}

PersonajeGui::~PersonajeGui() {}

void PersonajeGui::show(int animacion) {}

void PersonajeGui::setFrames(int animacion_actual) {}

SpazGui::SpazGui(ClaseTexturas& texturas, int posx, int posy, std::vector<Frame>& frames):
        PersonajeGui(texturas, posx, posy, frames) {}

SpazGui::~SpazGui() {}

void SpazGui::show(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);j
            animacion.run(pos_x, pos_y,5, frames, it);
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y,5, frames, it);
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y,5, frames, it);
            break;
        case ANI_SALTAR:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y,5, frames, it);
            break;
        default:
            break;
    }
}

void SpazGui::setFrames(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            frames = std::ref(texturas.findFrame(std::string(SPAZ_STAND)));
            it = frames.begin();
            break;
        case ANI_MOVER_IZQUIERDA:
        case ANI_MOVER_DERECHA:
            frames = std::ref(texturas.findFrame(std::string(SPAZ_WALK)));
            it = frames.begin();
            break;
        case ANI_SALTAR:
            frames = std::ref(texturas.findFrame(std::string(SPAZ_JUMP)));
            it = frames.begin();
            break;
        default:
            break;
    }
}

JazzGui::JazzGui(ClaseTexturas& texturas, int posx, int posy, std::vector<Frame>& frames):
        PersonajeGui(texturas, posx, posy, frames) {}

JazzGui::~JazzGui() {}

void JazzGui::show(int animacion_actual) {

    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y,2, frames, it);
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y,2, frames, it);
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y,2, frames, it);
            break;
        case ANI_SALTAR:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y,2, frames, it);
            break;
        default:
            break;
    }
}

void JazzGui::setFrames(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            frames = std::ref(texturas.findFrame(std::string(JAZZ_STAND)));
            it = frames.begin();
            break;
        case ANI_MOVER_IZQUIERDA:
        case ANI_MOVER_DERECHA:
            frames = std::ref(texturas.findFrame(std::string(JAZZ_WALK)));
            it = frames.begin();
            break;
        case ANI_SALTAR:
            frames = std::ref(texturas.findFrame(std::string(JAZZ_JUMP)));
            it = frames.begin();
            break;
        default:
            break;
    }
}

LoriGui::LoriGui(ClaseTexturas& texturas, int posx, int posy, std::vector<Frame>& frames):
        PersonajeGui(texturas, posx, posy, frames) {}

LoriGui::~LoriGui() {}

void LoriGui::show(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y,2, frames, it);
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            animacion.run(pos_x, pos_y,2, frames, it);
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y,2, frames, it);
            break;
        case ANI_SALTAR:
            animacion.setFlip(true);
            animacion.run(pos_x, pos_y,2, frames, it);
            break;
        default:
            break;
    }
}


void LoriGui::setFrames(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            frames = std::ref(texturas.findFrame(std::string(LORI_STAND)));
            it = frames.begin();
            break;
        case ANI_MOVER_IZQUIERDA:
        case ANI_MOVER_DERECHA:
            frames = std::ref(texturas.findFrame(std::string(LORI_WALK)));
            it = frames.begin();
            break;
        case ANI_SALTAR:
            frames = std::ref(texturas.findFrame(std::string(LORI_JUMP)));
            it = frames.begin();
            break;
        default:
            break;
    }
}
