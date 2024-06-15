#include "../../client_src/gui/gui_enemigos.h"

EnemigosGui::EnemigosGui(uint16_t * msg):         
        id(msg[POS_ID_ENEMIGO]),
        tipo(msg[POS_TIPO_ENEMIGO]),
        pos_x(ntohs(msg[POS_POSX_ENEMIGO])),
        pos_y(ntohs(msg[POS_POSY_ENEMIGO])){}

EnemigosGui::~EnemigosGui(){}