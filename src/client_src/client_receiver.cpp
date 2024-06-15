#include "../../include/client_src/client_receiver.h"

#include <memory>  // shared_ptr()
#include <string>
#include <utility>  // move()
#include <vector>

#include "../../include/client_src/client_protocol.h"
#include "../../include/common_src/catedra/liberror.h"

ClientReceiver::ClientReceiver(ProtocolClient& protocolo_cliente, uint16_t& client_id,
                               Queue<std::shared_ptr<GameStateMonitorClient>>& server_msg):
        protocolo_cliente(protocolo_cliente), client_id(client_id), server_msg(server_msg) {}

void ClientReceiver::run() {
    while (!protocolo_cliente.obtener_estado_de_la_conexion()) {
        try {
            std::shared_ptr<GameStateMonitorClient> gamestate;
            protocolo_cliente.recibir_respuesta(*gamestate, client_id);

            server_msg.push(std::move(gamestate));

        } catch (const ClosedQueue&) {
            return;
        } catch (const LibError& err) {
            if (protocolo_cliente.obtener_estado_de_la_conexion()) {
                return;
            }
            std::cerr << "Fallo el receive en ClientReceiver->run: " << err.what() << "\n";
            // TODO: Si el cliente cerro la conexión, no debería seguir intentando recibir
            return;
        } catch (const std::exception& err) {
            if (!this->is_alive()) {
                return;
            }
        }
    }
}

ClientReceiver::~ClientReceiver() {}
