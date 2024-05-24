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

void ProtocolClient::recibir_partidas_disponibles(
        std::map<uint16_t, std::string>& partidas_disponibles) {
    uint16_t cant_partidas;
    socket_cliente.recvall(&cant_partidas, sizeof(uint16_t), &was_closed);
    cant_partidas = ntohs(cant_partidas);
    if (was_closed) {
        return;
    }
    for (uint16_t i = 0; i < cant_partidas; i++) {
        uint16_t id_partida;
        socket_cliente.recvall(&id_partida, sizeof(uint16_t), &was_closed);
        id_partida = ntohs(id_partida);
        if (was_closed) {
            return;
        }
        uint8_t nombre_partida_len;
        socket_cliente.recvall(&nombre_partida_len, sizeof(uint8_t), &was_closed);
        if (was_closed) {
            return;
        }
        char nombre_partida_buffer[256];
        socket_cliente.recvall(nombre_partida_buffer, nombre_partida_len, &was_closed);
        if (was_closed) {
            return;
        }
        nombre_partida_buffer[nombre_partida_len] = '\0';
        partidas_disponibles[id_partida] = nombre_partida_buffer;
    }
}

void ProtocolClient::enviar_id_partida(uint16_t id_partida) {
    id_partida = htons(id_partida);
    socket_cliente.sendall(&id_partida, sizeof(uint16_t), &was_closed);
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

bool ProtocolClient::recibir_respuesta(ClientGameRespuesta& client_game_respuesta) {
    if (was_closed) {
        return false;
    }
    uint8_t codigo_mensaje;
    socket_cliente.recvall(&codigo_mensaje, sizeof(uint8_t), &was_closed);
    if (was_closed) {
        return false;
    }
    uint16_t cant_personajes;
    socket_cliente.recvall(&cant_personajes, sizeof(uint16_t), &was_closed);
    cant_personajes = ntohs(cant_personajes);
    if (was_closed) {
        return false;
    }
    for (size_t i = 0; i < cant_personajes; i++) {
        uint16_t id_personaje;
        uint16_t posicion_x;
        uint16_t posicion_y;
        socket_cliente.recvall(&id_personaje, sizeof(uint16_t), &was_closed);
        id_personaje = ntohs(id_personaje);
        if (was_closed) {
            return false;
        }
        socket_cliente.recvall(&posicion_x, sizeof(uint16_t), &was_closed);
        posicion_x = ntohs(posicion_x);
        if (was_closed) {
            return false;
        }
        socket_cliente.recvall(&posicion_y, sizeof(uint16_t), &was_closed);
        posicion_y = ntohs(posicion_y);
        if (was_closed) {
            return false;
        }
        Respuesta respuesta_actual(id_personaje, posicion_x, posicion_y);
        client_game_respuesta.agregar_respuesta(respuesta_actual);
    }
    return true;
}

ProtocolClient::~ProtocolClient() {}
