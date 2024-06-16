#include "../../include/client_src/gui/gui_coleccionables.h"

Colecionables::Colecionables(ClaseTexturas & texturas, int x, int y):
    texturas(texturas),
    pos_x(x),
    pos_y(y){}
Colecionables::~Colecionables(){}

void Colecionables::show(){
    animacion.run(pos_x, pos_y, speed, frames, it);
}

MunicionGui::MunicionGui( ClaseTexturas & texturas, int x, int y):Colecionables(texturas,x,y){
    frames = texturas.findFrame(ZANAHORIA);
    it = frames->begin();
    speed =5;
}
MunicionGui::~MunicionGui(){}

Zanahoria::Zanahoria(ClaseTexturas & texturas, int x, int y):Colecionables(texturas,x,y){
    frames = texturas.findFrame(ZANAHORIA);
    it = frames->begin();
    speed =5;
}
Zanahoria::~Zanahoria(){}

Moneda::Moneda(ClaseTexturas & texturas, int x, int y):Colecionables(texturas,x,y){
    frames = texturas.findFrame(MONEDA);
    it = frames->begin();
    speed =5;
}
Moneda::~Moneda(){}

Gema::Gema(ClaseTexturas & texturas, int x, int y):Colecionables(texturas,x,y){
    frames = texturas.findFrame(GEMA);
    it = frames->begin();
    speed =5;
}
Gema::~Gema(){}
