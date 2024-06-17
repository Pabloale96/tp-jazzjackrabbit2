#include "../../include/server_src/server_sender.h"

#include "../../include/common_src/catedra/liberror.h"
#include "../../include/server_src/server_protocol.h"

#define MATAR 0x04
#define REVIVIR 0x05

ServerSender::ServerSender(ProtocolServer& protocolo_server, uint16_t cliente_id, bool& was_closed,
                           Queue<std::shared_ptr<GameState>>& server_msg,
                           std::atomic<bool>& lobby_off):
        protocolo_server(protocolo_server),
        was_closed(was_closed),
        cliente_id(cliente_id),
        server_msg(server_msg),
        lobby_off(lobby_off) {}

void ServerSender::run() {
    while (!was_closed) {
        while (lobby_off) {
            try {
                std::shared_ptr<GameState> gameState = server_msg.pop();
                protocolo_server.enviar_respuesta(*gameState, cliente_id, was_closed);
            } catch (const ClosedQueue&) {
                std::cout << "ServerSender cerrado\n";
                return;
            } catch (const LibError& err) {
                std::cerr << "Fallo el send en ServerSender->run: " << err.what() << "\n";
            } catch (const std::exception& err) {
                if (was_closed) {
                    return;
                }
                if (!this->is_alive()) {
                    return;
                }
            }
        }
    }
}
