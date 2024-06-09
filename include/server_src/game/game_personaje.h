#ifndef _GAME_PERSONAJE_H_
#define _GAME_PERSONAJE_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "defines_msg.h"
#include "protocol_utils.h"
#include "game_arma.h"
#include "game_municion.h"
#include "game_posicion.h"

#define PUNTOS_INICIALES 0
#define VIDA_INICIAL 10


struct msgPersonaje;

class Personaje {

private:
    uint8_t tipo_personaje;
    uint16_t partida_id;
    uint16_t client_id;
    uint16_t puntos;
    uint16_t vida;
    uint8_t animacion;
    Arma arma;
    Posicion posicion;
    std::vector<Municion> municiones_disparadas;
    Direccion direccion;
    std::vector<bool> estados;
    std::vector<bool> acciones;

public:
    explicit Personaje(uint16_t partida_id, uint16_t client_id);

    explicit Personaje(msgPersonaje & personaje);

    void asignar_tipo_personaje(uint8_t tipo_personaje);

    void intoxicar();

    std::vector<bool>  obtener_estados();

    uint8_t obtener_animacion();

    void actualizar();

    virtual bool mover(const std::string& direccion);

    void setear_direccion(const std::string& direccion);

    void disminuir_vida(uint16_t danio);

    void disminuir_municion();

    Posicion obtener_posicion() const;

    Direccion obtener_direccion() const;

    uint16_t obtener_partida_id() const;

    uint16_t obtener_personaje_id() const;

    uint8_t obtener_tipo_personaje() const;

    uint16_t obtener_puntos() const;

    uint16_t obtener_vida() const;

    uint8_t obtener_nombre_arma() const;

    uint16_t obtener_municion() const;

    virtual void accion_especial() = 0;

    virtual ~Personaje() = default;
};

class Jazz: public Personaje {
public:
    Jazz(uint16_t partida_id, uint16_t client_id);
    Jazz(msgPersonaje & personaje);
    void accion_especial() override;
};

class Lori: public Personaje {
public:
    Lori(uint16_t partida_id, uint16_t client_id);
    Lori(msgPersonaje & personaje);
    void accion_especial() override;
};

class Spazz: public Personaje {
public:
    Spazz(uint16_t partida_id, uint16_t client_id);
    Spazz(msgPersonaje & personaje);
    void accion_especial() override;
};

Personaje* crear_personaje(uint16_t partida_id, uint16_t client_id, uint8_t personaje);

#endif
