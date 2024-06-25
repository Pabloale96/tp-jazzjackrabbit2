#include "../../include/server_src/game/game_enemigo.h"

#include <iostream>

#include <arpa/inet.h>

#include "../../include/server_src/yaml_config.h"

#include "defines_msg.h"

// Todos los enemigos tienen la misma velocidad y arrancan para la derecha
Enemigo::Enemigo(uint16_t id_enemigo):
        id_enemigo(id_enemigo),
        velocidad_enemigo(VELOCIDAD_EN_x, VELOCIDAD_EN_y),
        tiempo_muerte(),
        moviendose_a_la_derecha(true),
        pasos_hechos(0) {}

Enemigo::Enemigo(uint16_t* datos_enemigo):
        id_enemigo(ntohs(datos_enemigo[POS_ID_ENEMIGO])),
        tipo_enemigo(static_cast<TipoEnemigo>(datos_enemigo[POS_TIPO_ENEMIGO])),
        posicion_enemigo(ntohs(datos_enemigo[POS_POSX_ENEMIGO]),
                         ntohs(datos_enemigo[POS_POSY_ENEMIGO])) {}

void Enemigo::set_enemigo_id(uint16_t id_enemigo) { this->id_enemigo = id_enemigo; }

void Enemigo::set_tipo_enemigo(TipoEnemigo tipo_enemigo) { this->tipo_enemigo = tipo_enemigo; }

void Enemigo::set_posicion_enemigo(float x, float y) { posicion_enemigo.set_posicion(x, y); }

void Enemigo::set_vidas(uint16_t vidas) { this->vidas = vidas; }

void Enemigo::set_danio_al_jugador(uint16_t danio_al_jugador) {
    this->danio_al_jugador = danio_al_jugador;
}

void Enemigo::set_puntos(uint16_t puntos) { this->puntos = puntos; }

void Enemigo::set_time_revive(int time_revive) { this->time_revive = time_revive; }

void Enemigo::set_prob_municion(float prob_municion) { this->prob_municion = prob_municion; }

void Enemigo::set_prob_vida(float prob_vida) { this->prob_vida = prob_vida; }

uint16_t Enemigo::get_id_enemigo() const { return id_enemigo; }

TipoEnemigo Enemigo::get_tipo_enemigo() const { return tipo_enemigo; }

Posicion Enemigo::get_posicion_enemigo() const { return posicion_enemigo; }

uint16_t Enemigo::get_vidas() const { return vidas; }

uint16_t Enemigo::get_danio_al_jugador() const { return danio_al_jugador; }

uint16_t Enemigo::get_puntos() const { return puntos; }

void Enemigo::actualizar() {
    if (esta_vivo()) {
        mover();
    } else {
        aumentar_iteraciones();
    }
}

void Enemigo::mover() {
    if (moviendose_a_la_derecha) {
        posicion_enemigo.set_posicion(posicion_enemigo.get_posicion_x() + 0.1,
                                      posicion_enemigo.get_posicion_y());
        pasos_hechos++;
        if (pasos_hechos >= limite_de_pasos) {
            moviendose_a_la_derecha = false;
            pasos_hechos = 0;
        }
    } else {
        posicion_enemigo.set_posicion(posicion_enemigo.get_posicion_x() - 0.1,
                                      posicion_enemigo.get_posicion_y());
        pasos_hechos++;
        if (pasos_hechos >= limite_de_pasos) {
            moviendose_a_la_derecha = true;
            pasos_hechos = 0;
        }
    }
}

void Enemigo::recibir_disparo(uint8_t danio) {
    if (vidas > danio) {
        vidas -= danio;
    } else {
        vidas = 0;
        set_time_death(std::chrono::system_clock::now());
    }
}

void Enemigo::set_time_death(std::chrono::time_point<std::chrono::system_clock> time) {
    tiempo_muerte = time;
}

void Enemigo::aumentar_iteraciones() {
    auto now = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - tiempo_muerte).count();
    if (elapsed >= time_revive) {
        revivir_enemigo();
    }
}

void Enemigo::matar() { vidas = 0; }

void Enemigo::revivir_enemigo() {}

bool Enemigo::esta_vivo() {
    if (vidas > 0) {
        return true;
    }
    return false;
}


// ************  ENEMIGO 1 ("nombre")  ************
// Enemigo1 constructor
Enemigo1::Enemigo1(uint16_t id, float x, float y): Enemigo(id) {
    set_tipo_enemigo(TipoEnemigo::ENEMIGO1);
    set_posicion_enemigo(x, y);
    set_vidas(YAMLConfig::getConfig().enemigo_1.vidas);
    set_danio_al_jugador(YAMLConfig::getConfig().enemigo_1.danio);
    set_puntos(YAMLConfig::getConfig().enemigo_1.puntos);
    set_time_revive(YAMLConfig::getConfig().enemigo_1.segundos_para_revivir);
    set_prob_municion(YAMLConfig::getConfig().enemigo_1.proba_droppear_municion);
    set_prob_vida(YAMLConfig::getConfig().enemigo_1.proba_droppear_vida);
}

void Enemigo1::revivir_enemigo() {
    if (!esta_vivo()) {
        set_vidas(YAMLConfig::getConfig().enemigo_1.vidas);
    }
}

// ************  ENEMIGO 2 ("nombre")  ************
// Enemigo2 constructor
Enemigo2::Enemigo2(uint16_t id, float x, float y): Enemigo(id) {
    set_tipo_enemigo(TipoEnemigo::ENEMIGO2);
    set_posicion_enemigo(x, y);
    set_vidas(YAMLConfig::getConfig().enemigo_2.vidas);
    set_danio_al_jugador(YAMLConfig::getConfig().enemigo_2.danio);
    set_puntos(YAMLConfig::getConfig().enemigo_2.puntos);
    set_time_revive(YAMLConfig::getConfig().enemigo_2.segundos_para_revivir);
    set_prob_municion(YAMLConfig::getConfig().enemigo_2.proba_droppear_municion);
    set_prob_vida(YAMLConfig::getConfig().enemigo_2.proba_droppear_vida);
}

void Enemigo2::revivir_enemigo() {
    if (!esta_vivo()) {
        set_vidas(YAMLConfig::getConfig().enemigo_2.vidas);
    }
}

// ************  ENEMIGO 3 ("VOLADOR")  ************
// Enemigo3 constructor
Enemigo3::Enemigo3(uint16_t id, float x, float y): Enemigo(id) {
    set_tipo_enemigo(TipoEnemigo::ENEMIGO3);
    set_posicion_enemigo(x, y);
    set_vidas(YAMLConfig::getConfig().enemigo_3.vidas);
    set_danio_al_jugador(YAMLConfig::getConfig().enemigo_3.danio);
    set_puntos(YAMLConfig::getConfig().enemigo_3.puntos);
    set_time_revive(YAMLConfig::getConfig().enemigo_3.segundos_para_revivir);
    set_prob_municion(YAMLConfig::getConfig().enemigo_3.proba_droppear_municion);
    set_prob_vida(YAMLConfig::getConfig().enemigo_3.proba_droppear_vida);
}

void Enemigo3::revivir_enemigo() {
    if (!esta_vivo()) {
        set_vidas(YAMLConfig::getConfig().enemigo_3.vidas);
    }
}
