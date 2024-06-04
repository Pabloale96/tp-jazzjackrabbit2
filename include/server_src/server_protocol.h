#ifndef __PROTOCOL_SERVER_H__
#define __PROTOCOL_SERVER_H__

#include <memory>  // unique_ptr<>
#include <string>
#include <unordered_map>
#include <vector>

#include "game_comandos.h"
#include "game_state.h"
#include "gameloop_monitor.h"
#include "msgToSent.h"
#include "sockets.h"

class ProtocolServer {
private:
    Socket socket_cliente;

public:
    // Constructor
    explicit ProtocolServer(Socket&& socket_cliente);

    uint8_t crear_partida(bool& was_closed);

    void recibir_nombre_partida(std::string& nombre_partida, bool& was_closed);

    void enviar_partidas_disponibles(GameloopMonitor& gameloop_monitor, bool& was_closed);

    void recibir_personaje(std::string& personaje, bool& was_closed);

    uint16_t recibir_id_partida(bool& was_closed);

    // Como no se cuantas acciones me va a mandar el cliente, itero hasta que
    // termine el receive
    void recibir_acciones_serializadas(bool& was_closed, msgAccion& mensaje_recibido);

    // Recibe las acciones del cliente, las deserializa y se las devuelve al
    // server
    std::unique_ptr<Comando> recibir_acciones(bool& was_closed, uint16_t id_cliente);

    // Toma los valores del mensaje y los traduce a acciones
    std::unique_ptr<Comando> deserializar_acciones(const msgAccion& mensaje_recibido,
                                                   uint16_t cliente_id);

    // Para poder enviar comandos
    void enviar_respuesta(GameState&, uint16_t, bool&);
    void enviar_respuesta(msgGameState&, bool&);

    // Cierra el socket del cliente ordenadamente
    void cerrar_socket_cliente();

    // Destructor
    ~ProtocolServer();
};

#endif