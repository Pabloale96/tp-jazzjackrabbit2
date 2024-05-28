#ifndef _GAME_ENEMIGO_H_
#define _GAME_ENEMIGO_H_

#include <cstdint>

#define ITERACIONES_PARA_REVIVIR 15

#define VIDAS_INICIALES 5
#define DANIO_INICIAL 1
#define PUNTOS_INICIALES_ENEMIGO 1
#define TIME_REVIVE_INICIAL 50

class Enemigo {

private:
    bool vivo;
    unsigned int iteraciones;
    uint16_t vidas;
    uint16_t danio;
    // int puntos;
    // int time_revive;
    // float prob_municion;
    // float prob_vida;

public:
    // Constructor
    // Inicializa vivo en true y las iteraciones en 0
    Enemigo();

    // Mata al enemigo
    void matar_enemigo();

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
