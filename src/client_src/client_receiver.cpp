#include "../../include/client_src/client_receiver.h"

#include <memory>  // shared_ptr()
#include <string>
#include <utility>  // move()
#include <vector>

#include "../../include/client_src/client_protocol.h"
#include "../../include/common_src/catedra/liberror.h"

ClientReceiver::ClientReceiver(ProtocolClient& protocolo_cliente, uint16_t& client_id,
                               Queue<std::shared_ptr<GameState>>& server_msg):
        protocolo_cliente(protocolo_cliente), client_id(client_id), server_msg(server_msg) {}

void ClientReceiver::run() {
    while (!protocolo_cliente.obtener_estado_de_la_conexion()) {
        try {
            auto gameState = std::make_shared<GameState>(0, true);
            protocolo_cliente.recibir_respuesta(*gameState, client_id);
            server_msg.push(gameState);
        } catch (const ClosedQueue&) {
            return;
        } catch (const LibError& err) {
            std::cerr << "Fallo el receive en ClientSender->run: " << err.what() << "\n";
        } catch (const std::exception& err) {
            if (protocolo_cliente.obtener_estado_de_la_conexion()) {
                return;
            }
            if (!this->is_alive()) {
                return;
            }
        }
    }
}

ClientReceiver::~ClientReceiver() {}
