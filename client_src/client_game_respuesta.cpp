#include "../client_src/client_game_respuesta.h"

ClientGameRespuesta::ClientGameRespuesta(/* args */) {}

void ClientGameRespuesta::agregar_respuesta(Respuesta& respuesta) {
    estado_juego.push_back(respuesta);
}

void ClientGameRespuesta::imprimir_respuesta() {
    for (const auto& resp: estado_juego) {
        std::cout << "El personaje " + std::to_string(resp.id_personaje) +
                             " está en la posición (" + std::to_string(resp.posicion_x) + ", " +
                             std::to_string(resp.posicion_y) + ")."
                  << std::endl;
    }
}

ClientGameRespuesta::~ClientGameRespuesta() {}
