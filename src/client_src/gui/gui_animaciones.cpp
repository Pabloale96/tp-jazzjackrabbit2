#include "../../include/client_src/gui/gui_animaciones.h"


Animacion::~Animacion() {}

Animacion::Animacion() {}

void Animacion::setFlip(bool flip) { this->flip = flip; }

void Animacion::run(int pos_x, int pos_y, std::vector<Frame>& frames) {
    frames[scr_x].copy(flip, pos_x - frames[scr_x].getW() / 2, pos_y - frames[scr_x].getH() / 2);
    scr_x++;
    if (scr_x == frames.size())
        scr_x = 0;
}
/*
void Animacion::run(int pos_x,int pos_y){
   frames[scr_x/2%frames.size()].copy(flip,pos_x,pos_y);
   scr_x++; // cambiar por it.
   if (scr_x == frames.size()) scr_x=0;
}
*/
