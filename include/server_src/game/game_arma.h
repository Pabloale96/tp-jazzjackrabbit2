#ifndef GAME_ARMA_H
#define GAME_ARMA_H

#include <cstdint>
#include <memory>

class Arma {
protected:
    uint8_t nombre_arma;
    uint16_t cant_municiones;
    float vel_dis;
    float vel_proy;
    uint16_t dano;

public:
    Arma(uint16_t municion, uint8_t nombre, float vel_dis, float vel_proy, uint16_t dano);

    uint8_t obtener_nombre_arma() const;

    uint16_t obtener_municion() const;

    void set_municion(uint16_t municion);

    float obtener_vel_dis() const;

    float obtener_vel_proy() const;

    void disminuir_municion();

    std::unique_ptr<Arma> crear_arma(uint16_t municion, uint8_t nombre);

    virtual ~Arma() = default;
};

class ArmaInicial: public Arma {
public:
    ArmaInicial();
    explicit ArmaInicial(uint16_t municion);
};

class Arma1: public Arma {
public:
    Arma1();
    explicit Arma1(uint16_t municion);
};

class Arma2: public Arma {
public:
    Arma2();
    explicit Arma2(uint16_t municion);
};

#endif
