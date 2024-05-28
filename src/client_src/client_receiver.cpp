#include "../client_src/client_receiver.h"

#include <memory>  // shared_ptr()
#include <string>
#include <utility>  // move()
#include <vector>

#include "../client_src/client_game_respuesta.h"
#include "../client_src/client_protocol.h"
#include "../common_src/common_liberror.h"

ClientReceiver::ClientReceiver(ProtocolClient& protocolo_cliente,
                               Queue<std::shared_ptr<ClientGameRespuesta>>& server_msg):
        protocolo_cliente(protocolo_cliente), server_msg(server_msg) {}

void ClientReceiver::run() {
    while (!protocolo_cliente.obtener_estado_de_la_conexion()) {
        try {
            auto msg = std::make_shared<ClientGameRespuesta>();
            protocolo_cliente.recibir_respuesta(*msg);
            server_msg.push(msg);
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
