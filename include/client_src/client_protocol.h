#ifndef __PROTOCOL_CLIENT_H__
#define __PROTOCOL_CLIENT_H__

#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "../common_src/vector_monitor.h"
#include "gui/gui_clase_texturas.h"
#include "gui/gui_platform.h"

#include "game_state_client.h"
#include "sockets.h"

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

    // Devuelve el estado de was_closed
    bool obtener_estado_de_la_conexion();

    uint16_t recibir_id_jugador();

    bool enviar_codigo_de_crear_partida();

    bool crear_partida(std::string& nombre_partida);

    bool unirse_a_partida();

    bool enviar_personaje(const std::string& personaje);

    void recibir_partidas_disponibles(std::map<uint16_t, std::string>& partidas_disponibles);

    void enviar_id_partida(uint16_t id_partida);

    bool recibir_escenario(GameStateClient& gamestate);

    bool confirmar_fin_lobby();

    // Recibe del cliente la accion para serializar y enviar al server
    void enviar_accion(msgAccion& msg);

    // Para poder recivir comandos
    void recibir_respuesta(std::shared_ptr<GameStateClient>& gameState, uint16_t& client_id);

    void cerrar_socket();

    // Destructor
    ~ProtocolClient();
};

#endif
