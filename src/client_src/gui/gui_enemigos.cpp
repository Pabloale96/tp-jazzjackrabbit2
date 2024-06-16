#include "../../client_src/gui/gui_enemigos.h"

EnemigosGui::EnemigosGui(msgEnemigo& msg):
        id(ntohs(msg.enemigo[POS_ID_ENEMIGO])),
        tipo(ntohs(msg.enemigo[POS_TIPO_ENEMIGO])),
        pos_x(ntohs(msg.enemigo[POS_POSX_ENEMIGO])),
        pos_y(ntohs(msg.enemigo[POS_POSY_ENEMIGO])) {}

EnemigosGui::~EnemigosGui() {}


EnemigoGui1::EnemigoGui1(msgEnemigo& msg):EnemigosGui(msg){
        frames = texturas.findFrame(ENEMIGO1);
        it = frames.begin();
        speed =5;
}
EnemigoGui1::~EnemigoGui1(){}

EnemigoGui2::EnemigoGui2(msgEnemigo& msg):EnemigosGui(msg){
        frames = texturas.findFrame(ENEMIGO2);
        it = frames.begin();
        speed =5;
}
EnemigoGui2::~EnemigoGui2(){}

EnemigoGui3::EnemigoGui3(msgEnemigo& msg):EnemigosGui(msg){
        frames = texturas.findFrame(ENEMIGO3);
        it = frames.begin();
        speed =5;
}
EnemigoGui3::~EnemigoGui3(){}