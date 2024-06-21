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
        pos_x(ntohs(personaje.personaje[POS_POSX_PERSONAJE]) / 100),
        pos_y(ntohs(personaje.personaje[POS_POSY_PERSONAJE]) / 100),
        tipo(personaje.tipo_personaje),
        estado(personaje.estado),
        frames(nullptr) {
    this->setFrames();
}
// estados() {}
void PersonajeGui::setPosicion(int x, int y) {
    pos_x = x;
    pos_y = y;
}

void PersonajeGui::setAnimacion(uint8_t estado, bool flip) {
    if (this->estado != estado) {
        this->estado = estado;
        this->setFrames();
        animacion.setFlip(flip);
    }
}

void PersonajeGui::setAccion(uint8_t accion) {
    switch (accion) {
        case (uint8_t)efectos::IDLE:
            this->estado = ANI_STAND;
            this->setFrames();
            break;
        case (uint8_t)efectos::CORRIENDO:
            this->estado = ANI_MOVER_DERECHA;
            this->setFrames();
            break;
        case (uint8_t)efectos::CORRIENDO_RAPIDO:
            this->estado = ANI_RUN_DERECHA;
            this->setFrames();
            break;
        case (uint8_t)efectos::SALTANDO:
            this->estado = ANI_SALTAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::CORRIENDO_SALTANDO:
            this->estado = ANI_SALTAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::CAYENDO:
            this->estado = ANI_SALTAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::INTOXICADO:
            this->estado = ANI_SALTAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::HERIDO:
            this->estado = ANI_SALTAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::MUERTO:
            this->estado = ANI_SALTAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::DISPARANDO:
            this->estado = ANI_DISPARAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::DISPARANDO_SALTANDO:
            this->estado = ANI_DISPARAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::DISPARANDO_CORRIENDO:
            this->estado = ANI_DISPARAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::DISPARANDO_CAYENDO:
            this->estado = ANI_DISPARAR;
            this->setFrames();
            break;
        case (uint8_t)efectos::ACCION_ESPECIAL:
            this->estado = ANI_ESPECIAL;
            this->setFrames();
            break;
        default:
            break;
    }
}

PersonajeGui::~PersonajeGui() {}

void PersonajeGui::show() { animacion.run(pos_x, pos_y, speed, frames, it); }

void PersonajeGui::setFrames() {}

SpazGui::SpazGui(ClaseTexturas& texturas, int posx, int posy, int speed,
                 std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, speed, frames) {}

SpazGui::SpazGui(ClaseTexturas& texturas, msgPersonaje& msg): PersonajeGui(texturas, msg) {}
SpazGui::~SpazGui() {}

void SpazGui::setFrames() {
    int spe = 5;
    switch (estado) {
        case (uint8_t)efectos::IDLE:
            frames = texturas.findFrame(std::string(SPAZ_STAND));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CORRIENDO:
            frames = texturas.findFrame(std::string(SPAZ_WALK));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::SALTANDO:
            frames = texturas.findFrame(std::string(SPAZ_JUMP));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CORRIENDO_SALTANDO:
            frames = texturas.findFrame(std::string(SPAZ_JUMP));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO:
            frames = texturas.findFrame(std::string(SPAZ_SHOOT));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CORRIENDO_RAPIDO:
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CAYENDO:
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::INTOXICADO:
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::HERIDO:
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::MUERTO:
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO_SALTANDO:
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO_CORRIENDO:
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO_CAYENDO:
            frames = texturas.findFrame(std::string(SPAZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::ACCION_ESPECIAL:
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

JazzGui::JazzGui(ClaseTexturas& texturas, msgPersonaje& msg): PersonajeGui(texturas, msg) {}
JazzGui::~JazzGui() {}

void JazzGui::setFrames() {
    int spe = 5;
    switch (estado) {
        case (uint8_t)efectos::IDLE:
            frames = texturas.findFrame(std::string(JAZZ_STAND));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CORRIENDO:
            frames = texturas.findFrame(std::string(JAZZ_WALK));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::SALTANDO:
            frames = texturas.findFrame(std::string(JAZZ_JUMP));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CORRIENDO_SALTANDO:
            frames = texturas.findFrame(std::string(JAZZ_JUMP));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO:
            frames = texturas.findFrame(std::string(JAZZ_SHOOT));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CORRIENDO_RAPIDO:
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CAYENDO:
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::INTOXICADO:
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::HERIDO:
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::MUERTO:
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO_SALTANDO:
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO_CORRIENDO:
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO_CAYENDO:
            frames = texturas.findFrame(std::string(JAZZ_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::ACCION_ESPECIAL:
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

LoriGui::LoriGui(ClaseTexturas& texturas, msgPersonaje& msg): PersonajeGui(texturas, msg) {}
LoriGui::~LoriGui() {}

void LoriGui::setFrames() {
    int spe = 5;
    switch (estado) {
        case (uint8_t)efectos::IDLE:
            frames = texturas.findFrame(std::string(LORI_STAND));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CORRIENDO:
            frames = texturas.findFrame(std::string(LORI_WALK));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::SALTANDO:
            frames = texturas.findFrame(std::string(LORI_JUMP));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CORRIENDO_SALTANDO:
            frames = texturas.findFrame(std::string(LORI_JUMP));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO:
            frames = texturas.findFrame(std::string(LORI_SHOOT));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CORRIENDO_RAPIDO:
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::CAYENDO:
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::INTOXICADO:
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::HERIDO:
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::MUERTO:
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO_SALTANDO:
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO_CORRIENDO:
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::DISPARANDO_CAYENDO:
            frames = texturas.findFrame(std::string(LORI_RUN));
            it = frames->begin();
            speed = spe;
            break;
        case (uint8_t)efectos::ACCION_ESPECIAL:
            frames = texturas.findFrame(std::string(LORI_SPECIAL));
            it = frames->begin();
            speed = spe;
            break;
        default:
            break;
    }
}
