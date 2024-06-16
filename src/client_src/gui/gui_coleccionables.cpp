#include "../../include/client_src/gui/gui_coleccionables.h"

Collecionables::Collecionables(int x, int y):pos_x(x),pos_y(y){}
Collecionables::~Collecionables(){}

void Collecionables::show(){
    animacion.run(pos_x, pos_y, speed, frames, it);
}

Municion::Municion( int x, int y):Collecionables(x,y){
    frames = texturas.findFrame(ZANAHORIA);
    it = frames.begin();
    speed =5;
}
Municion::~Municion(){}

Zanahoria::Zanahoria(int x, int y):Collecionables(x,y){
    frames = texturas.findFrame(ZANAHORIA);
    it = frames.begin();
    speed =5;
}
Zanahoria::~Zanahoria(){}

Moneda::Moneda(int x, int y):Collecionables(x,y){
    frames = texturas.findFrame(MONEDA);
    it = frames.begin();
    speed =5;
}
Moneda::~Moneda(){}

Gema::Gema(int x, int y):Collecionables(x,y){
    frames = texturas.findFrame(GEMA);
    it = frames.begin();
    speed =5;
}
Gema::~Gema(){}
