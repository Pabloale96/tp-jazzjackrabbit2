#include "../server_src/server_protocol.h"

#include <algorithm>  // transform()
#include <cstring>
#include <iostream>
#include <iterator>  // back_inserter()
#include <sstream>
#include <string>
#include <utility>  // move()

#include <arpa/inet.h>   // htons()
#include <sys/socket.h>  // para usar el flag para hacer shutdown del socket

#include "../common_src/common_protocol_utils.h"

#define MUERTO 0x04
#define REVIVIO 0x05
#define MENSAJE 0x06

#define FALLO 0x00

ProtocolServer::ProtocolServer(Socket&& socket_cliente):
        socket_cliente(std::move(socket_cliente)) {}

void ProtocolServer::recibir_acciones_serializadas(bool& was_closed, uint8_t& mensaje_recibido) {
    if (was_closed) {
        return;
    }
    uint8_t buffer = 0;
    socket_cliente.recvall(&buffer, sizeof(uint8_t), &was_closed);
    mensaje_recibido = buffer;
}

std::unique_ptr<Comando> ProtocolServer::deserializar_acciones(const uint8_t& mensaje_recibido) {
    if (mensaje_recibido == ATACAR) {
        return std::make_unique<Atacar>();
    }
    if (mensaje_recibido == MOVER_DERECHA) {
        return std::make_unique<MoverDerecha>();
    }
    if (mensaje_recibido == MOVER_IZQUIERDA) {
        return std::make_unique<MoverIzquierda>();
    }
    if (mensaje_recibido == MOVER_ARRIBA) {
        return std::make_unique<MoverArriba>();
    }
    if (mensaje_recibido == MOVER_ABAJO) {
        return std::make_unique<MoverAbajo>();
    }
    return nullptr;
}

std::unique_ptr<Comando> ProtocolServer::recibir_acciones(bool& was_closed) {
    uint8_t mensaje_recibido = 0;
    recibir_acciones_serializadas(was_closed, mensaje_recibido);
    if (was_closed) {
        return nullptr;
    }
    return deserializar_acciones(mensaje_recibido);
}

void ProtocolServer::obtener_estado_enemigos_del_msg(ServerJuegoMensaje& msg,
                                                     std::vector<uint16_t>& estado_enemigos) {
    estado_enemigos.push_back(msg.obtener_enemigos_vivos());
    estado_enemigos.push_back(msg.obtener_enemigos_muertos());
}

uint8_t ProtocolServer::obtener_tipo_evento_del_msg(ServerJuegoMensaje& msg) {
    return msg.obtener_accion();
}

void ProtocolServer::enviar_respuesta(ServerJuegoMensaje& msg, bool& was_closed) {
    // Envio el 0x06
    uint8_t mensaje = MENSAJE;
    socket_cliente.sendall(&mensaje, sizeof(uint8_t), &was_closed);

    // Envio la cant de enemigos vivos y muertos
    std::vector<uint16_t> estado_enemigos;
    obtener_estado_enemigos_del_msg(msg, estado_enemigos);

    uint16_t vivos = htons(estado_enemigos[0]);
    socket_cliente.sendall(&vivos, sizeof(uint16_t), &was_closed);

    uint16_t muertos = htons(estado_enemigos[1]);
    socket_cliente.sendall(&muertos, sizeof(uint16_t), &was_closed);

    // Envio el tipo de evento
    uint8_t evento = obtener_tipo_evento_del_msg(msg);
    socket_cliente.sendall(&evento, sizeof(uint8_t), &was_closed);
}

void ProtocolServer::cerrar_socket_cliente() {
    socket_cliente.shutdown(SHUT_RDWR);
    socket_cliente.close();
}

ProtocolServer::~ProtocolServer() {}
