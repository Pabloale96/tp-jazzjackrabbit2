#include "../client_src/client_sender.h"

#include "../client_src/client_protocol.h"
#include "../common_src/common_liberror.h"

ClientSender::ClientSender(ProtocolClient& protocolo_cliente, Queue<TipoAccion>& client_commands):
        protocolo_cliente(protocolo_cliente), client_commands(client_commands) {}

void ClientSender::run() {
    while (!protocolo_cliente.obtener_estado_de_la_conexion()) {
        try {
            TipoAccion comando = client_commands.pop();
            protocolo_cliente.enviar_accion(comando);
            if (!this->is_alive()) {
                break;
            }
        } catch (const LibError& err) {
            std::cerr << "Fallo el send en ClientReceiver->run: " << err.what() << "\n";
        }
    }
}
