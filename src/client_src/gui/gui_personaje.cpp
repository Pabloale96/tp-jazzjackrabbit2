#include "../../include/client_src/gui/gui_personaje.h"

PersonajeGui::PersonajeGui(ClaseTexturas& texturas, int posx, int posy, int speed,
                           std::shared_ptr<std::vector<Frame>>& frames):
        texturas(texturas), pos_x(posx), pos_y(posy), speed(speed), frames(frames) {
    it = frames->begin();
}

PersonajeGui::~PersonajeGui() {}

void PersonajeGui::show() {
    animacion.run(pos_x, pos_y, speed, frames, it);
}

void PersonajeGui::setFrames(int animacion_actual,int spe) {}

SpazGui::SpazGui(ClaseTexturas& texturas, int posx, int posy, int speed,
                 std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, speed, frames) {}

SpazGui::~SpazGui() {}

void SpazGui::setFrames(int animacion_actual,int spe) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_STAND));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_WALK));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(true);
            frames = texturas.findFrame(std::string(SPAZ_WALK));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_SALTAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_JUMP));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_DISPARAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_SHOOT));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_RUN_IZQUIERDA:
            animacion.setFlip(true);
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_RUN_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_ESPECIAL:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(SPAZ_SPECIAL));
            it = frames->begin();
            speed = spe;
            break;
        default:
            break;
    }
}

JazzGui::JazzGui(ClaseTexturas& texturas, int posx, int posy, int speed,
                 std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, speed, frames) {}

JazzGui::~JazzGui() {}

void JazzGui::setFrames(int animacion_actual, int spe) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_STAND));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_WALK));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_WALK));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_SALTAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_JUMP));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_DISPARAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_SHOOT));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_RUN_IZQUIERDA:
            animacion.setFlip(true);
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_RUN_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_ESPECIAL:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(JAZZ_SPECIAL));
            it = frames->begin();
            speed = spe;
            break;
        default:
            break;
    }
}

LoriGui::LoriGui(ClaseTexturas& texturas, int posx, int posy, int speed,
                 std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, speed, frames) {}

LoriGui::~LoriGui() {}

void LoriGui::setFrames(int animacion_actual,int spe) {
    switch (animacion_actual) {
        case ANI_STAND:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_STAND));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_MOVER_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_WALK));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_MOVER_IZQUIERDA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_WALK));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_SALTAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_JUMP));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_DISPARAR:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_SHOOT));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_RUN_IZQUIERDA:
            animacion.setFlip(true);
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_RUN_DERECHA:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case ANI_ESPECIAL:
            animacion.setFlip(false);
            frames = texturas.findFrame(std::string(LORI_SPECIAL));
            it = frames->begin();
            speed = spe;
            break;
        default:
            break;
    }
}
