#ifndef _GAME_ENEMIGO_H_
#define _GAME_ENEMIGO_H_

#include <cstdint>

#define ITERACIONES_PARA_REVIVIR 15

#define VIDAS_INICIALES 5
#define DANIO_INICIAL 1
#define PUNTOS_INICIALES_ENEMIGO 1
#define TIME_REVIVE_INICIAL 50

enum class TipoEnemigo { ENEMIGO1, ENEMIGO2, ENEMIGO3 };

class Enemigo {

private:
    TipoEnemigo tipo_enemigo;
    bool vivo;
    unsigned int iteraciones;
    uint16_t vidas;
    uint16_t danio_al_jugador;
    uint16_t puntos;
    // int time_revive;
    // float prob_municion;
    // float prob_vida;

public:
    // Constructor
    // Inicializa vivo en true y las iteraciones en 0
    Enemigo();

    void set_tipo_enemigo(TipoEnemigo tipo_enemigo);

    uint16_t get_vidas();
    uint16_t get_danio_al_jugador();
    uint16_t get_puntos();

    // Mata al enemigo
    void atacar_enemigo();

    // Aumenta las iteraciones del enemigo. Si llega a 15 llama a revivir_enemigo
    void aumentar_iteraciones();

    // Revive al enemigo
    void revivir_enemigo();

    // Devuelve true si el enemigo esta vivo
    bool esta_vivo();

    // Destructor
    virtual ~Enemigo() = default;
};

class Enemigo1: public Enemigo {
public:
    Enemigo1();
};

class Enemigo2: public Enemigo {
public:
    Enemigo2();
};

class Enemigo3: public Enemigo {
public:
    Enemigo3();
};

#endif
