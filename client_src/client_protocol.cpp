#include "client_protocol.h"

#include <cstring>
#include <iostream>
#include <sstream>

#include <arpa/inet.h>  // para usar htons()

#include "../common_src/common_protocol_utils.h"

ProtocolClient::ProtocolClient(const std::string& hostname, const std::string& servicio):
        socket_cliente(hostname.c_str(), servicio.c_str()), was_closed(false) {}

bool ProtocolClient::crear_partida(std::string& nombre_partida) {
    uint8_t accion_serializada = CREAR_PARTIDA;
    enviar_accion_serializada(accion_serializada, was_closed);
    if (was_closed) {
        return false;
    }
    uint8_t nombre_partida_len = nombre_partida.size();
    socket_cliente.sendall(&nombre_partida_len, sizeof(uint8_t), &was_closed);
    if (was_closed) {
        return false;
    }
    socket_cliente.sendall(nombre_partida.c_str(), nombre_partida_len, &was_closed);
    return true;
}

bool ProtocolClient::unirse_a_partida() {
    uint8_t accion_serializada = UNIRSE_A_PARTIDA;
    enviar_accion_serializada(accion_serializada, was_closed);
    if (was_closed) {
        return false;
    }
    return true;
}

void ProtocolClient::recibir_partidas_disponibles() {
    bool was_closed = false;
    uint8_t cantidad_partidas;
    socket_cliente.recvall(&cantidad_partidas, sizeof(uint8_t), &was_closed);
    if (was_closed) {
        return;
    }
    cantidad_partidas = ntohs(cantidad_partidas);
    std::cout << "Cantidad de partidas disponibles: " << (int)cantidad_partidas << std::endl;
    for (int i = 0; i < cantidad_partidas; i++) {
        uint8_t nombre_partida_len;
        socket_cliente.recvall(&nombre_partida_len, sizeof(uint8_t), &was_closed);
        if (was_closed) {
            return;
        }
        char nombre_partida[256];
        socket_cliente.recvall(nombre_partida, nombre_partida_len, &was_closed);
        if (was_closed) {
            return;
        }
        nombre_partida[nombre_partida_len] = '\0';
        std::cout << "Partida " << i + 1 << ": " << nombre_partida << std::endl;
    }
}

void ProtocolClient::enviar_accion(TipoAccion accion) {
    uint8_t accion_serializada;
    switch (accion) {
        case TipoAccion::Disparar:
            accion_serializada = DISPARAR;
            break;
        case TipoAccion::MoverDerecha:
            accion_serializada = MOVER_DERECHA;
            break;
        case TipoAccion::MoverDerechaRapido:
            accion_serializada = MOVER_DERECHA_RAPIDO;
            break;
        case TipoAccion::MoverIzquierda:
            accion_serializada = MOVER_IZQUIERDA;
            break;
        case TipoAccion::MoverIzquierdaRapido:
            accion_serializada = MOVER_IZQUIERDA_RAPIDO;
            break;
        case TipoAccion::MoverArriba:
            accion_serializada = MOVER_ARRIBA;
            break;
        case TipoAccion::MoverAbajo:
            accion_serializada = MOVER_ABAJO;
            break;
        case TipoAccion::Saltar:
            accion_serializada = SALTAR;
            break;
        default:
            return;  // Acción no válida
    }
    enviar_accion_serializada(accion_serializada, was_closed);
}

void ProtocolClient::enviar_accion_serializada(uint8_t accion_serializada, bool& was_closed) {
    if (was_closed) {
        return;
    }
    socket_cliente.sendall(&accion_serializada, sizeof(uint8_t), &was_closed);
}

bool ProtocolClient::recibir_respuesta(Respuesta& respuesta) {
    if (was_closed) {
        return false;
    }
    uint8_t codigo_mensaje;
    socket_cliente.recvall(&codigo_mensaje, sizeof(uint8_t), &was_closed);

    if (was_closed) {
        return false;
    }
    socket_cliente.recvall(&respuesta.posicion_x_personaje, sizeof(uint16_t), &was_closed);
    respuesta.posicion_x_personaje = ntohs(respuesta.posicion_x_personaje);

    if (was_closed) {
        return false;
    }
    socket_cliente.recvall(&respuesta.posicion_y_personaje, sizeof(uint16_t), &was_closed);
    respuesta.posicion_y_personaje = ntohs(respuesta.posicion_y_personaje);

    if (was_closed) {
        return false;
    }
    return true;
}

ProtocolClient::~ProtocolClient() {}
