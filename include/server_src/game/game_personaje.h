#ifndef _GAME_PERSONAJE_H_
#define _GAME_PERSONAJE_H_

#include <iostream>
#include <string>
#include <vector>

#include "defines_msg.h"
#include "game_arma.h"
#include "game_posicion.h"
#include "game_municion.h"

#define PUNTOS_INICIALES 0
#define VIDA_INICIAL 10

class Personaje {

private:
    std::string tipo_personaje;
    uint16_t partida_id;
    uint16_t client_id;
    uint16_t puntos;
    uint16_t vida;
    Arma arma;
    Posicion posicion;
    std::vector<Municion> municiones_disparadas;
    Direccion direccion;

public:
    explicit Personaje(uint16_t partida_id, uint16_t client_id);

    explicit Personaje(uint16_t* personaje);

    void asignar_tipo_personaje(const std::string& tipo_personaje);

    virtual bool mover(const std::string& direccion);

    void setear_direccion(const std::string& direccion);

    void disminuir_vida(uint16_t danio);

    void disminuir_municion();

    Posicion obtener_posicion() const;

    Direccion obtener_direccion() const;

    uint16_t obtener_partida_id() const;

    uint16_t obtener_personaje_id() const;

    std::string obtener_tipo_personaje() const;

    uint16_t obtener_puntos() const;

    uint16_t obtener_vida() const;

    uint8_t obtener_nombre_arma() const;

    uint16_t obtener_municion() const;

    virtual ~Personaje() = default;
};

class Jazz: public Personaje {
public:
    Jazz(uint16_t partida_id, uint16_t client_id);
    void punietazo_hacia_arriba();
};

class Lori: public Personaje {
public:
    Lori(uint16_t partida_id, uint16_t client_id);
    void patada_de_corto_alcance();
};

class Spazz: public Personaje {
public:
    Spazz(uint16_t partida_id, uint16_t client_id);
    void patada_hacia_un_costado();
};

Personaje* crear_personaje(uint16_t partida_id, uint16_t client_id, const std::string& personaje);

#endif
