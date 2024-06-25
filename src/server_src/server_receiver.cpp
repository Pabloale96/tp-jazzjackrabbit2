#include "../../include/server_src/server_receiver.h"

#include <memory>
#include <string>
#include <utility>  // move()
#include <vector>

#include "../../include/common_src/catedra/liberror.h"
#include "../../include/server_src/game/gameloop_class.h"
#include "../../include/server_src/server_protocol.h"

ServerReceiver::ServerReceiver(ProtocolServer& protocolo_server, bool& was_closed,
                               GameloopMonitor& gameloop_monitor, uint16_t gameloop_id,
                               uint16_t cliente_id):
        protocolo_server(protocolo_server),
        was_closed(was_closed),
        gameloop_monitor(gameloop_monitor),
        gameloop_id(gameloop_id),
        cliente_id(cliente_id),
        client_commands(gameloop_monitor.obtener_queue_de_client_commands(gameloop_id)) {}

void ServerReceiver::run() {
    while (!was_closed) {
        try {
            auto comando = protocolo_server.recibir_acciones(was_closed, cliente_id);
            client_commands.push(std::shared_ptr<Comando>(
                    std::move(comando)));  // Como use unique_ptr por la herencia, tengo q
                                           // convertirlo a shared_ptr
            if (!this->is_alive()) {
                break;
            }
        } catch (const LibError& err) {
            break;
        }
    }
    std::cout << "El cliente " << cliente_id << " se ha desconectado" << std::endl;
    gameloop_monitor.borrar_cliente_de_gameloop(gameloop_id, cliente_id);
}

ServerReceiver::~ServerReceiver() {}
