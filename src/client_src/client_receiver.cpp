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
            if (false == protocolo_cliente.recibir_respuesta(*gameState, client_id))
            {
                std::cerr << "Ahh shit, Here we go again"<< "\n";
                return;
            }
            server_msg.push(gameState);
        } catch (const ClosedQueue&) {
            std::cerr << "Se cerro la queue de server_msg en el ClientReceiver"<< "\n";
            return;
        } catch (const LibError& err) {
            if (protocolo_cliente.obtener_estado_de_la_conexion()) {
                return;
            }
            std::cerr << "Fallo el receive en ClientReceiver->run: " << err.what() << "\n";
            return;
        } catch (const std::exception& err) {
            if (!this->is_alive()) {
                return;
            }
        }
    }
}

ClientReceiver::~ClientReceiver() {}
