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
    std::shared_ptr<ClaseTexturas> texturas;
    uint16_t id = 0x00;
    uint16_t tipo = 0x00;
    uint16_t pos_x = 0x0000;
    uint16_t pos_y = 0x0000;
    int speed = 0;
    Animacion enemigo;
    std::shared_ptr<std::vector<Frame>> frames;
    std::vector<Frame>::iterator it;

public:
    EnemigosGui() {}
    explicit EnemigosGui(msgEnemigo&);
    ~EnemigosGui();
    uint16_t get_id_enemigo() { return id; }
    void show();
};
class EnemigoGui1: public EnemigosGui {
private:
public:
    explicit EnemigoGui1(msgEnemigo&);
    ~EnemigoGui1();
};

class EnemigoGui2: public EnemigosGui {
private:
public:
    explicit EnemigoGui2(msgEnemigo&);
    ~EnemigoGui2();
};

class EnemigoGui3: public EnemigosGui {
private:
public:
    explicit EnemigoGui3(msgEnemigo&);
    ~EnemigoGui3();
};
#endif
