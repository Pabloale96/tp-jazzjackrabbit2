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

// ********************** PROTOCOLOS DE LOBBY **********************

uint8_t ProtocolServer::crear_partida(bool& was_closed) {
    uint8_t buffer = 0;
    socket_cliente.recvall(&buffer, sizeof(uint8_t), &was_closed);
    return buffer;
}

void ProtocolServer::recibir_nombre_partida(std::string& nombre_partida, bool& was_closed) {
    uint8_t nombre_partida_len = 0;
    socket_cliente.recvall(&nombre_partida_len, sizeof(uint8_t), &was_closed);
    if (was_closed) {
        return;
    }
    // TODO: mejorar esta parte para que no tenga limite de buffer
    char nombre_partida_buffer[256];
    socket_cliente.recvall(nombre_partida_buffer, nombre_partida_len, &was_closed);
    if (was_closed) {
        return;
    }
    nombre_partida_buffer[nombre_partida_len] = '\0';
    nombre_partida = nombre_partida_buffer;
}

void ProtocolServer::enviar_partidas_disponibles(GameloopMonitor& gameloop_monitor,
                                                 bool& was_closed) {
    std::map<uint16_t, std::string> partidas_disponibles;
    gameloop_monitor.obtener_partidas_disponibles(partidas_disponibles);
    uint16_t cant_partidas = partidas_disponibles.size();
    cant_partidas = htons(cant_partidas);
    socket_cliente.sendall(&cant_partidas, sizeof(uint16_t), &was_closed);
    if (was_closed) {
        return;
    }
    for (const auto& pair: partidas_disponibles) {
        uint16_t id = pair.first;
        id = htons(id);
        socket_cliente.sendall(&id, sizeof(uint16_t), &was_closed);
        if (was_closed) {
            return;
        }
        std::string nombre_partida = pair.second;
        uint8_t nombre_partida_len = nombre_partida.size();
        socket_cliente.sendall(&nombre_partida_len, sizeof(uint8_t), &was_closed);
        if (was_closed) {
            return;
        }
        socket_cliente.sendall(nombre_partida.c_str(), nombre_partida_len, &was_closed);
        if (was_closed) {
            return;
        }
    }
}

uint16_t ProtocolServer::recibir_id_partida(bool& was_closed) {
    uint16_t buffer = 0;
    socket_cliente.recvall(&buffer, sizeof(uint16_t), &was_closed);
    return buffer;
}

// ********************** PROTOCOLOS DE JUEGO **********************

void ProtocolServer::recibir_acciones_serializadas(bool& was_closed, uint8_t& mensaje_recibido) {
    if (was_closed) {
        return;
    }
    uint8_t buffer = 0;
    socket_cliente.recvall(&buffer, sizeof(uint8_t), &was_closed);
    mensaje_recibido = buffer;
}

std::unique_ptr<Comando> ProtocolServer::deserializar_acciones(const uint8_t& mensaje_recibido,
                                                               uint16_t cliente_id) {
    if (mensaje_recibido == DISPARAR) {
        std::unique_ptr<Comando> comando = std::make_unique<Disparar>();
        comando->set_client_id(cliente_id);
        return comando;
    }
    if (mensaje_recibido == MOVER_DERECHA) {
        std::unique_ptr<Comando> comando = std::make_unique<MoverDerecha>();
        comando->set_client_id(cliente_id);
        return comando;
    }
    if (mensaje_recibido == MOVER_DERECHA_RAPIDO) {
        std::unique_ptr<Comando> comando = std::make_unique<MoverDerechaRapido>();
        comando->set_client_id(cliente_id);
        return comando;
    }
    if (mensaje_recibido == MOVER_IZQUIERDA) {
        std::unique_ptr<Comando> comando = std::make_unique<MoverIzquierda>();
        comando->set_client_id(cliente_id);
        return comando;
    }
    if (mensaje_recibido == MOVER_IZQUIERDA_RAPIDO) {
        std::unique_ptr<Comando> comando = std::make_unique<MoverIzquierdaRapido>();
        comando->set_client_id(cliente_id);
        return comando;
    }
    if (mensaje_recibido == MOVER_ARRIBA) {
        std::unique_ptr<Comando> comando = std::make_unique<MoverArriba>();
        comando->set_client_id(cliente_id);
        return comando;
    }
    if (mensaje_recibido == MOVER_ABAJO) {
        std::unique_ptr<Comando> comando = std::make_unique<MoverAbajo>();
        comando->set_client_id(cliente_id);
        return comando;
    }
    if (mensaje_recibido == SALTAR) {
        std::unique_ptr<Comando> comando = std::make_unique<Saltar>();
        comando->set_client_id(cliente_id);
        return comando;
    }
    return nullptr;
}

std::unique_ptr<Comando> ProtocolServer::recibir_acciones(bool& was_closed, uint16_t cliente_id) {
    uint8_t mensaje_recibido = 0;
    recibir_acciones_serializadas(was_closed, mensaje_recibido);
    if (was_closed) {
        return nullptr;
    }
    return deserializar_acciones(mensaje_recibido, cliente_id);
}

void ProtocolServer::enviar_respuesta(GameState& msg, bool& was_closed) {
    // Envio el 0x06
    uint8_t mensaje = MENSAJE;
    socket_cliente.sendall(&mensaje, sizeof(uint8_t), &was_closed);
    if (was_closed) {
        return;
    }
    const std::map<uint16_t, Personaje>& diccionario_de_personajes =
            msg.obtener_diccionario_de_personajes();
    int cant_personajes = diccionario_de_personajes.size();
    cant_personajes = htons(cant_personajes);
    socket_cliente.sendall(&cant_personajes, sizeof(int), &was_closed);

    for (auto& pair: diccionario_de_personajes) {
        const Personaje& personaje = pair.second;
        // Envio el id del personaje
        uint16_t id_personaje = personaje.obtener_personaje_id();
        id_personaje = htons(id_personaje);
        socket_cliente.sendall(&id_personaje, sizeof(uint16_t), &was_closed);
        if (was_closed) {
            return;
        }
        // Envio la posicion del personaje
        uint16_t posicion_x = personaje.obtener_posicion().get_posicion_x();
        posicion_x = htons(posicion_x);
        socket_cliente.sendall(&posicion_x, sizeof(uint16_t), &was_closed);
        if (was_closed) {
            return;
        }
        uint16_t posicion_y = personaje.obtener_posicion().get_posicion_y();
        posicion_y = htons(posicion_y);
        socket_cliente.sendall(&posicion_y, sizeof(uint16_t), &was_closed);
        if (was_closed) {
            return;
        }

        /*

        uint8_t vida = personaje.obtener_vida();
        socket_cliente.sendall(&vida, sizeof(uint8_t), &was_closed);
        if (was_closed) {
            return;
        }

        uint8_t estado = personaje.obtener_estado();
        socket_cliente.sendall(&estado, sizeof(uint8_t), &was_closed);
        if (was_closed) {
            return;
        }
        */
    }
}

void ProtocolServer::cerrar_socket_cliente() {
    socket_cliente.shutdown(SHUT_RDWR);
    socket_cliente.close();
}

ProtocolServer::~ProtocolServer() {}
