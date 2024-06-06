#include "../../include/client_src/client_protocol.h"

#include <cstring>
#include <iostream>
#include <sstream>

#include <arpa/inet.h>   // para usar htons()
#include <sys/socket.h>  // para usar el flag para hacer shutdown del socket

#include "../../include/common_src/protocol_utils.h"

ProtocolClient::ProtocolClient(const std::string& hostname, const std::string& servicio):
        socket_cliente(hostname.c_str(), servicio.c_str()), was_closed(false) {}

bool ProtocolClient::obtener_estado_de_la_conexion() { return was_closed; }

uint16_t ProtocolClient::recibir_id_jugador() {
    uint16_t id_jugador;
    if (was_closed) {
        return 0;
    }
    socket_cliente.recvall(&id_jugador, sizeof(uint16_t), &was_closed);
    return ntohs(id_jugador);
}

// ********************** PROTOCOLOS DE LOBBY **********************

bool ProtocolClient::enviar_personaje(const std::string& personaje) {
    uint8_t personaje_serializado;
    if (personaje == "j") {
        personaje_serializado = JAZZ;
    } else if (personaje == "s") {
        personaje_serializado = SPAZZ;
    } else if (personaje == "l") {
        personaje_serializado = LORI;
    } else {
        return false;  // Personaje no válido
    }
    socket_cliente.sendall(&personaje_serializado, sizeof(uint8_t), &was_closed);
    return true;
}

bool ProtocolClient::enviar_codigo_de_crear_partida() {
    uint8_t accion_serializada = CREAR_PARTIDA;
    if (was_closed) {
        return false;
    }
    socket_cliente.sendall(&accion_serializada, sizeof(uint8_t), &was_closed);
    if (was_closed) {
        return false;
    }
    return true;
}

bool ProtocolClient::crear_partida(std::string& nombre_partida) {
    uint8_t nombre_partida_len = nombre_partida.size();
    socket_cliente.sendall(&nombre_partida_len, sizeof(uint8_t), &was_closed);
    if (was_closed) {
        return false;
    }
    socket_cliente.sendall(nombre_partida.c_str(), nombre_partida_len, &was_closed);
    return true;
}

bool ProtocolClient::recibir_escenario(std::vector<msgPlataforma>& vec_plataforma) {

    msgEscenario escenario(0);

    uint16_t size = 0;
    if (was_closed) {
        return false;
    }
    socket_cliente.recvall(&escenario, sizeof(escenario), &was_closed);
    msgPlataforma plataforma;
    for (size_t i = 0; i < htons(escenario.cantidad_plataformas); i++) {
        if (was_closed) {
            return false;
        }
        socket_cliente.recvall(&plataforma, sizeof(plataforma), &was_closed);
        vec_plataforma.emplace_back(plataforma);
    }
    return true;
}

bool ProtocolClient::unirse_a_partida() {
    uint8_t accion_serializada = UNIRSE_A_PARTIDA;
    if (was_closed) {
        return false;
    }
    socket_cliente.sendall(&accion_serializada, sizeof(uint8_t), &was_closed);
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

// ********************** PROTOCOLOS DE JUEGO **********************

void ProtocolClient::enviar_accion(msgAccion& msg) {
    if (was_closed) {
        return;
    }
    socket_cliente.sendall(&msg, sizeof(msg), &was_closed);
}

bool ProtocolClient::recibir_respuesta(GameState& gameState, uint16_t& client_id) {
    msgGameState msg;
    if (was_closed) {
        return false;
    }
    socket_cliente.recvall(&msg, sizeof(msg), &was_closed);
    gameState.setGameState(msg.state_partida);
    client_id = msg.client_id;
    msgPersonaje personaje;
    for (size_t i = 0; i < msg.cantidad_personajes; i++) {
        if (was_closed) {
            return false;
        }
        socket_cliente.recvall(&personaje, sizeof(personaje), &was_closed);
        gameState.pushPersonajes(personaje.personaje);
    }

    return true;
}

void ProtocolClient::cerrar_socket() {
    socket_cliente.shutdown(SHUT_RDWR);
    socket_cliente.close();
}

ProtocolClient::~ProtocolClient() {}
