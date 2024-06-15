#ifndef _GAME_PERSONAJE_H_
#define _GAME_PERSONAJE_H_

#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "defines_msg.h"
#include "game_arma.h"
#include "game_municion.h"
#include "game_personaje_estado.h"
#include "game_posicion.h"
#include "game_velocidad.h"
#include "protocol_utils.h"

#define PUNTOS_INICIALES 0
#define VIDA_INICIAL 10


struct msgPersonaje;

class Personaje {

private:
    uint16_t partida_id;
    uint16_t client_id;
    uint8_t tipo_personaje;
    uint16_t puntos;
    uint16_t vida;

    uint8_t animacion;

    Arma arma;
    std::vector<Municion> municiones_disparadas;
    uint16_t bala_id;

    Posicion posicion;
    Velocidad velocidad;
    uint16_t ancho;
    uint16_t alto;

    std::chrono::seconds tiempo_restante_de_partida;
    std::chrono::seconds duracion_del_salto;

protected:
    EstadoPersonaje estados;

public:
    explicit Personaje(uint16_t partida_id, uint16_t client_id,
                       std::chrono::seconds tiempo_restante_de_partida);

    explicit Personaje(msgPersonaje& personaje);

    void asignar_tipo_personaje(uint8_t tipo_personaje);

    void intoxicar();

    EstadoPersonaje& obtener_estados();

    uint8_t obtener_estado_actual();

    uint8_t obtener_animacion();

    void actualizar(std::chrono::seconds tiempo_restante_de_partida);

    void set_tiempo_restante_de_partida(std::chrono::seconds tiempo_restante_de_partida);

    virtual void mover();

    Velocidad& obtener_velocidad();

    void disminuir_vida(uint16_t danio);

    void disminuir_municion();

    Posicion obtener_posicion() const;

    uint16_t obtener_partida_id() const;

    uint16_t obtener_personaje_id() const;

    uint8_t obtener_tipo_personaje() const;

    uint16_t obtener_puntos() const;

    uint16_t obtener_vida() const;

    uint8_t obtener_nombre_arma() const;

    uint16_t obtener_municion() const;

    std::chrono::seconds obtener_tiempo_restante_de_partida() const;

    uint16_t generar_id_bala();

    std::vector<Municion> obtener_balas() const;

    void disparar();

    void eliminar_bala(uint16_t id_bala);

    virtual void accion_especial() = 0;

    uint16_t getBottom() const;
    uint16_t getTop() const;
    uint16_t getLeft() const;
    uint16_t getRight() const;

    uint16_t obtener_ancho() const;

    virtual ~Personaje() = default;
};

class Jazz: public Personaje {
public:
    Jazz(uint16_t partida_id, uint16_t client_id, std::chrono::seconds tiempo_restante_de_partida);
    explicit Jazz(msgPersonaje& personaje);
    void accion_especial() override;
};

class Lori: public Personaje {
public:
    Lori(uint16_t partida_id, uint16_t client_id, std::chrono::seconds tiempo_restante_de_partida);
    explicit Lori(msgPersonaje& personaje);
    void accion_especial() override;
};

class Spazz: public Personaje {
public:
    Spazz(uint16_t partida_id, uint16_t client_id, std::chrono::seconds tiempo_restante_de_partida);
    explicit Spazz(msgPersonaje& personaje);
    void accion_especial() override;
};

Personaje* crear_personaje(uint16_t partida_id, uint16_t client_id, uint8_t personaje,
                           std::chrono::seconds tiempo_restante_de_partida);

#endif
