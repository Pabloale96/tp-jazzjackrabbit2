#include "../../include/server_src/server_protocol.h"

#include <algorithm>  // transform()
#include <cstring>
#include <iostream>
#include <iterator>  // back_inserter()
#include <sstream>
#include <string>
#include <utility>  // move()

#include <arpa/inet.h>   // htons()
#include <sys/socket.h>  // para usar el flag para hacer shutdown del socket

#include "../../include/common_src/protocol_utils.h"

#define MUERTO 0x04
#define REVIVIO 0x05
#define MENSAJE 0x06

#define FALLO 0x00

ProtocolServer::ProtocolServer(Socket&& socket_cliente):
        socket_cliente(std::move(socket_cliente)) {}

void ProtocolServer::enviar_id_jugador(uint16_t id_cliente, bool& was_closed) {
    id_cliente = htons(id_cliente);
    socket_cliente.sendall(&id_cliente, sizeof(uint16_t), &was_closed);
}


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
    nombre_partida.resize(nombre_partida_len);
    socket_cliente.recvall(&nombre_partida[0], nombre_partida_len * sizeof(uint8_t), &was_closed);
}

uint8_t ProtocolServer::enviar_partidas_disponibles(GameloopMonitor& gameloop_monitor,
                                                    bool& was_closed) {
    std::map<uint16_t, std::string> partidas_disponibles;
    gameloop_monitor.obtener_partidas_disponibles(partidas_disponibles);
    uint16_t cant_partidas = partidas_disponibles.size();
    cant_partidas = htons(cant_partidas);
    socket_cliente.sendall(&cant_partidas, sizeof(uint16_t), &was_closed);
    if (cant_partidas == 0) {
        // Si no hay partidas disponibles, se pasa a crear partida
        return CREAR_PARTIDA;
    }
    if (was_closed) {
        return FALLO;
    }
    for (const auto& pair: partidas_disponibles) {
        uint16_t id = pair.first;
        id = htons(id);
        socket_cliente.sendall(&id, sizeof(uint16_t), &was_closed);

        if (was_closed) {
            return FALLO;
        }
        std::string nombre_partida = pair.second;
        uint8_t nombre_partida_len = nombre_partida.size();
        socket_cliente.sendall(&nombre_partida_len, sizeof(uint8_t), &was_closed);
        if (was_closed) {
            return FALLO;
        }
        socket_cliente.sendall(nombre_partida.c_str(), nombre_partida_len, &was_closed);
        if (was_closed) {
            return FALLO;
        }
    }
    return UNIRSE_A_PARTIDA;
}

uint16_t ProtocolServer::recibir_id_partida(bool& was_closed) {
    uint16_t buffer = 0;
    socket_cliente.recvall(&buffer, sizeof(uint16_t), &was_closed);
    buffer = ntohs(buffer);
    return buffer;
}

void ProtocolServer::recibir_personaje(std::string& personaje, bool& was_closed) {
    uint8_t buffer = 0;
    socket_cliente.recvall(&buffer, sizeof(uint8_t), &was_closed);
    if (buffer == JAZZ) {
        personaje = "jazz";
    } else if (buffer == SPAZZ) {
        personaje = "spazz";
    } else if (buffer == LORI) {
        personaje = "lori";
    }
}

// ********************** PROTOCOLOS DE JUEGO **********************

void ProtocolServer::recibir_acciones_serializadas(bool& was_closed, msgAccion& mensaje_recibido) {
    if (was_closed) {
        return;
    }
    msgAccion buffer;
    socket_cliente.recvall(&buffer, sizeof(buffer), &was_closed);
    mensaje_recibido = buffer;
}

std::unique_ptr<Comando> ProtocolServer::deserializar_acciones(const msgAccion& mensaje_recibido,
                                                               uint16_t cliente_id) {

    std::unique_ptr<Comando> comando = nullptr;
    switch (mensaje_recibido.accion) {
        case DISPARAR:
            comando = std::make_unique<Disparar>();
            comando->set_client_id(cliente_id);
            comando->set_toggle(mensaje_recibido.toggle);
            return comando;
        case MOVER_DERECHA:
            comando = std::make_unique<MoverDerecha>();
            comando->set_client_id(cliente_id);
            comando->set_toggle(mensaje_recibido.toggle);
            return comando;
        case MOVER_DERECHA_RAPIDO:
            comando = std::make_unique<MoverDerechaRapido>();
            comando->set_client_id(cliente_id);
            comando->set_toggle(mensaje_recibido.toggle);
            return comando;
        case MOVER_IZQUIERDA:
            comando = std::make_unique<MoverIzquierda>();
            comando->set_client_id(cliente_id);
            comando->set_toggle(mensaje_recibido.toggle);
            return comando;
        case MOVER_IZQUIERDA_RAPIDO:
            comando = std::make_unique<MoverIzquierdaRapido>();
            comando->set_client_id(cliente_id);
            comando->set_toggle(mensaje_recibido.toggle);
            return comando;
        case MOVER_ARRIBA:
            comando = std::make_unique<MoverArriba>();
            comando->set_client_id(cliente_id);
            comando->set_toggle(mensaje_recibido.toggle);
            return comando;
        case MOVER_ABAJO:
            comando = std::make_unique<MoverAbajo>();
            comando->set_client_id(cliente_id);
            comando->set_toggle(mensaje_recibido.toggle);
            return comando;
        case SALTAR:
            comando = std::make_unique<Saltar>();
            comando->set_client_id(cliente_id);
            comando->set_toggle(mensaje_recibido.toggle);
            return comando;

        default:
            return nullptr;
    }
}

std::unique_ptr<Comando> ProtocolServer::recibir_acciones(bool& was_closed, uint16_t cliente_id) {
    msgAccion mensaje_recibido;
    recibir_acciones_serializadas(was_closed, mensaje_recibido);
    if (was_closed) {
        return nullptr;
    }
    return deserializar_acciones(mensaje_recibido, cliente_id);
}

void ProtocolServer::enviar_respuesta(GameState& gameState, uint16_t cliente_id, bool& was_closed) {
    msgGameState msg(gameState, cliente_id);
    if (was_closed) {
        return;
    }
    socket_cliente.sendall(&msg, sizeof(msg), &was_closed);

    for (auto& pair: gameState.obtener_diccionario_de_personajes()) {
        msgPersonaje personaje(pair.first, pair.second);

        if (was_closed) {
            return;
        }
        socket_cliente.sendall(&personaje, sizeof(personaje), &was_closed);
    }
}

void ProtocolServer::enviar_escenario(Game& game, bool& was_closed) {
    std::vector<Platform> plataformas = game.obtener_plataformas();
    msgEscenario msg_escenario(plataformas.size());

    if (was_closed) {
        return;
    }
    socket_cliente.sendall(&msg_escenario, sizeof(msg_escenario), &was_closed);
    for (int i = 0; i < plataformas.size(); i++) {
        msgPlataforma msg_plataforma(plataformas[i]);
        if (was_closed) {
            return;
        }
        socket_cliente.sendall(&msg_plataforma, sizeof(msg_plataforma), &was_closed);
    }
}

void ProtocolServer::cerrar_socket_cliente() {
    socket_cliente.shutdown(SHUT_RDWR);
    socket_cliente.close();
}

ProtocolServer::~ProtocolServer() {}
