#include "../../include/client_src/gui/gui_personaje.h"

PersonajeGui::PersonajeGui(ClaseTexturas& texturas, int posx, int posy, std::shared_ptr<std::vector<Frame>>& frames):
        texturas(texturas), pos_x(posx), pos_y(posy), frames(frames) {
    it = frames->begin();
}

PersonajeGui::~PersonajeGui() {}

void PersonajeGui::show(int animacion) {}

void PersonajeGui::setFrames(int animacion_actual) {}

SpazGui::SpazGui(ClaseTexturas& texturas, int posx, int posy, std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, frames) {}

SpazGui::~SpazGui() {}

void SpazGui::show(int animacion_actual) {
    animacion.run(pos_x, pos_y, frames->size(), frames, it);
}

void SpazGui::setFrames(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_STAND));
            it = frames->begin();
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_WALK));
            it = frames->begin();
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            frames = texturas.findFrame(std::string(SPAZ_WALK));
            it = frames->begin();
            break;
        case ANI_SALTAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_JUMP));
            it = frames->begin();
            break;
        case ANI_DISPARAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_SHOOT));
            it = frames->begin();
            break;
        case ANI_RUN_IZQUIERDA:
            animacion.setFlip(true);
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            break;
        case ANI_RUN_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            break;
        case ANI_ESPECIAL:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_SPECIAL));
            it = frames->begin();
            break;
        default:
            break;
    }
}

JazzGui::JazzGui(ClaseTexturas& texturas, int posx, int posy, std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, frames) {}

JazzGui::~JazzGui() {}

void JazzGui::show(int animacion_actual) {
    animacion.run(pos_x, pos_y, frames->size(), frames, it);
}

void JazzGui::setFrames(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_STAND));
            it = frames->begin();
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_WALK));
            it = frames->begin();
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_WALK));
            it = frames->begin();
            break;
        case ANI_SALTAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_JUMP));
            it = frames->begin();
            break;
        case ANI_DISPARAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_SHOOT));
            it = frames->begin();
            break;
        case ANI_RUN_IZQUIERDA:
            animacion.setFlip(true);
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            break;
        case ANI_RUN_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            break;
        case ANI_ESPECIAL:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_SPECIAL));
            it = frames->begin();
            break;
        default:
            break;
    }
}

LoriGui::LoriGui(ClaseTexturas& texturas, int posx, int posy, std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, frames) {}

LoriGui::~LoriGui() {}

void LoriGui::show(int animacion_actual) {
    animacion.run(pos_x, pos_y, frames->size(), frames, it);
}


void LoriGui::setFrames(int animacion_actual) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_STAND));
            it = frames->begin();
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_WALK));
            it = frames->begin();
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_WALK));
            it = frames->begin();
            break;
        case ANI_SALTAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_JUMP));
            it = frames->begin();
            break;
        case ANI_DISPARAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_SHOOT));
            it = frames->begin();
            break;
        case ANI_RUN_IZQUIERDA:
            animacion.setFlip(true);
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            break;
        case ANI_RUN_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            break;
        case ANI_ESPECIAL:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_SPECIAL));
            it = frames->begin();
            break;
        default:
            break;
    }
}
