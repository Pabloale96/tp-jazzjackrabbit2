#include "../../include/client_src/gui/gui_escenario.h"

Escenario::Escenario(std::vector<PlatformGui>& plataformas):
        platforms(plataformas) {}
Escenario::~Escenario() {}

void Escenario::show(int dif_x, int dif_y) {
    for (size_t i = 0; i < platforms.size(); i++) {
        platforms[i].show(dif_x, dif_y);
    }
}
