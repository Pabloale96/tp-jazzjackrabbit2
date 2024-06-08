#ifndef _CLIENTE_PERSONAJE_H_
#define _CLIENTE_PERSONAJE_H_

#include <iostream>
#include "msgToSent.h"

class PersonajeCliente {
private:
    uint16_t client_id;
    uint16_t posicion_x;
    uint16_t posicion_y;
    uint16_t puntos;
    uint16_t vida; 
    uint16_t municion;
    uint8_t tipo_arma;
    uint8_t tipo_personaje;

public:
    explicit PersonajeCliente(msgPersonaje& datos_personajes) :
        client_id(datos_personajes.personaje[POS_ID_PERSONAJE]),
        posicion_x(datos_personajes.personaje[POS_POSX_PERSONAJE]),
        posicion_y(datos_personajes.personaje[POS_POSY_PERSONAJE]),
        puntos(datos_personajes.personaje[POS_PUNTOS_PERSONAJE]),
        vida(datos_personajes.personaje[POS_VIDA_PERSONAJE]),
        municion(datos_personajes.personaje[POS_MUNICION_PERSONAJE]),
        tipo_arma(datos_personajes.nombre_arma),
        tipo_personaje(datos_personajes.tipo_personaje) {}

    uint16_t obtener_personaje_id() const { return client_id; }

    uint16_t obtener_posicion_x() const { return posicion_x; }

    uint16_t obtener_posicion_y() const { return posicion_y; }

    uint16_t obtener_puntos() const { return puntos; }

    uint16_t obtener_vida() const { return vida; }

    uint16_t obtener_municion() const { return municion; }

    uint8_t obtener_tipo_arma() const { return tipo_arma; }

    uint8_t obtener_tipo_personaje() const { return tipo_personaje; }

    ~PersonajeCliente() {}
};

#endif
