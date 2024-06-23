#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include <SDL2pp/SDL2pp.hh>
#include <arpa/inet.h>  // para usar htons()

#include "defines_msg.h"
#include "gui_animaciones.h"
#include "gui_clase_texturas.h"
#include "msgToSent.h"
#include "protocol_utils.h"

class EnemigosGui {
protected:
    ClaseTexturas & texturas;
    uint16_t id = 0x00;
    uint8_t tipo = 0x00;
    float pos_x;
    float pos_y;
    int speed = 0;
    Animacion animacion;
    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;

public:
    explicit EnemigosGui(ClaseTexturas&, msgEnemigo&);
    ~EnemigosGui();
    uint16_t get_id_enemigo() { return id; }
    float obtener_posicion_x() const { return pos_x; }
    float obtener_posicion_y() const { return pos_y; }
    uint8_t obtener_tipo_personaje() const { return tipo; }
    void show();
    void setPosicion(float x, float y);
    void actualizar_enemigo(const EnemigosGui&);
};
class EnemigoGui1: public EnemigosGui {
private:
public:
    explicit EnemigoGui1(ClaseTexturas&,msgEnemigo&);
    ~EnemigoGui1();
};

class EnemigoGui2: public EnemigosGui {
private:
public:
    explicit EnemigoGui2(ClaseTexturas&,msgEnemigo&);
    ~EnemigoGui2();
};

class EnemigoGui3: public EnemigosGui {
private:
public:
    explicit EnemigoGui3(ClaseTexturas&,msgEnemigo&);
    ~EnemigoGui3();
};
#endif
