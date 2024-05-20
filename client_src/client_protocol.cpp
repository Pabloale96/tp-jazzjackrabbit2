#include "client_protocol.h"

#include <cstring>
#include <iostream>
#include <sstream>

#include <arpa/inet.h>  // para usar htons()

#include "../common_src/common_protocol_utils.h"

#define MUERTO 0x04
#define REVIVIO 0x05

ProtocolClient::ProtocolClient(const std::string& hostname, const std::string& servicio):
        socket_cliente(hostname.c_str(), servicio.c_str()), was_closed(false) {}

void ProtocolClient::enviar_accion(TipoAccion accion) {
    uint8_t accion_serializada;
    switch (accion) {
        case TipoAccion::Atacar:
            accion_serializada = ATACAR;
            break;
        case TipoAccion::MoverDerecha:
            accion_serializada = MOVER_DERECHA;
            break;
        case TipoAccion::MoverIzquierda:
            accion_serializada = MOVER_IZQUIERDA;
            break;
        case TipoAccion::MoverArriba:
            accion_serializada = MOVER_ARRIBA;
            break;
        case TipoAccion::MoverAbajo:
            accion_serializada = MOVER_ABAJO;
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
    socket_cliente.recvall(&respuesta.enemigos_vivos, sizeof(uint16_t), &was_closed);
    respuesta.enemigos_vivos = ntohs(respuesta.enemigos_vivos);

    if (was_closed) {
        return false;
    }
    socket_cliente.recvall(&respuesta.enemigos_muertos, sizeof(uint16_t), &was_closed);
    respuesta.enemigos_muertos = ntohs(respuesta.enemigos_muertos);

    if (was_closed) {
        return false;
    }
    uint8_t tipo_evento_mensaje;
    socket_cliente.recvall(&tipo_evento_mensaje, sizeof(uint8_t), &was_closed);
    if (tipo_evento_mensaje == (uint8_t)MUERTO) {
        respuesta.tipo_evento = "muerto";
    } else if (tipo_evento_mensaje == (uint8_t)REVIVIO) {
        respuesta.tipo_evento = "revivido";
    }

    return true;
}

ProtocolClient::~ProtocolClient() {}
