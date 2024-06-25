#ifndef _GAME_ENEMIGO_H_
#define _GAME_ENEMIGO_H_

#include <chrono>
#include <cstdint>

#include "game_posicion.h"
#include "protocol_utils.h"

const float VELOCIDAD_EN_x = 0.1f;
const float VELOCIDAD_EN_y = 0.0f;

class Enemigo {

private:
    uint16_t id_enemigo;
    TipoEnemigo tipo_enemigo;
    Posicion posicion_enemigo;
    Velocidad velocidad_enemigo;

    uint16_t vidas;
    uint16_t danio_al_jugador;
    uint16_t puntos;
    int time_revive;
    float prob_municion;
    float prob_vida;

    std::chrono::time_point<std::chrono::system_clock> tiempo_muerte;

    bool moviendose_a_la_derecha;
    uint16_t pasos_hechos;
    const uint16_t limite_de_pasos = 30;

public:
    // Constructor para el servidor
    explicit Enemigo(uint16_t id_enemigo);

    // Constructor para el cliente
    explicit Enemigo(uint16_t* datos_enemigo);

    // Setters
    void set_enemigo_id(uint16_t id_enemigo);
    void set_tipo_enemigo(TipoEnemigo tipo_enemigo);
    void set_posicion_enemigo(float x, float y);
    void set_vidas(uint16_t vidas);
    void set_danio_al_jugador(uint16_t danio_al_jugador);
    void set_puntos(uint16_t puntos);
    void set_time_revive(int time_revive);
    void set_prob_municion(float prob_municion);
    void set_prob_vida(float prob_vida);
    void set_time_death(std::chrono::time_point<std::chrono::system_clock> time);

    // Getters
    uint16_t get_id_enemigo() const;
    TipoEnemigo get_tipo_enemigo() const;
    Posicion get_posicion_enemigo() const;
    uint16_t get_vidas() const;
    uint16_t get_danio_al_jugador() const;
    uint16_t get_puntos() const;

    // Actualiza la posicion del enemigo
    void actualizar();

    // Mueve al enemigo
    void mover();

    // reduce vida al enemigo
    void recibir_disparo(uint8_t danio);

    // Aumenta las iteraciones del enemigo. Si llega a time_revive llama a revivir_enemigo
    void aumentar_iteraciones();

    // Pone vidas en 0
    void matar();

    // Revive al enemigo dependiendo de su tipo
    virtual void revivir_enemigo();

    // Devuelve true si el enemigo tiene vidas
    bool esta_vivo();

    // Destructor
    virtual ~Enemigo() = default;
};


// ************  ENEMIGO 1 ("nombre")  ************
class Enemigo1: public Enemigo {
public:
    explicit Enemigo1(uint16_t id, float x, float y);

    // Revive al enemigo
    void revivir_enemigo() override;
};


// ************  ENEMIGO 2 ("nombre")  ************
class Enemigo2: public Enemigo {
public:
    explicit Enemigo2(uint16_t id, float x, float y);

    // Revive al enemigo
    void revivir_enemigo() override;
};


// ************  ENEMIGO 3 ("nombre")  ************
class Enemigo3: public Enemigo {
public:
    explicit Enemigo3(uint16_t id, float x, float y);

    // Revive al enemigo
    void revivir_enemigo() override;
};

#endif
