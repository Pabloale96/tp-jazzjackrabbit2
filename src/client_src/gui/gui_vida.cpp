#include "../../include/client_src/gui/gui_vida.h"


VidaGui::VidaGui(ClaseTexturas & texturas, uint16_t vida, std::shared_ptr<std::vector<Frame>> frame):
        texturas(texturas),vida(vida),frame(frame){
            it = frame.begin();
        }

VidaGui::~VidaGui(){}

void VidaGui::show_icon(int speed){
    if (it == frames->end()) {
        it = frames->begin();
    }
    it->copy(0,0,0,50,50);
    // it->copyTest();
    if (contador % speed == 0) {
        it++;
    }
    contador++;
}
void VidaGui::show_vida() {
    int offset = 0
    uint16_t vida_aux =vida;
    while (vida_aux > 0) {
        int cifra = vida_aux % 10;
        texturas.findNumber(cifra).copy(0,0,55+offset,10,10);
        offset+=10;
        vida_aux /= 10;
    }
}

void VidaGui::run(int speed){
    show_icon(speed);
    show_vida();
}