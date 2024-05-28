#include "../server_src/game_personaje.h"

#include <iostream>

Personaje::Personaje(uint16_t partida_id, uint16_t client_id):
        tipo_personaje(),
        partida_id(partida_id),
        client_id(client_id),
        puntos(PUNTOS_INICIALES),
        vida(VIDA_INICIAL),
        arma(),
        posicion() {}

void Personaje::asignar_tipo_personaje(const std::string& tipo_personaje) {
    this->tipo_personaje = tipo_personaje;
}

bool Personaje::mover(const std::string& direccion) { return posicion.mover(direccion); }

Posicion Personaje::obtener_posicion() const { return posicion; }

uint16_t Personaje::obtener_partida_id() const { return partida_id; }

uint16_t Personaje::obtener_personaje_id() const { return client_id; }

std::string Personaje::obtener_tipo_personaje() const { return tipo_personaje; }

uint16_t Personaje::obtener_puntos() const { return puntos; }

uint16_t Personaje::obtener_vida() const { return vida; }

uint16_t Personaje::obtener_municion() const { return arma.obtener_municion(); }

std::string Personaje::obtener_nombre_arma() const { return arma.obtener_nombre_arma(); }

Jazz::Jazz(uint16_t partida_id, uint16_t client_id): Personaje(partida_id, client_id) {
    asignar_tipo_personaje("jazz");
}

void Jazz::punietazo_hacia_arriba() {
    // TODO: Implementación del puñetazo hacia arriba
}

Lori::Lori(uint16_t partida_id, uint16_t client_id): Personaje(partida_id, client_id) {
    asignar_tipo_personaje("lori");
}

void Lori::patada_de_corto_alcance() {
    // TODO: Implementación de la patada de corto alcance
}

Spazz::Spazz(uint16_t partida_id, uint16_t client_id): Personaje(partida_id, client_id) {
    asignar_tipo_personaje("spazz");
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
