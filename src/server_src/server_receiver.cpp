#include "../../include/server_src/server_receiver.h"

#include <memory>
#include <string>
#include <utility>  // move()
#include <vector>

#include "../../include/common_src/liberror.h"
#include "../../include/server_src/game/gameloop_class.h"
#include "../../include/server_src/server_protocol.h"

ServerReceiver::ServerReceiver(ProtocolServer& protocolo_server, bool& was_closed,
                               GameloopMonitor& gameloop_monitor, uint16_t gameloop_id,
                               uint16_t cliente_id):
        protocolo_server(protocolo_server),
        was_closed(was_closed),
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
            // Si falla el receive, es porque el cliente cerró la conexion (o falló)
            std::cout << "Cliente " << cliente_id << "se ha desconectado\n";
            // TODO: gamelop, cerra este cliente/personaje
            protocolo_server.cerrar_socket_cliente();
            return;
        }
    }
}

ServerReceiver::~ServerReceiver() {}
