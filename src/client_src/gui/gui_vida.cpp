#include "../../include/client_src/gui/gui_vida.h"


VidaGui::VidaGui(ClaseTexturas& texturas, uint16_t vida, uint8_t tipo):
        texturas(texturas), vida(vida), tipo(tipo) {}

VidaGui::~VidaGui() {}

void VidaGui::show_icon() {

    switch (tipo) {
        case static_cast<uint8_t>(personajes::JAZZ):
            texturas.findFrame(ICON_JAZZ)->at(0).copy(0, 0, 0);
            break;
        case static_cast<uint8_t>(personajes::SPAZZ):
            texturas.findFrame(ICON_SPAZ)->at(0).copy(0, 0, 0);
            break;
        case static_cast<uint8_t>(personajes::LORI):
            texturas.findFrame(ICON_LORI)->at(0).copy(0, 0, 0);
            break;
        default:
            std::cerr << "Error: Tipo de personaje no válido" << std::endl;
            return;
    }
}

void VidaGui::setVida(uint16_t vida) {this->vida = vida;}
uint16_t VidaGui::getVida() const {return vida;}

void VidaGui::show_vida() {

    std::stack<uint16_t> pilaCifras;
    uint16_t vida_aux = vida;
    int offset = 50;
    if (vida_aux == 0) {
        Frame frame = texturas.findFrame(vida_aux);
        frame.copy(0, frame.getH() + offset, 0);
        offset += frame.getH();
    }
    // Extraer las cifras y almacenarlas en una pila.
    while (vida_aux > 0) {
        uint16_t cifra = vida_aux % 10;  // Extraer la última cifra.
        pilaCifras.push(cifra);          // Almacenar en la pila.
        vida_aux /= 10;                  // Eliminar la última cifra del número.
    }

    // Transferir las cifras de la pila al vector.
    while (!pilaCifras.empty()) {
        Frame frame = texturas.findFrame(pilaCifras.top());
        frame.copy(0, frame.getH() + offset, 0);
        offset += frame.getH();
        pilaCifras.pop();
    }
}

void VidaGui::run() {
    show_icon();
    show_vida();
}
