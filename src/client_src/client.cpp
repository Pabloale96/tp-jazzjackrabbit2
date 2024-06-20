#include "../../include/client_src/client.h"

#include <cctype>  // std::tolower()
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define MAX_TAM_COLA 100000
#define CLIENT_ID_NULO 0


Client::Client(const std::string& hostname, const std::string& servicio):
        hostname(hostname),
        servicio(servicio),
        protocolo_client(hostname.c_str(), servicio.c_str()),
        client_commands(MAX_TAM_COLA),
        sender(protocolo_client, client_commands),
        server_msg(MAX_TAM_COLA),
        receiver(protocolo_client, client_id, server_msg),
        client_off(false),
        client_id(CLIENT_ID_NULO),
        gui(0, 0, client_off, personaje, client_commands, plataformas, client_id) {}

void Client::imprimir_portada() {
    std::ifstream file("../docs/portada.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo 'portada.txt'" << std::endl;
    }
}

void Client::imprimir_bienvenida() {
    imprimir_portada();
    std::cout << "Bienvenido al juego!" << std::endl;
    client_id = protocolo_client.recibir_id_jugador();
    std::cout << "Su numero de jugador es: " << client_id << std::endl;
}

void Client::crear_personaje() {
    std::cout << "Ingrese el nombre del personaje que desea utilizar" << std::endl;
    std::cout << "  - Jazz (j)" << std::endl;
    std::cout << "  - Spazz (s)" << std::endl;
    std::cout << "  - Lori (l)" << std::endl;
    std::cin >> personaje;
    personaje = toLowercase(personaje);
    while (personaje != "j" && personaje != "s" && personaje != "l") {
        std::cout << "Error: Personaje no válido. Intente nuevamente" << std::endl;
        std::cin >> personaje;
        personaje = toLowercase(personaje);
    }
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
    if (protocolo_client.enviar_codigo_de_crear_partida() == false) {
        std::cout << "Error: No se pudo enviar el código de crear partida" << std::endl;
        return;
    } else if (protocolo_client.crear_partida(nombre_partida) == false) {
        std::cout << "Error: No se pudo crear la partida" << std::endl;
        return;
    }
}

void Client::unirse_a_partida() {
    if (protocolo_client.unirse_a_partida() == false) {
        std::cout << "Error: No se pudo joinear a la partida" << std::endl;
        return;
    }
    std::cout << "Espere un momento mientras buscamos las partidas disponibles para unirse..."
              << std::endl;
    std::map<uint16_t, std::string> partidas_disponibles;
    protocolo_client.recibir_partidas_disponibles(partidas_disponibles);
    if (partidas_disponibles.empty()) {
        std::cout << "No hay partidas disponibles para unirse" << std::endl;
        std::cout << "Creando una nueva partida..." << std::endl;
        crear_partida();
        return;
    } else {
        std::cout << "Estas son las partidas disponibles para unirse: " << std::endl;
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
            std::cout << "id partida: " << static_cast<int>(id_partida) << std::endl;
            protocolo_client.enviar_id_partida(id_partida);
            return;
        }
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

void Client::iniciar_hilos() {
    receiver.start();
    sender.start();
}

void Client::crear_escenario() {
    if (protocolo_client.recibir_escenario(plataformas) == false) {
        std::cout << "Error: No se pudo recibir el escenario" << std::endl;
        return;
    }
}

bool Client::cerrar_lobby() {
    if (protocolo_client.confirmar_fin_lobby() == false) {
        std::cout << "Error: No se pudo completar correctamente el inicio del juego. Por favor "
                     "cierre y vuelva a intentarlo. "
                  << std::endl;
        return false;
    }
    return true;
}

void Client::jugar() {

    // ***************** LOBBY *****************
    imprimir_bienvenida();
    establecer_partida();
    crear_personaje();
    std::cout << "Aguarda unos minutos mientras se completa el escenario..." << std::endl;
    crear_escenario();
    if (cerrar_lobby() == false) {
        return;
    }

    // ***************** JUEGO *****************
    std::cout << "Comienza la partida!" << std::endl;
    iniciar_hilos();

    gui.start();

    while (!client_off) {

        std::shared_ptr<GameStateClient> respuesta = nullptr;
        while (server_msg.try_pop(respuesta)) {
            gui.setGameState(*respuesta);
            respuesta->imprimir_cliente();

            if (respuesta->getJugando() == false) {
                std::cout << "La partida ha finalizado" << std::endl;
                // TODO: aca se deberían de mostrar las estadísticas
                mostrar_estadisticas(*respuesta);
                return;
            }
        }
    }
}

void Client::mostrar_estadisticas(const GameStateClient& respuestas) const {
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
