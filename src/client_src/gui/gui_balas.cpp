#include "../../include/client_src/gui/gui_balas.h"

BalasGui::BalasGui(ClaseTexturas& texturas, msgBalas& msg):
        texturas(texturas),
        pos_x((float)ntohs(msg.balas[POS_POSX_BALA]) / 100),
        pos_y((float)ntohs(msg.balas[POS_POSY_BALA]) / 100),
        frames(texturas.findFrame(BALA1)),
        it(frames->begin()) {}

BalasGui::~BalasGui() {}

void BalasGui::show() { animacion.run(pos_x, pos_y, 5, frames, it); }

void BalasGui::setPosicion(float x, float y) {
    pos_x = x;
    pos_y = y;
}


float BalasGui::obtener_posicion_x() { return pos_x; }
float BalasGui::obtener_posicion_y() { return pos_y; }

BalasGui1::BalasGui1(ClaseTexturas& texturas, msgBalas& msg): BalasGui(texturas, msg) {

    frames = texturas.findFrame(BALA1);
    it = frames->begin();
}

BalasGui1::~BalasGui1() {}

BalasGui2::BalasGui2(ClaseTexturas& texturas, msgBalas& msg): BalasGui(texturas, msg) {
    frames = texturas.findFrame(BALA2);
    it = frames->begin();
}

BalasGui2::~BalasGui2() {}
