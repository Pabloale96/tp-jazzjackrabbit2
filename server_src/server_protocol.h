#ifndef __PROTOCOL_SERVER_H__
#define __PROTOCOL_SERVER_H__

#include <memory>  // unique_ptr<>
#include <string>
#include <unordered_map>
#include <vector>

#include "../common_src/common_sockets.h"
#include "../server_src/game_comandos.h"
#include "../server_src/game_state.h"

class ProtocolServer {
private:
    Socket socket_cliente;

public:
    // Constructor
    explicit ProtocolServer(Socket&& socket_cliente);

    void establecer_partida();

    // Como no se cuantas acciones me va a mandar el cliente, itero hasta que
    // termine el receive
    void recibir_acciones_serializadas(bool& was_closed, uint8_t& mensaje_recibido);

    // Recibe las acciones del cliente, las deserializa y se las devuelve al
    // server
    std::unique_ptr<Comando> recibir_acciones(bool& was_closed);

    // Toma los valores del mensaje y los traduce a acciones
    std::unique_ptr<Comando> deserializar_acciones(const uint8_t& mensaje_recibido);

    void obtener_posicion_del_personaje(GameState& msg, std::vector<uint16_t>& posicion_personaje);

    // Para poder enviar comandos
    void enviar_respuesta(GameState& msg, bool& was_closed);

    // Cierra el socket del cliente ordenadamente
    void cerrar_socket_cliente();

    // Destructor
    ~ProtocolServer();
};

#endif
