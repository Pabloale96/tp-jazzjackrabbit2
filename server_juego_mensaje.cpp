#include "server_juego_mensaje.h"

ServerJuegoMensaje::ServerJuegoMensaje(uint8_t accion, uint16_t enemigos_vivos,
                                       uint16_t enemigos_muertos):
        accion(accion), enemigos_vivos(enemigos_vivos), enemigos_muertos(enemigos_muertos) {}

void ServerJuegoMensaje::imprimir_mensaje() {
    std::string accion_string;
    if (accion == MATAR) {
        accion_string = "muerto";
    } else if (accion == REVIVIR) {
        accion_string = "revivido";
    }
    std::string msg = "Un enemigo ha " + accion_string + ". " + std::to_string(enemigos_vivos) +
                      " vivo(s) y " + std::to_string(enemigos_muertos) + " muerto(s).";
    std::cout << msg << std::endl;
}

uint8_t ServerJuegoMensaje::obtener_accion() { return accion; }

uint16_t ServerJuegoMensaje::obtener_enemigos_vivos() { return enemigos_vivos; }

uint16_t ServerJuegoMensaje::obtener_enemigos_muertos() { return enemigos_muertos; }

ServerJuegoMensaje::~ServerJuegoMensaje() {}
