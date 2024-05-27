#ifndef __PROTOCOL_CLIENT_H__
#define __PROTOCOL_CLIENT_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "../client_src/client_game_respuesta.h"
#include "../common_src/common_sockets.h"

enum class TipoAccion : char {
    Disparar,
    MoverDerecha,
    MoverDerechaRapido,
    MoverIzquierda,
    MoverIzquierdaRapido,
    MoverArriba,
    MoverAbajo,
    Saltar
};

class ProtocolClient {
private:
    Socket socket_cliente;
    bool was_closed;

public:
    // Constructor
    // Carga en el diccionario las acciones posibles y su valor asociado
    ProtocolClient(const std::string& hostname, const std::string& servicio);

    bool crear_partida(std::string& nombre_partida);

    bool unirse_a_partida();

    bool enviar_personaje(const std::string& personaje);

    void recibir_partidas_disponibles(std::map<uint16_t, std::string>& partidas_disponibles);

    void enviar_id_partida(uint16_t id_partida);

    // Recibe del cliente la accion para serializar y enviar al server
    void enviar_accion(TipoAccion accion);

    // Envia las acciones ya con su valor asociado al server
    void enviar_accion_serializada(uint8_t accion_serializada, bool& was_closed);

    // Para poder recivir comandos
    bool recibir_respuesta(ClientGameRespuesta& game_respuesta);

    // Destructor
    ~ProtocolClient();
};

#endif
