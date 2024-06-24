#include "../../include/client_src/gui/gui_coleccionables.h"

ColecionablesGui::ColecionablesGui(ClaseTexturas& texturas, int x, int y):
        texturas(texturas), pos_x(x), pos_y(y) {}
ColecionablesGui::~ColecionablesGui() {}

void ColecionablesGui::show() { animacion.run(pos_x, pos_y, speed, frames, it); }

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
ZanahoriaGui::~ZanahoriaGui() {}

MonedaGui::MonedaGui(ClaseTexturas& texturas, int x, int y): ColecionablesGui(texturas, x, y) {
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
GemaGui::~GemaGui() {}
