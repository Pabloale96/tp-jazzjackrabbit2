#include "../../include/client_src/gui/gui_municion.h"


CantidadMunicionGui::CantidadMunicionGui(ClaseTexturas& texturas, int municion, int tipo_arma): 
                texturas(texturas),
                municion(municion),
                tipo_arma(tipo_arma) {}

CantidadMunicionGui::~CantidadMunicionGui() {}


void CantidadMunicionGui::setMunicion(int municion) { this->municion = municion; }
int CantidadMunicionGui::getMunicion() const { return municion; }

void CantidadMunicionGui::setTipoArma(int tipo_arma) { this->tipo_arma = tipo_arma; }
int CantidadMunicionGui::getTipoArma() const { return tipo_arma; }

void CantidadMunicionGui::show(int w_window) {

    std::stack<uint16_t> pilaCifras;
    uint16_t municion_aux = municion;
    int offset = 30;
    if (municion_aux == 0) {
        Frame frame = texturas.findFrame(municion_aux);
        frame.copy(0, frame.getW() + offset,w_window-frame.getH()-10);
    }
    // Extraer las cifras y almacenarlas en una pila.
    while (municion_aux > 0) {
        uint16_t cifra = municion_aux % 10;  // Extraer la última cifra.
        pilaCifras.push(cifra);            // Almacenar en la pila.
        municion_aux /= 10;                  // Eliminar la última cifra del número.
    }

    // Transferir las cifras de la pila al vector.
    while (!pilaCifras.empty()) {
        Frame frame = texturas.findFrame(pilaCifras.top());
        frame.copy(0, frame.getW() + offset,w_window-frame.getH()-10);
        offset += frame.getW();
        pilaCifras.pop();
    }
}

void CantidadMunicionGui::showInf(int w_window) {
    Frame frame = texturas.findFrame(INFINITO);
    frame.copy(0, frame.getW(),w_window-frame.getH()-10);
}


void CantidadMunicionGui::run(int w_window) {
    if( tipo_arma == 1) {
        Frame frame = texturas.findFrame(ICON_ARMA1)->at(0);
        frame.copy(0, 0, w_window-frame.getH()-10);
        this->show(w_window);
    } else {
        Frame frame = texturas.findFrame(ICON_ARMA2)->at(0);
        frame.copy(0, 0, w_window-frame.getH()-10);
        this->showInf(w_window);
    }
}