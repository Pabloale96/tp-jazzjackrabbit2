#include "../../include/server_src/game/game_personaje.h"

#include "../../include/common_src/msgToSent.h"

Personaje::Personaje(uint16_t partida_id, uint16_t client_id):
        tipo_personaje(),
        partida_id(partida_id),
        client_id(client_id),
        puntos(PUNTOS_INICIALES),
        vida(VIDA_INICIAL),
        arma(),
        posicion() {}

Personaje::Personaje(msgPersonaje & personaje):
        tipo_personaje(personaje.tipo_personaje),
        partida_id(partida_id),
        client_id(personaje.personaje[POS_ID_PERSONAJE]),
        puntos(personaje.personaje[POS_PUNTOS_PERSONAJE]),
        vida(personaje.personaje[POS_VIDA_PERSONAJE]),
        arma(personaje.personaje[POS_MUNICION_PERSONAJE], personaje.tipo_arma),
        posicion(personaje.personaje[POS_POSX_PERSONAJE], personaje.personaje[POS_POSY_PERSONAJE]) {}

void Personaje::asignar_tipo_personaje(const uint16_t& tipo_personaje) {
    this->tipo_personaje = tipo_personaje;
}

bool Personaje::mover(const std::string& direccion) {
    // TODO: Esto es reactivo
    return posicion.mover(direccion);
    // Deberia setear el toggle de movimiento
    // y siempre hago el update
}

void Personaje::disminuir_vida(uint16_t danio) {
    if (vida > danio) {
        vida -= danio;
    } else {
        vida = 0;
    }
}

void Personaje::disminuir_municion() { arma.disminuir_municion(); }

Posicion Personaje::obtener_posicion() const { return posicion; }

uint16_t Personaje::obtener_partida_id() const { return partida_id; }

uint16_t Personaje::obtener_personaje_id() const { return client_id; }

uint8_t Personaje::obtener_tipo_personaje() const { return tipo_personaje; }

uint16_t Personaje::obtener_puntos() const { return puntos; }

uint16_t Personaje::obtener_vida() const { return vida; }

uint16_t Personaje::obtener_municion() const { return arma.obtener_municion(); }

uint8_t Personaje::obtener_nombre_arma() const { return arma.obtener_nombre_arma(); }

Jazz::Jazz(uint16_t partida_id, uint16_t client_id): Personaje(partida_id, client_id) {
    asignar_tipo_personaje(static_cast<uint16_t>(TIPO_PERSONAJE::JAZZ));
}

void Jazz::punietazo_hacia_arriba() {
    // TODO: Implementación del puñetazo hacia arriba
}

Lori::Lori(uint16_t partida_id, uint16_t client_id): Personaje(partida_id, client_id) {
    asignar_tipo_personaje(static_cast<uint16_t>(TIPO_PERSONAJE::LORI));
}

void Lori::patada_de_corto_alcance() {
    // TODO: Implementación de la patada de corto alcance
}

Spazz::Spazz(uint16_t partida_id, uint16_t client_id): Personaje(partida_id, client_id) {
    asignar_tipo_personaje(static_cast<uint16_t>(TIPO_PERSONAJE::SPAZZ));
}

void Spazz::patada_hacia_un_costado() {
    // TODO: Implementación de la patada hacia un costado
}

Personaje* crear_personaje(uint16_t partida_id, uint16_t client_id, const std::string& personaje) {
    if (personaje == "jazz") {
        return new Jazz(partida_id, client_id);
    } else if (personaje == "lori") {
        return new Lori(partida_id, client_id);
    } else if (personaje == "spazz") {
        return new Spazz(partida_id, client_id);
    } else {
        return nullptr;
    }
}
