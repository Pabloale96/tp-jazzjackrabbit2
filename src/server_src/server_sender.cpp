#include "../server_src/server_sender.h"

#include "../common_src/common_liberror.h"
#include "../server_src/server_protocol.h"

#define MATAR 0x04
#define REVIVIR 0x05

ServerSender::ServerSender(ProtocolServer& protocolo_server, bool& was_closed,
                           Queue<std::shared_ptr<GameState>>& server_msg):
        protocolo_server(protocolo_server), was_closed(was_closed), server_msg(server_msg) {}

void ServerSender::run() {
    while (!was_closed) {
        try {
            std::shared_ptr<GameState> msg = server_msg.pop();
            protocolo_server.enviar_respuesta(*msg, was_closed);
        } catch (const ClosedQueue&) {
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
