#include "../../include/client_src/gui/gui_coleccionables.h"

ColecionablesGui::ColecionablesGui(ClaseTexturas& texturas, int x, int y):
        texturas(texturas), pos_x(x), pos_y(y) {}
ColecionablesGui::~ColecionablesGui() {}

ColecionablesGui::ColecionablesGui(ClaseTexturas& texturas, msgColecionables& msg):
        texturas(texturas),
        pos_x((float)ntohs(msg.coleccionables[POS_POSX_COLECCIONABLE])/100),
        pos_y((float)ntohs(msg.coleccionables[POS_POSY_COLECCIONABLE])/100) {}

void ColecionablesGui::show() { animacion.run(pos_x, pos_y, speed, frames, it); }

void ColecionablesGui::setPosicion(float x, float y){
    pos_x = x;
    pos_y = y;
}
float ColecionablesGui::obtener_posicion_x() {return pos_x;}
float ColecionablesGui::obtener_posicion_y() {return pos_y;}

MunicionGui::MunicionGui(ClaseTexturas& texturas, int x, int y): ColecionablesGui(texturas, x, y) {
    frames = texturas.findFrame(ZANAHORIA);
    it = frames->begin();
    speed = 5;
}
MunicionGui::~MunicionGui() {}

ZanahoriaGui::ZanahoriaGui(ClaseTexturas& texturas, int x, int y):
        ColecionablesGui(texturas, x, y) {
    frames = texturas.findFrame(ZANAHORIA);
    it = frames->begin();
    speed = 5;
}

ZanahoriaGui::ZanahoriaGui(ClaseTexturas& texturas, msgColecionables& msg):
        ColecionablesGui(texturas, msg) {
    frames = texturas.findFrame(ZANAHORIA);
    it = frames->begin();
    speed = 5;
}
ZanahoriaGui::~ZanahoriaGui() {}

MonedaGui::MonedaGui(ClaseTexturas& texturas, int x, int y): ColecionablesGui(texturas, x, y) {
    frames = texturas.findFrame(MONEDA);
    it = frames->begin();
    speed = 5;
}


MonedaGui::MonedaGui(ClaseTexturas& texturas, msgColecionables& msg):
        ColecionablesGui(texturas, msg) {
    frames = texturas.findFrame(MONEDA);
    it = frames->begin();
    speed = 5;
}

MonedaGui::~MonedaGui() {}

GemaGui::GemaGui(ClaseTexturas& texturas, int x, int y): ColecionablesGui(texturas, x, y) {
    frames = texturas.findFrame(GEMA);
    it = frames->begin();
    speed = 5;
}

GemaGui::GemaGui(ClaseTexturas& texturas, msgColecionables& msg):
        ColecionablesGui(texturas, msg) {
    frames = texturas.findFrame(GEMA);
    it = frames->begin();
    speed = 5;
}
GemaGui::~GemaGui() {}
