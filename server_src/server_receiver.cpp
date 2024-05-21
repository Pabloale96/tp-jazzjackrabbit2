#include "server_receiver.h"

#include <memory>
#include <string>
#include <utility>  // move()
#include <vector>

#include "../common_src/common_liberror.h"
#include "../server_src/gameloop_class.h"
#include "../server_src/server_protocol.h"

ServerReceiver::ServerReceiver(ProtocolServer& protocolo_server, bool& was_closed,
                               Queue<std::shared_ptr<Comando>>& client_commands):
        protocolo_server(protocolo_server),
        was_closed(was_closed),
        client_commands(client_commands) {}

void ServerReceiver::run() {
    while (!was_closed) {
        try {
            auto comando = protocolo_server.recibir_acciones(was_closed);
            client_commands.push(std::shared_ptr<Comando>(
                    std::move(comando)));  // Como use unique_ptr por la herencia, tengo q
                                           // convertirlo a shared_ptr
            if (!this->is_alive()) {
                break;
            }
        } catch (const LibError& err) {
            std::cerr << "Fallo el receive en ServerReceiver->run: " << err.what() << "\n";
        }
    }
}

ServerReceiver::~ServerReceiver() {}
