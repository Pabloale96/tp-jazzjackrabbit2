#include "../../include/client_src/client_receiver.h"

#include <memory>  // shared_ptr()
#include <string>
#include <utility>  // move()
#include <vector>

#include "../../include/client_src/client_protocol.h"
#include "../../include/common_src/catedra/liberror.h"

ClientReceiver::ClientReceiver(ProtocolClient& protocolo_cliente, uint16_t& client_id,
                               Queue<std::shared_ptr<GameStateClient>>& server_msg,
                               ClaseTexturas& texturas):
        protocolo_cliente(protocolo_cliente),
        client_id(client_id),
        server_msg(server_msg),
        texturas(texturas) {}

void ClientReceiver::run() {
    while (!protocolo_cliente.obtener_estado_de_la_conexion()) {
        try {
            std::shared_ptr<GameStateClient> gameState = std::make_unique<GameStateClient>();
            protocolo_cliente.recibir_respuesta(texturas, gameState, client_id);
            server_msg.push(std::move(gameState));

        } catch (const ClosedQueue&) {
            return;
        } catch (const LibError& err) {
            if (protocolo_cliente.obtener_estado_de_la_conexion()) {
                return;
            }

            // Si el cliente cerro la conexión, no debería seguir intentando recibir
            if (this->is_alive()) {
                std::cout << "Te has desconectado del juego" << std::endl;
                // hay q avisarle al sender q cierre
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
