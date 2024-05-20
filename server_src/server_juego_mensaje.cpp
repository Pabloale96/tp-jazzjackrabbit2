#include "../server_src/server_juego_mensaje.h"

ServerJuegoMensaje::ServerJuegoMensaje(Personaje personaje):
        personaje(personaje) {
            imprimir_mensaje();
        }

Personaje ServerJuegoMensaje::obtener_personaje() {
    return personaje;
}

void ServerJuegoMensaje::imprimir_mensaje() {
    std::string accion_string;
    std::string msg = "El personaje esta en la posicion: (" + std::to_string(personaje.obtener_posicion().get_posicion_x()) + ", " + std::to_string(personaje.obtener_posicion().get_posicion_y()) +
                      ")";
    std::cout << msg << std::endl;
}

ServerJuegoMensaje::~ServerJuegoMensaje() {}
