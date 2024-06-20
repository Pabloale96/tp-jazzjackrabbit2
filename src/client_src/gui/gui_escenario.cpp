#include "../../include/client_src/gui/gui_escenario.h"

Escenario::Escenario(VectorMonitor<std::shared_ptr<PlatformGui>>& plataformas):
        platforms(plataformas) {

    for (size_t i = 0; i < plataformas.size(); i++) {
        std::cout << "( " << plataformas[i]->getX() << ", " << plataformas[i]->getY() << ", "
                  << plataformas[i]->getW() << ", " << plataformas[i]->getH() << " )" << std::endl;
    }
}
Escenario::~Escenario() {}

void Escenario::show(int dif_x, int dif_y) {
    for (size_t i = 0; i < platforms.size(); i++) {
        platforms[i]->show(dif_x, dif_y, i);
    }
}
