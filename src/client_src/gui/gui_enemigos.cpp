#include "../../client_src/gui/gui_enemigos.h"

EnemigosGui::EnemigosGui(ClaseTexturas& texturas, msgEnemigo& msg):
        texturas(texturas),
        id(ntohs(msg.enemigo[POS_ID_ENEMIGO])),
        tipo(ntohs(msg.enemigo[POS_TIPO_ENEMIGO])),
        pos_x(ntohs(msg.enemigo[POS_POSX_ENEMIGO])/100),
        pos_y(ntohs(msg.enemigo[POS_POSY_ENEMIGO])/100) {}

EnemigosGui::~EnemigosGui() {}

void EnemigosGui::setPosicion(float x, float y) {
    pos_x = x;
    pos_y = y;
}

void EnemigosGui::show() { 
    animacion.run(pos_x, pos_y, speed, frames, it);
}

void EnemigosGui::actualizar_enemigo(const EnemigosGui& other){
    this->pos_x = other.obtener_posicion_x();
    this->pos_y = other.obtener_posicion_y();
    this->it++;
    if(this->it == frames->end()) {
        it = frames->begin();
    }
}

EnemigoGui1::EnemigoGui1(ClaseTexturas& texturas,msgEnemigo& msg): EnemigosGui(texturas,msg) {
    frames = texturas.findFrame(ENEMIGO1_GUI);
    it = frames->begin();
    speed = 100;
}
EnemigoGui1::~EnemigoGui1() {}

EnemigoGui2::EnemigoGui2(ClaseTexturas& texturas,msgEnemigo& msg): EnemigosGui(texturas,msg) {
    frames = texturas.findFrame(ENEMIGO2_GUI);
    it = frames->begin();
    speed = 100;
}
EnemigoGui2::~EnemigoGui2() {}

EnemigoGui3::EnemigoGui3(ClaseTexturas& texturas,msgEnemigo& msg): EnemigosGui(texturas,msg) {
    frames = texturas.findFrame(ENEMIGO3_GUI);
    it = frames->begin();
    speed = 100;
}
EnemigoGui3::~EnemigoGui3() {}
