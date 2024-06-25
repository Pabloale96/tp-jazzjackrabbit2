#include "../../include/client_src/gui/gui_personaje.h"

PersonajeGui::PersonajeGui(ClaseTexturas& texturas, float posx, float posy, uint8_t tipo, int speed,
                           std::shared_ptr<std::vector<Frame>>& frames):
        puntos(texturas,0),
        texturas(texturas),
        pos_x(posx),
        pos_y(posy),
        tipo(1),
        speed(speed),
        estado(0),
        vida(texturas, 10, tipo),
        animacion(),
        frames(frames),
        it(frames->begin()) {}

PersonajeGui::PersonajeGui(ClaseTexturas& texturas, msgPersonaje& personaje):
        puntos(texturas,(int)ntohs(personaje.personaje[POS_PUNTOS_PERSONAJE])),
        texturas(texturas),
        pos_x((float)ntohs(personaje.personaje[POS_POSX_PERSONAJE]) / 100.0),
        pos_y((float)ntohs(personaje.personaje[POS_POSY_PERSONAJE]) / 100.0),
        tipo(personaje.tipo_personaje),
        speed(5),
        estado(personaje.estado),
        vida(texturas, ntohs(personaje.personaje[POS_VIDA_PERSONAJE]), tipo),
        animacion(),
        frames(texturas.findFrame(std::string(SPAZ_STAND))),
        it(frames->begin()) {}

// estados() {}
void PersonajeGui::setPosicion(float x, float y) {
    pos_x = x;
    pos_y = y;
}

void PersonajeGui::actualizar_personaje(const PersonajeGui& other) {
    this->pos_x = other.obtener_posicion_x();
    this->pos_y = other.obtener_posicion_y();
    this->vida.setVida(other.getVida());
    this->puntos.setPuntos(other.getPuntos());
    if (this->estado != other.obtener_estado_actual()) {
        this->estado = other.obtener_estado_actual();
        this->setFrames();
    } else {
        if (frames && !frames->empty()) {
            this->it++;
            if (this->it == frames->end()) {
                it = frames->begin();
            }
        } else {
            it = frames->begin();
            // throw std::runtime_error("Error: frames is null or empty");
        }
    }
}

void PersonajeGui::setAnimacion(const PersonajeGui& other, bool flip) {
    if (this->estado != estado) {
      this->actualizar_personaje(other);
      this->animacion.setFlip(flip);
    }
}

void PersonajeGui::show(bool con_vida,int h_window, int w_window) {
    if (con_vida) {
        puntos.show(h_window);
        vida.run();
    }
    animacion.run(pos_x, pos_y, speed, frames, it);
}

void PersonajeGui::setFrames() {}

SpazGui::SpazGui(ClaseTexturas& texturas, float posx, float posy, uint8_t tipo, int speed,
                 std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, tipo, speed, frames) {}

SpazGui::SpazGui(ClaseTexturas& texturas, msgPersonaje& msg): PersonajeGui(texturas, msg) {
    this->setFrames();
}

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

JazzGui::JazzGui(ClaseTexturas& texturas, float posx, float posy, uint8_t tipo, int speed,
                 std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, tipo, speed, frames) {}

JazzGui::JazzGui(ClaseTexturas& texturas, msgPersonaje& msg): PersonajeGui(texturas, msg) {
    this->setFrames();
}

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

LoriGui::LoriGui(ClaseTexturas& texturas, float posx, float posy, uint8_t tipo, int speed,
                 std::shared_ptr<std::vector<Frame>>& frames):
        PersonajeGui(texturas, posx, posy, tipo, speed, frames) {}

LoriGui::LoriGui(ClaseTexturas& texturas, msgPersonaje& msg): PersonajeGui(texturas, msg) {
    this->setFrames();
}
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

PersonajeGui::~PersonajeGui() {}
