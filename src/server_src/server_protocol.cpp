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

#include "../../include/common_src/catedra/liberror.h"
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

uint8_t ProtocolServer::recibir_personaje(bool& was_closed) {
    uint8_t buffer = 0;
    socket_cliente.recvall(&buffer, sizeof(uint8_t), &was_closed);
    switch (buffer) {
        case static_cast<uint8_t>(personajes::JAZZ):
            return static_cast<uint8_t>(personajes::JAZZ);
        case static_cast<uint8_t>(personajes::SPAZZ):
            return static_cast<uint8_t>(personajes::SPAZZ);
        case static_cast<uint8_t>(personajes::LORI):
            return static_cast<uint8_t>(personajes::LORI);
        default:
            return FALLO;
    }
}

void ProtocolServer::enviar_escenario(Game& game, bool& was_closed) {
    std::vector<Platform> plataformas = game.obtener_escenario().obtener_plataformas();
    msgEscenario msg_escenario(plataformas.size());

    if (was_closed) {
        return;
    }
    socket_cliente.sendall(&msg_escenario, sizeof(msg_escenario), &was_closed);
    for (uint16_t i = 0; i < plataformas.size(); i++) {
        msgPlataforma msg_plataforma(plataformas[i]);
        if (was_closed) {
            return;
        }
        socket_cliente.sendall(&msg_plataforma, sizeof(msg_plataforma), &was_closed);
    }
}

bool ProtocolServer::confirmar_fin_lobby(bool& was_closed) {
    uint8_t confirmacion = 0;
    if (was_closed) {
        return false;
    }
    socket_cliente.recvall(&confirmacion, sizeof(uint8_t), &was_closed);
    if (confirmacion != 1) {
        std::cout << "Error en la confirmacion del cliente" << std::endl;
        return false;
    }

    uint8_t fin = 1;
    if (was_closed) {
        return false;
    }
    socket_cliente.sendall(&fin, sizeof(fin), &was_closed);

    
    std::cout << "El jugador esta saliendo del lobby" << std::endl;
    return true;
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
        case static_cast<uint8_t>(acciones::MOVER_DERECHA):
            comando = std::make_unique<MoverDerecha>(cliente_id, mensaje_recibido.toggle);
            return comando;
        case static_cast<uint8_t>(acciones::MOVER_DERECHA_RAPIDO):
            comando = std::make_unique<MoverDerechaRapido>(cliente_id, mensaje_recibido.toggle);
            return comando;
        case static_cast<uint8_t>(acciones::MOVER_IZQUIERDA):
            comando = std::make_unique<MoverIzquierda>(cliente_id, mensaje_recibido.toggle);
            return comando;
        case static_cast<uint8_t>(acciones::MOVER_IZQUIERDA_RAPIDO):
            comando = std::make_unique<MoverIzquierdaRapido>(cliente_id, mensaje_recibido.toggle);
            return comando;
        case static_cast<uint8_t>(acciones::SALTAR):
            comando = std::make_unique<Saltar>(cliente_id, mensaje_recibido.toggle);
            return comando;

        case static_cast<uint8_t>(acciones::DISPARAR):
            comando = std::make_unique<Disparar>(cliente_id, mensaje_recibido.toggle);
            return comando;
        case static_cast<uint8_t>(acciones::ACCION_ESPECIAL):
            comando = std::make_unique<AccionEspecial>(cliente_id, mensaje_recibido.toggle);
            return comando;

        case static_cast<uint8_t>(acciones::KILL_ALL):
            comando = std::make_unique<KillAll>(cliente_id, mensaje_recibido.toggle);
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
        msgPersonaje personaje(pair.first, *(pair.second));

        if (was_closed) {
            return;
        }
        socket_cliente.sendall(&personaje, sizeof(personaje), &was_closed);
    }
    for (auto& pair: gameState.obtener_diccionario_de_enemigos()) {
        msgEnemigo enemigo(pair.first, pair.second);

        if (was_closed) {
            return;
        }
        socket_cliente.sendall(&enemigo, sizeof(enemigo), &was_closed);
    }
}

void ProtocolServer::cerrar_socket_cliente() {
    try {
        socket_cliente.shutdown(SHUT_RDWR);
    } catch (const LibError& err) {
        // Si ya estaba cerrado, no hago nada
    }
    socket_cliente.close();
}

ProtocolServer::~ProtocolServer() {}
