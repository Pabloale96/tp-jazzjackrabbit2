#include "../../include/client_src/client.h"

#include <cctype>  // std::tolower()
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define MAX_TAM_COLA 1000
#define ANCHO_RESOLUCION 800
#define ALTO_RESOLUCION 600

Client::Client(const std::string& hostname, const std::string& servicio):
        hostname(hostname),
        servicio(servicio),
        protocolo_client(hostname.c_str(), servicio.c_str()),
        client_commands(MAX_TAM_COLA),
        sender(protocolo_client, client_commands),
        server_msg(MAX_TAM_COLA),
        receiver(protocolo_client, client_id, server_msg),
        client_off(false),
        gui(0, 0, ANCHO_RESOLUCION, ALTO_RESOLUCION, std::ref(client_off), std::ref(personaje),
            std::ref(client_commands)) {}

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
    imprimir_portada();
    std::cout << "Bienvenido al juego!" << std::endl;
}

void Client::crear_personaje() {
    std::cout << "Ingrese el nombre del personaje que desea utilizar" << std::endl;
    std::cout << "  - Jazz (j)" << std::endl;
    std::cout << "  - Spazz (s)" << std::endl;
    std::cout << "  - Lori (l)" << std::endl;
    std::cin >> personaje;
    personaje = toLowercase(personaje);
    if (protocolo_client.enviar_personaje(personaje) == false) {
        std::cout << "Error: No se pudo crear el personaje" << std::endl;
        return;
    }
    // protocolo_client.recibir_escenario(plataformas);
    gui.start();
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

/*void Client::acciones_posibles() {
    std::cout << "Acciones posibles:" << std::endl;
    std::cout << "  - Disparar (s)" << std::endl;
    std::cout << "  - Derecha (r)" << std::endl;
    std::cout << "  - Derecha rápido (fr)" << std::endl;
    std::cout << "  - Izquierda (l)" << std::endl;
    std::cout << "  - Izquierda rápido (fl)" << std::endl;
    std::cout << "  - Arriba (u)" << std::endl;
    std::cout << "  - Abajo (d)" << std::endl;
    std::cout << "  - Saltar (j)" << std::endl;
    std::cout << "  - Salir (q)" << std::endl;
}*/

void Client::iniciar_hilos() {
    sender.start();
    receiver.start();
}

void Client::jugar() {

    // ***************** LOBBY *****************
    imprimir_bienvenida();
    establecer_partida();
    crear_personaje();
    // gui.setEscenario(plataforma);

    //  ***************** JUEGO *****************
    iniciar_hilos();

    while (not client_off) {

        std::shared_ptr<GameState> respuesta = nullptr;
        while (server_msg.try_pop(respuesta)) {
            // TODO: aca se debería de actualizar el render
            gui.setGameState(*respuesta, client_id);

            if (respuesta->getJugando() == false) {
                std::cout << "La partida ha finalizado" << std::endl;
                // TODO: aca se deberían de mostrar las estadísticas
                mostrar_estadisticas(*respuesta);
                return;
            }
        }
    }
}

void Client::mostrar_estadisticas(const GameState& respuestas) const {
    // TODO: Habria q dejarla mas linda y que imprima en orden de puntos
    std::cout << "Estadísticas de la partida:" << std::endl;
    std::cout << "   PERSONAJE   |   PUNTOS" << std::endl;
    /*for (const auto& respuesta: respuestas.obtener_respuestas()) {
        std::cout << "   " << respuesta.obtener_id_personaje() << "   |   " <<
    respuesta.obtener_puntos() << std::endl;
    }*/
}

void Client::stop_hilos() {}

Client::~Client() {
    client_commands.close();
    server_msg.close();
    protocolo_client.cerrar_socket();
    sender.stop();
    receiver.stop();
    gui.stop();
    sender.join();
    receiver.join();
    gui.join();
}
