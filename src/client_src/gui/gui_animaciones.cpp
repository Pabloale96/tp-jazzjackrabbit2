#include "../../include/client_src/gui/gui_animaciones.h"


Animacion::~Animacion() {}

Animacion::Animacion() {}

void Animacion::setFlip(bool flip) { this->flip = flip; }


void Animacion::run(int pos_x, int pos_y, int speed, std::vector<Frame>& frames,
                    std::vector<Frame>::iterator& it) {
    if (it == frames.end()) {
        it = frames.begin();
    }
    //it->copy(flip, pos_x, pos_y);
    it->copyTest();
    if (contador % speed == 0) {
        it++;
    }
    contador++;
}
