#include "../../include/client_src/gui/gui_animaciones.h"


Animacion::~Animacion() {}

Animacion::Animacion() {}

void Animacion::setFlip(bool flip) { this->flip = flip; }

void Animacion::run(int pos_x, int pos_y, std::vector<Frame>& frames,
                    std::vector<Frame>::iterator& it) {

    if (it == frames.end()) {
        it = frames.begin();
    }
    it->copy(flip, pos_x,
             pos_y);  // esto acelera la animacion y necesito hacer algo como el codigo (*)
    it++;
}

//(*)(*)(*)(*)(*)(*)
/*
void Animacion::run(int pos_x,int pos_y){
   frames[scr_x/2%frames.size()].copy(flip,pos_x,pos_y);
   scr_x++; // cambiar por it.
   if (scr_x == frames.size()) scr_x=0;
}
*/
