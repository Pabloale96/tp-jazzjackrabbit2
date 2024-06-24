#include "../../include/server_src/game/game_platform.h"

Platform::Platform(uint16_t pos_x, uint16_t pos_y, uint16_t width, uint16_t height, uint8_t type,
                   bool flip):
        pos_x(pos_x), pos_y(pos_y), width(width), height(height), type(type), flip(flip) {}

Platform::~Platform() {}

uint16_t Platform::obtener_posicion_x() const { return pos_x; }
uint16_t Platform::obtener_posicion_y() const { return pos_y; }
uint8_t Platform::obtener_tipo() const { return type; }
uint16_t Platform::obtener_width() const { return width; }
uint16_t Platform::obtener_height() const { return height; }
uint8_t Platform::obtener_flip() const { return (flip) ? 0x01 : 0x00; }


// Funciones para detectar colisiones
uint16_t Platform::getBottom() const { return pos_y; }
uint16_t Platform::getTop() const { return pos_y + height; }
uint16_t Platform::getLeft() const { return pos_x - width; }
uint16_t Platform::getRight() const { return pos_x; }


Plataforma::Plataforma(platform tipo_plataforma, float x_ver_izq_abajo, float y_ver_izq_abajo,
                       float x_ver_izq_arriba, float y_ver_izq_arriba, float x_ver_der_abajo,
                       float y_ver_der_abajo, float x_ver_der_arriba, float y_ver_der_arriba,
                       uint8_t angulo):
        tipo_plataforma(tipo_plataforma),
        vertice_izq_abajo(x_ver_izq_abajo, y_ver_izq_abajo),
        vertice_izq_arriba(x_ver_izq_arriba, y_ver_izq_arriba),
        vertice_der_abajo(x_ver_der_abajo, y_ver_der_abajo),
        vertice_der_arriba(x_ver_der_arriba, y_ver_der_arriba),
        centro((x_ver_izq_abajo + x_ver_der_arriba) / 2, (y_ver_izq_abajo + y_ver_der_arriba) / 2),
        angulo(angulo) {}


platform Plataforma::obtener_tipo_plataforma() const { return tipo_plataforma; }
Posicion Plataforma::obtener_vertice_izq_abajo() const { return vertice_izq_abajo; }
Posicion Plataforma::obtener_vertice_izq_arriba() const { return vertice_izq_arriba; }
Posicion Plataforma::obtener_vertice_der_abajo() const { return vertice_der_abajo; }
Posicion Plataforma::obtener_vertice_der_arriba() const { return vertice_der_arriba; }

float Plataforma::obtener_borde_izquierdo() const { return vertice_izq_abajo.get_posicion_x(); }

float Plataforma::obtener_borde_derecho() const { return vertice_der_abajo.get_posicion_x(); }

float Plataforma::obtener_borde_superior() const { return vertice_izq_arriba.get_posicion_y(); }

float Plataforma::obtener_borde_inferior() const { return vertice_izq_abajo.get_posicion_y(); }

Posicion Plataforma::obtener_centro() const { return centro; }
uint8_t Plataforma::obtener_angulo() const { return angulo; }

bool Plataforma::estoy_adentro_de_la_plataforma(float prox_pos_x, float prox_pos_y) const {
    if (prox_pos_x >= obtener_borde_izquierdo() && prox_pos_x <= obtener_borde_derecho() &&
        prox_pos_y <= obtener_borde_superior() && prox_pos_y >= obtener_borde_inferior()) {
        return true;
    }
    return false;
}

void Plataforma::chequear_colisiones(float prox_pos_x, float prox_pos_y, bool& colisiona_en_x,
                                     bool& colisiona_en_y) const {
    if (es_plataforma_cercana_en_x_izquierda(prox_pos_x)) {
        colisiona_en_x = true;
    } else if (es_plataforma_cercana_en_x_derecha(prox_pos_x)) {
        colisiona_en_x = true;
    }
    if (es_plataforma_cercana_en_y_abajo(prox_pos_y)) {
        colisiona_en_y = true;
    } else if (es_plataforma_cercana_en_y_arriba(prox_pos_y)) {
        colisiona_en_y = true;
    }
}

bool Plataforma::es_plataforma_cercana_en_y_abajo(float y) const {
    const float TOLERANCIA = 0.01f;
    // Si la futura posición del personaje está por debajo del borde superior, entonces voy a
    // chocar
    if (y <= obtener_borde_superior() + TOLERANCIA) {
        if (y >= obtener_borde_inferior() - TOLERANCIA) {
            return true;
        }
    }
    return false;
}

bool Plataforma::es_plataforma_cercana_en_y_arriba(float y) const {
    const float TOLERANCIA = 0.01f;
    // Si la futura posición del personaje está por encima del borde inferior, entonces voy a
    // chocar
    if (y >= obtener_borde_inferior() - TOLERANCIA) {
        if (y <= obtener_borde_superior() + TOLERANCIA) {
            return true;
        }
    }
    return false;
}

bool Plataforma::es_plataforma_cercana_en_x_izquierda(float x) const {
    const float TOLERANCIA = 0.01f;
    // Si la futura posición del personaje está a la derecha del borde izquierdo, entonces voy a
    // chocar
    if (x <= obtener_borde_derecho() + TOLERANCIA) {
        if (x >= obtener_borde_izquierdo() - TOLERANCIA) {
            return true;
        }
    }
    return false;
}

bool Plataforma::es_plataforma_cercana_en_x_derecha(float x) const {
    const float TOLERANCIA = 0.01f;
    // Si la futura posición del personaje está a la izquierda del borde derecho, entonces voy a
    // chocar
    if (x >= obtener_borde_izquierdo() - TOLERANCIA) {
        if (x <= obtener_borde_derecho() + TOLERANCIA) {
            return true;
        }
    }
    return false;
}

Plataforma::~Plataforma() {}
