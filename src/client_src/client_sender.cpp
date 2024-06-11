#include "../../include/client_src/client_sender.h"

#include "../../include/client_src/client_protocol.h"
#include "../../include/common_src/catedra/liberror.h"

ClientSender::ClientSender(ProtocolClient& protocolo_cliente, Queue<msgAccion>& client_commands):
        protocolo_cliente(protocolo_cliente), client_commands(client_commands) {}

void ClientSender::run() {
    while (!protocolo_cliente.obtener_estado_de_la_conexion()) {
        try {
            msgAccion comando = client_commands.pop();
            protocolo_cliente.enviar_accion(comando);
            if (!this->is_alive()) {
                break;
            }
        } catch (const ClosedQueue&) {
            return;
        } catch (const LibError& err) {
            std::cerr << "Fallo el send en ClientSender->run: " << err.what() << "\n";
            return;
        }
    }
}
