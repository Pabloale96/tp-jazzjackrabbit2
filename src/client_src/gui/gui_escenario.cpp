#include "../../include/client_src/gui/gui_escenario.h"

Escenario::Escenario(std::vector<PlatformGui>& plataformas): platforms(plataformas) {}
Escenario::~Escenario() {}

void Escenario::show() {
    for (size_t i = 0; i < platforms.size(); i++) {
        platforms[i].show();
    }
}
