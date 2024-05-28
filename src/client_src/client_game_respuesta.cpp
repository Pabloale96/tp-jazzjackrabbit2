#include "../client_src/client_game_respuesta.h"

ClientGameRespuesta::ClientGameRespuesta(/* args */) {}

void ClientGameRespuesta::agregar_respuesta(Respuesta& respuesta) {
    estado_juego.push_back(respuesta);
}

void ClientGameRespuesta::imprimir_respuesta() {
    for (const auto& resp: estado_juego) {
        std::cout << "El personaje " + std::to_string(resp.id_personaje) + " tiene:" << std::endl;
        std::cout << "  - Posición: (" << resp.posicion_x << ", " << resp.posicion_y << ")."
                  << std::endl;
        std::cout << "  - Puntos: " << resp.puntos << std::endl;
        std::cout << "  - Vida: " << resp.vida << std::endl;
        std::cout << "  - Municion: " << resp.municion << std::endl;
        std::cout << "  - Arma: " << resp.nombre_arma << std::endl;
    }
}

ClientGameRespuesta::~ClientGameRespuesta() {}
