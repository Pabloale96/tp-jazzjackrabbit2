#include "client_client.h"

#include <cctype>  // std::tolower()
#include <iostream>
#include <map>
#include <sstream>
#include <string>

Client::Client(const std::string& hostname, const std::string& servicio):
        hostname(hostname),
        servicio(servicio),
        protocolo_client(hostname.c_str(), servicio.c_str()) {}

void Client::imprimir_portada() {
    std::cout
            << "╔════════════════════════════════════════════════════════════════════════════════╗"
            << std::endl;
    std::cout
            << "║                                                                                ║"
            << std::endl;
    std::cout
            << "║                       ██╗ █████╗ ███████╗███████╗                              ║"
            << std::endl;
    std::cout
            << "║                       ██║██╔══██╗╚══███╔╝╚══███╔╝                              ║"
            << std::endl;
    std::cout
            << "║                       ██║███████║  ███╔╝   ███╔╝                               ║"
            << std::endl;
    std::cout
            << "║                  ██   ██║██╔══██║ ███╔╝   ███╔╝                                ║"
            << std::endl;
    std::cout
            << "║                  ╚█████╔╝██║  ██║███████╗███████╗                              ║"
            << std::endl;
    std::cout
            << "║                   ╚════╝ ╚═╝  ╚═╝╚══════╝╚══════╝                              ║"
            << std::endl;
    std::cout
            << "║       ██╗ █████╗  ██████╗██╗  ██╗██████╗  █████╗ ██████╗ ██████╗ ██╗████████╗  ║"
            << std::endl;
    std::cout
            << "║       ██║██╔══██╗██╔════╝██║ ██╔╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║╚══██╔══╝  ║"
            << std::endl;
    std::cout
            << "║       ██║███████║██║     █████╔╝ ██████╔╝███████║██████╔╝██████╔╝██║   ██║     ║"
            << std::endl;
    std::cout
            << "║  ██   ██║██╔══██║██║     ██╔═██╗ ██╔══██╗██╔══██║██╔══██╗██╔══██╗██║   ██║     ║"
            << std::endl;
    std::cout
            << "║  ╚█████╔╝██║  ██║╚██████╗██║  ██╗██║  ██║██║  ██║██████╔╝██████╔╝██║   ██║     ║"
            << std::endl;
    std::cout
            << "║   ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═════╝ ╚═╝   ╚═╝     ║"
            << std::endl;
    std::cout
            << "║                                  ██████╗                                       ║"
            << std::endl;
    std::cout
            << "║                                  ╚════██╗                                      ║"
            << std::endl;
    std::cout
            << "║                                   █████╔╝                                      ║"
            << std::endl;
    std::cout
            << "║                                  ██╔═══╝                                       ║"
            << std::endl;
    std::cout
            << "║                                  ███████╗                                      ║"
            << std::endl;
    std::cout
            << "║                                  ╚══════╝                                      ║"
            << std::endl;
    std::cout
            << "║                                                                                ║"
            << std::endl;
    std::cout
            << "╚════════════════════════════════════════════════════════════════════════════════╝"
            << std::endl;
}

void Client::imprimir_bienvenida() {
    // TODO: Volver a poner la portada (la saco para testear)
    // imprimir_portada();
    std::cout << "Bienvenido al juego!" << std::endl;
}

void Client::crear_personaje() {
    std::string personaje;
    std::cout << "Ingrese el nombre del personaje que desea utilizar" << std::endl;
    std::cout << "  - Jazz (j)" << std::endl;
    std::cout << "  - Spaz (s)" << std::endl;
    std::cout << "  - Lori (l)" << std::endl;
    std::cin >> personaje;
    personaje = toLowercase(personaje);
    if (protocolo_client.enviar_personaje(personaje) == false) {
        std::cout << "Error: No se pudo crear el personaje" << std::endl;
        return;
    }
}

void Client::crear_partida() {
    std::cout << "Ingrese el nombre de la partida que desea crear" << std::endl;
    std::string nombre_partida;
    std::cin.ignore();
    std::getline(std::cin, nombre_partida);
    if (protocolo_client.crear_partida(nombre_partida) == false) {
        std::cout << "Error: No se pudo crear la partida" << std::endl;
        return;
    }
}

void Client::unirse_a_partida() {
    if (protocolo_client.unirse_a_partida() == false) {
        std::cout << "Error: No se pudo joinear a la partida" << std::endl;
        return;
    }
    std::cout << "Estas son las partidas disponibles para unirse: " << std::endl;
    std::map<uint16_t, std::string> partidas_disponibles;
    protocolo_client.recibir_partidas_disponibles(partidas_disponibles);
    if (partidas_disponibles.empty()) {
        std::cout << "No hay partidas disponibles para unirse" << std::endl;
        return;
    }
    for (const auto& pair: partidas_disponibles) {
        std::cout << "   - ID: " << pair.first << " - Nombre: " << pair.second << std::endl;
    }
    std::cout << "Ingrese el ID de la partida a la que desea unirse" << std::endl;
    uint16_t id_partida;
    while (std::cin >> id_partida) {
        if (partidas_disponibles.find(id_partida) == partidas_disponibles.end()) {
            std::cout << "Error: ID de partida no válido. Intente nuevamente" << std::endl;
            continue;
        }
        protocolo_client.enviar_id_partida(id_partida);
        return;
    }
}

void Client::establecer_partida() {
    std::cout << "¿Desea crear una partida o ver las partidas disponibles para unirse?"
              << std::endl;
    std::cout << "Ingrese 'c' para crear una partida o 'j' para unirse a una partida" << std::endl;
    std::string accion_actual;
    while (std::cin >> accion_actual) {
        accion_actual = toLowercase(accion_actual);
        if (accion_actual == "c") {
            crear_partida();
            return;
        } else if (accion_actual == "j") {
            unirse_a_partida();
            return;
        } else {
            std::cout << "Error: Acción no reconocida" << std::endl;
        }
    }
}

std::string Client::toLowercase(const std::string& str) {
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
    imprimir_bienvenida();
    establecer_partida();
    crear_personaje();
    acciones_posibles();
    std::string accion_actual;
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
            leer();
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
    ClientGameRespuesta game_respuesta;
    if (protocolo_client.recibir_respuesta(game_respuesta) == false) {
        return;
    } else {
        game_respuesta.imprimir_respuesta();
    }
}

Client::~Client() {}
