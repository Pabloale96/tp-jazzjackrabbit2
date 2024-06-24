#include "game_velocidad.h"

Velocidad::Velocidad(): velocidad_x(0.0f), velocidad_y(0.0f) {}

Velocidad::Velocidad(float velocidad_x, float velocidad_y):
        velocidad_x(velocidad_x), velocidad_y(velocidad_y) {}

float Velocidad::obtener_velocidad_x() const { return velocidad_x; }

float Velocidad::obtener_velocidad_y() const { return velocidad_y; }

void Velocidad::setear_velocidad_x(float velocidad_x) { this->velocidad_x = velocidad_x; }

void Velocidad::setear_velocidad_y(float velocidad_y) { this->velocidad_y = velocidad_y; }

void Velocidad::idle() {
    velocidad_x = 0;
    velocidad_y = 0;
}

void Velocidad::correrDerecha() {
    velocidad_x = VELOCIDAD_NORMAL;
    velocidad_y = 0;
}

void Velocidad::correrDerechaRapido() {
    velocidad_x = VELOCIDAD_RAPIDA;
    velocidad_y = 0;
}

void Velocidad::correrIzquierda() {
    velocidad_x = (-1) * VELOCIDAD_NORMAL;
    velocidad_y = 0;
}

void Velocidad::correrIzquierdaRapido() {
    velocidad_x = (-1) * VELOCIDAD_RAPIDA;
    velocidad_y = 0;
}

void Velocidad::saltar() {
    // Si estoy corriendo y salto, mantengo la velocidad en x
    velocidad_y = 3.0f;
}

void Velocidad::caer() { velocidad_y = (-1) * VELOCIDAD_NORMAL; }


Velocidad::~Velocidad() {}
