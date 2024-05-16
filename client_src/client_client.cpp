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

void Client::jugar() {
    std::string accion_actual;
    int cant_lineas_a_leer;
    while (std::cin >> accion_actual) {
        accion_actual = toLowercase(accion_actual);
        if (accion_actual == "atacar") {
            atacar();
        } else if (accion_actual == "leer") {
            if (!(std::cin >> cant_lineas_a_leer)) {
                std::cout << "Error: No indicó la cantidad de líneas a leer" << std::endl;
                continue;
            }
            for (int n = 0; n < cant_lineas_a_leer; n++) {
                leer();
            }
        } else if (accion_actual == "salir") {
            return;
        } else {
            std::cout << "Error: Acción no reconocida" << std::endl;
        }
    }
}

void Client::atacar() { protocolo_client.enviar_accion_atacar(TipoAccion::Atacar); }

void Client::leer() {
    Respuesta respuesta;
    if (protocolo_client.recibir_respuesta(respuesta) == false) {
        return;
    } else {
        imprimir_respuesta(respuesta);
    }
}

void Client::imprimir_respuesta(const Respuesta& respuesta) {
    std::cout << "Un enemigo ha " + respuesta.tipo_evento + ". " +
                         std::to_string(respuesta.enemigos_vivos) + " vivo(s) y " +
                         std::to_string(respuesta.enemigos_muertos) + " muerto(s)."
              << std::endl;
}

Client::~Client() {}
