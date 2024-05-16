#include "server_receiver.h"

#include <string>
#include <vector>

#include "../common_src/common_liberror.h"
#include "../server_src/server_juego.h"
#include "../server_src/server_protocol.h"

ServerReceiver::ServerReceiver(ProtocolServer& protocolo_server, bool& was_closed, Juego& juego):
        protocolo_server(protocolo_server), was_closed(was_closed), juego(juego) {}

void ServerReceiver::run() {
    while (!was_closed) {
        try {
            auto comando = protocolo_server.recibir_acciones(was_closed);
            if (comando) {
                comando->ejecutar(juego);
            }

            if (!this->is_alive()) {
                break;
            }
        } catch (const LibError& err) {
            std::cerr << "Fallo el receive en ServerReceiver->run: " << err.what() << "\n";
        }
    }
}

ServerReceiver::~ServerReceiver() {}
