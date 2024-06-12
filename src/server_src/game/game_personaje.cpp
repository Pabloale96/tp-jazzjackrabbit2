#include "../../include/server_src/game/game_personaje.h"

#include "../../include/common_src/msgToSent.h"

#define ID_BALA_INICIAL 0

#define POS_X_INICIAL 1
#define POS_Y_INICIAL 1

Personaje::Personaje(uint16_t partida_id, uint16_t client_id):
        tipo_personaje(),
        partida_id(partida_id),
        client_id(client_id),
        puntos(PUNTOS_INICIALES),
        vida(VIDA_INICIAL),
        arma(),
        posicion(POS_X_INICIAL,POS_Y_INICIAL),
        bala_id(ID_BALA_INICIAL),
        direccion(Direccion::CENTRO),
        estados() {}

Personaje::Personaje(msgPersonaje& personaje):
        tipo_personaje(personaje.tipo_personaje),
        partida_id(0),
        client_id(ntohs(personaje.personaje[POS_ID_PERSONAJE])),
        puntos(personaje.personaje[POS_PUNTOS_PERSONAJE]),
        vida(ntohs(personaje.personaje[POS_VIDA_PERSONAJE])),
        arma(ntohs(personaje.personaje[POS_MUNICION_PERSONAJE]), personaje.tipo_arma),
        posicion(personaje.personaje[POS_POSX_PERSONAJE], personaje.personaje[POS_POSY_PERSONAJE]),
        estados() {
    estados.setear_estado_respuesta(personaje.estado);
}

void Personaje::asignar_tipo_personaje(uint8_t tipo_personaje) {
    this->tipo_personaje = tipo_personaje;
}

void Personaje::intoxicar() { estados.setIntoxicado(true); }

EstadoPersonaje& Personaje::obtener_estados() { return estados; }

uint8_t Personaje::obtener_estado_actual() {
    if (estados.esta_intoxicado()) {
        return (uint8_t)efectos::INTOXICADO;
    } else if (estados.getIdle()) {
        return (uint8_t)efectos::IDLE;
    } else if (estados.getCorriendo()) {
        return (uint8_t)efectos::CORRIENDO;
    } else if (estados.getCorriendoMuyRapido()) {
        return (uint8_t)efectos::CORRIENDO_RAPIDO;
    } else if (estados.getSaltando()) {
        return (uint8_t)efectos::SALTANDO;
    } else if (estados.getCayendo()) {
        return (uint8_t)efectos::CAYENDO;
    } else if (estados.getDisparando()) {
        return (uint8_t)efectos::DISPARANDO;
    } else if (estados.getAccionEspecial()) {
        return (uint8_t)efectos::ACCION_ESPECIAL;
    } else if (estados.getMuerto()) {
        return (uint8_t)efectos::MUERTO;
    } else {
        return (uint8_t)efectos::IDLE;
    }
}

uint8_t Personaje::obtener_animacion() { return animacion; }

void Personaje::actualizar() {
    for (auto& municion: municiones_disparadas) {
        municion.mover();
    }
}

void Personaje::setear_direccion(const std::string& direccion) {
    if (direccion == "derecha" || direccion == "derecha_rapido") {
        this->direccion = Direccion::DERECHA;
    } else if (direccion == "izquierda" || direccion == "izquierda_rapido") {
        this->direccion = Direccion::IZQUIERDA;
    } else if (direccion == "arriba" || direccion == "saltar" || direccion == "saltando") {
        this->direccion = Direccion::ARRIBA;
    } else if (direccion == "abajo" || direccion == "cayendo") {
        this->direccion = Direccion::ABAJO;
    } else {
        this->direccion = Direccion::CENTRO;
    }
}

bool Personaje::mover(const std::string& direccion) {
    setear_direccion(direccion);
    return posicion.mover(direccion);
}

void Personaje::disminuir_vida(uint16_t danio) {
    if (vida > danio) {
        vida -= danio;
        estados.setRecibiendoDanio(true);
    } else {
        vida = 0;
        estados.setMuerto(true);
    }
}

void Personaje::disparar() {
    municiones_disparadas.emplace_back(obtener_posicion().get_posicion_x(),
                                       obtener_posicion().get_posicion_y(), obtener_direccion(),
                                       arma.obtener_nombre_arma(), generar_id_bala());
}

void Personaje::eliminar_bala(uint16_t id_bala) {
    for (auto it = municiones_disparadas.begin(); it != municiones_disparadas.end(); ++it) {
        if (it->obtener_id() == id_bala) {
            municiones_disparadas.erase(it);
            break;
        }
    }
}

std::vector<Municion> Personaje::obtener_balas() const { return municiones_disparadas; }

void Personaje::disminuir_municion() { arma.disminuir_municion(); }

Posicion Personaje::obtener_posicion() const { return posicion; }

Direccion Personaje::obtener_direccion() const { return direccion; }

uint16_t Personaje::obtener_partida_id() const { return partida_id; }

uint16_t Personaje::obtener_personaje_id() const { return client_id; }

uint8_t Personaje::obtener_tipo_personaje() const { return tipo_personaje; }

uint16_t Personaje::obtener_puntos() const { return puntos; }

uint16_t Personaje::obtener_vida() const { return vida; }

uint16_t Personaje::obtener_municion() const { return arma.obtener_municion(); }

uint16_t Personaje::generar_id_bala() { return bala_id++; }

uint8_t Personaje::obtener_nombre_arma() const { return arma.obtener_nombre_arma(); }

Jazz::Jazz(uint16_t partida_id, uint16_t client_id): Personaje(partida_id, client_id) {
    asignar_tipo_personaje(static_cast<uint8_t>(personajes::JAZZ));
}

Jazz::Jazz(msgPersonaje& personaje): Personaje(personaje) {}

void Jazz::accion_especial() {
    this->estados.setAccionEspecial(true);
    obtener_posicion().mover("arriba");
    // TODO: Si toco un enemigo, realizo daño
}

Lori::Lori(uint16_t partida_id, uint16_t client_id): Personaje(partida_id, client_id) {
    asignar_tipo_personaje(static_cast<uint8_t>(personajes::LORI));
}

Lori::Lori(msgPersonaje& personaje): Personaje(personaje) {}

void Lori::accion_especial() {
    this->estados.setAccionEspecial(true);
    obtener_posicion().mover("arriba");
    // TODO: Si toco un enemigo, realizo daño
}

Spazz::Spazz(uint16_t partida_id, uint16_t client_id): Personaje(partida_id, client_id) {
    asignar_tipo_personaje(static_cast<uint8_t>(personajes::SPAZZ));
}

Spazz::Spazz(msgPersonaje& personaje): Personaje(personaje) {}

void Spazz::accion_especial() {
    this->estados.setAccionEspecial(true);
    obtener_direccion() == Direccion::DERECHA ? obtener_posicion().mover("derecha") :
                                                obtener_posicion().mover("izquierda");
    // TODO: Si toco un enemigo, realizo daño
}

Personaje* crear_personaje(uint16_t partida_id, uint16_t client_id, uint8_t personaje) {
    if (personaje == static_cast<uint8_t>(personajes::JAZZ)) {
        return new Jazz(partida_id, client_id);
    } else if (personaje == static_cast<uint8_t>(personajes::SPAZZ)) {
        return new Spazz(partida_id, client_id);
    } else if (personaje == static_cast<uint8_t>(personajes::LORI)) {
        return new Lori(partida_id, client_id);
    } else {
        return nullptr;
    }
}
