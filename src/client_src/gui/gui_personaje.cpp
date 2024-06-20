#include "../../include/client_src/gui/gui_personaje.h"

PersonajeGui::PersonajeGui(ClaseTexturas& texturas, int posx, int posy, int speed,
                           std::shared_ptr<std::vector<Frame>>& frames):
        texturas(texturas), pos_x(posx), pos_y(posy), speed(speed), frames(frames) {
    it = frames->begin();
}
PersonajeGui::PersonajeGui(ClaseTexturas& texturas, msgPersonaje& personaje):
        // puntos(ntohs(personaje.personaje[POS_PUNTOS_PERSONAJE])),
        // vida(ntohs(personaje.personaje[POS_VIDA_PERSONAJE]))),
        texturas(texturas),
        pos_x(ntohs(personaje.personaje[POS_POSX_PERSONAJE])),
        pos_y(ntohs(personaje.personaje[POS_POSY_PERSONAJE])),
        tipo(personaje.tipo_personaje),
        frames(nullptr) {}
// estados() {}
void PersonajeGui::setAccion(uint8_t accion){
    switch (accion) {
        case (uint8_t) acciones::NULO:
            this->estado = ANI_STAND;
            this->setFrames(5);
            break;
        case (uint8_t) acciones::MOVER_DERECHA:
            this->estado = ANI_MOVER_DERECHA;
            this->setFrames(5);
            break;
        case (uint8_t) acciones::MOVER_DERECHA_RAPIDO:
            this->estado = ANI_RUN_DERECHA;
            this->setFrames(5);
            break;
        case (uint8_t) acciones::MOVER_IZQUIERDA:
            this->estado = ANI_MOVER_IZQUIERDA;
            this->setFrames(5);
            break;
        case (uint8_t) acciones::MOVER_IZQUIERDA_RAPIDO:
            this->estado = ANI_RUN_IZQUIERDA;
            this->setFrames(5);
            break;
        case (uint8_t) acciones::SALTAR:
            this->estado = ANI_SALTAR;
            this->setFrames(5);
            break;
        case (uint8_t) acciones::DISPARAR:
            this->estado = ANI_DISPARAR;
            this->setFrames(5);
            break;
        case (uint8_t) acciones::ACCION_ESPECIAL:
            this->estado = ANI_ESPECIAL;
            this->setFrames(5);
            break;
        default:
            break;
    }
}

PersonajeGui::~PersonajeGui() {}

void PersonajeGui::show() { animacion.run(pos_x, pos_y, speed, frames, it); }

void PersonajeGui::setFrames(int spe) {}

SpazGui::SpazGui(ClaseTexturas& texturas, int posx, int posy, int speed,
                 std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, speed, frames) {}

SpazGui::SpazGui(ClaseTexturas& texturas, msgPersonaje& msg): PersonajeGui(texturas, msg) {
    this->setAccion(msg.estado);
}
SpazGui::~SpazGui() {}

void SpazGui::setFrames(int spe) {
    switch (estado) {
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

JazzGui::JazzGui(ClaseTexturas& texturas, msgPersonaje& msg): PersonajeGui(texturas, msg) {
    this->setAccion(msg.estado);
}
JazzGui::~JazzGui() {}

void JazzGui::setFrames(int spe) {
    switch (estado) {
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

LoriGui::LoriGui(ClaseTexturas& texturas, msgPersonaje& msg): PersonajeGui(texturas, msg) {
    this->setAccion(msg.estado);
}
LoriGui::~LoriGui() {}

void LoriGui::setFrames(int spe) {
    switch (estado) {
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
