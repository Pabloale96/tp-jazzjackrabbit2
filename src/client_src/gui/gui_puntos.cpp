#include "../../include/client_src/gui/gui_puntos.h"


PuntosGui::PuntosGui(ClaseTexturas& texturas, int puntos): texturas(texturas), puntos(puntos) {}

PuntosGui::~PuntosGui() {}


void PuntosGui::setPuntos(int puntos) { this->puntos = puntos; }
int PuntosGui::getPuntos() const { return puntos; }

void PuntosGui::show(int h_window) {

    std::stack<uint16_t> pilaCifras;
    uint16_t puntos_aux = puntos;
    int offset = h_window;
    if (puntos_aux == 0) {
        Frame frame = texturas.findFrame(puntos_aux);
        frame.copy(0, offset - frame.getH(), 0);
    }
    // Extraer las cifras y almacenarlas en una pila.
    while (puntos_aux > 0) {
        uint16_t cifra = puntos_aux % 10;  // Extraer la última cifra.
        pilaCifras.push(cifra);            // Almacenar en la pila.
        puntos_aux /= 10;                  // Eliminar la última cifra del número.
    }

    // Transferir las cifras de la pila al vector.
    while (!pilaCifras.empty()) {
        Frame frame = texturas.findFrame(pilaCifras.top());
        frame.copy(0, offset - frame.getH(), 0);
        offset += frame.getH();
        pilaCifras.pop();
    }
}
