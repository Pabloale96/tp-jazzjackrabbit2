#include "client_client.h"

#include <cctype>  // std::tolower()
#include <iostream>
#include <sstream>

Client::Client(const std::string& hostname, const std::string& servicio):
        hostname(hostname),
        servicio(servicio),
        protocolo_client(hostname.c_str(), servicio.c_str()) {}

std::string toLowercase(const std::string& str) {
    std::string minusculas;
    for (char c: str) {
        minusculas += std::tolower(c);
    }
    return minusculas;
}

void Client::acciones_posibles() {
    std::cout << "Acciones posibles:" << std::endl;
    std::cout << "  - Disparar (s)" << std::endl;
    std::cout << "  - Derecha (r)" << std::endl;
    std::cout << "  - Derecha rápido (fr)" << std::endl;
    std::cout << "  - Izquierda (l)" << std::endl;
    std::cout << "  - Izquierda rápido (fl)" << std::endl;
    std::cout << "  - Arriba (u)" << std::endl;
    std::cout << "  - Abajo (d)" << std::endl;
    std::cout << "  - Saltar (j)" << std::endl;
    std::cout << "  - Leer <cant_lineas_leer>" << std::endl;
    std::cout << "  - Salir (q)" << std::endl;
}

void Client::jugar() {
    acciones_posibles();
    std::string accion_actual;
    int cant_lineas_a_leer;
    while (std::cin >> accion_actual) {
        accion_actual = toLowercase(accion_actual);
        if (accion_actual == "disparar" or accion_actual == "s") {
            disparar();
        } else if (accion_actual == "derecha" or accion_actual == "r") {
            moverDerecha();
        } else if (accion_actual == "izquierda" or accion_actual == "l") {
            moverIzquierda();
        } else if (accion_actual == "rapido derecha" or accion_actual == "fr") {
            moverDerechaRapido();
        } else if (accion_actual == "rapido izquierda" or accion_actual == "fl") {
            moverIzquierdaRapido();
        } else if (accion_actual == "arriba" or accion_actual == "u") {
            moverArriba();
        } else if (accion_actual == "abajo" or accion_actual == "d") {
            moverAbajo();
        } else if (accion_actual == "saltar" or accion_actual == "j") {
            saltar();
        } else if (accion_actual == "leer") {
            if (!(std::cin >> cant_lineas_a_leer)) {
                std::cout << "Error: No indicó la cantidad de líneas a leer" << std::endl;
                continue;
            }
            for (int n = 0; n < cant_lineas_a_leer; n++) {
                leer();
            }
        } else if (accion_actual == "salir" or accion_actual == "q") {
            return;
        } else {
            std::cout << "Error: Acción no reconocida" << std::endl;
        }
    }
}

void Client::disparar() { protocolo_client.enviar_accion(TipoAccion::Disparar); }

void Client::moverDerecha() { protocolo_client.enviar_accion(TipoAccion::MoverDerecha); }

void Client::moverIzquierda() { protocolo_client.enviar_accion(TipoAccion::MoverIzquierda); }

void Client::moverArriba() { protocolo_client.enviar_accion(TipoAccion::MoverArriba); }

void Client::moverAbajo() { protocolo_client.enviar_accion(TipoAccion::MoverAbajo); }

void Client::saltar() { protocolo_client.enviar_accion(TipoAccion::Saltar); }

void Client::moverDerechaRapido() {
    protocolo_client.enviar_accion(TipoAccion::MoverDerechaRapido);
}

void Client::moverIzquierdaRapido() {
    protocolo_client.enviar_accion(TipoAccion::MoverIzquierdaRapido);
}

void Client::leer() {
    Respuesta respuesta;
    if (protocolo_client.recibir_respuesta(respuesta) == false) {
        return;
    } else {
        imprimir_respuesta(respuesta);
    }
}

void Client::imprimir_respuesta(const Respuesta& respuesta) {
    std::cout << "El personaje está en la posición (" +
                         std::to_string(respuesta.posicion_x_personaje) + ", " +
                         std::to_string(respuesta.posicion_y_personaje) + " )."
              << std::endl;
}

Client::~Client() {}
