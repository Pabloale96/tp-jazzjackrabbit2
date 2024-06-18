#ifndef _SERVER_LOBBY_H
#define _SERVER_LOBBY_H

#include <memory>
#include <string>

#include "server_protocol.h"
#include "server_receiver.h"
#include "thread.h"

class Lobby: public Thread {
private:
    ProtocolServer& protocolo_server;
    bool& was_closed;
    GameloopMonitor& gameloop_monitor;
    uint16_t gameloop_id;
    uint16_t id_cliente;
    Queue<std::shared_ptr<GameState>>& server_msg;
    std::shared_ptr<ServerReceiver>& receiver;

public:
    Lobby(ProtocolServer& protocolo_server, bool& was_closed, GameloopMonitor& gameloop_monitor,
          uint16_t gameloop_id, uint16_t id_cliente, Queue<std::shared_ptr<GameState>>& server_msg,
          std::shared_ptr<ServerReceiver>& receiver);

    void run() override;

    void establecer_partida(GameloopMonitor& gameloop_monitor);

    uint16_t crear_partida(GameloopMonitor& gameloop_monitor, const std::string& nombre_partida);

    uint16_t joinearse_a_una_partida(GameloopMonitor& gameloop_monitor);

    ~Lobby();
};

#endif
