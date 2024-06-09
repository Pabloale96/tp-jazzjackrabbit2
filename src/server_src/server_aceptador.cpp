#include "../../include/server_src/server_aceptador.h"

#include <list>
#include <utility>  // move()

#include <sys/socket.h>  // para usar el flag para hacer shutdown del socket

#include "../../include/common_src/catedra/liberror.h"
#include "../../include/server_src/cliente_aceptado.h"
#include "../../include/server_src/game/gameloop_class.h"
#include "../../include/server_src/server_protocol.h"

Aceptador::Aceptador(const std::string& servname):
        socket_server(servname.c_str()), was_closed_aceptador(false), monitor_de_partidas() {}

void Aceptador::run() {
    std::list<ClienteAceptado> lista_clientes;
    while (!was_closed_aceptador) {
        try {
            Socket socket_cliente = socket_server.accept();
            lista_clientes.emplace_back(std::move(socket_cliente), monitor_de_partidas);
            lista_clientes.back().start(monitor_de_partidas);
        } catch (const std::exception& err) {
            if (!is_alive() or was_closed_aceptador) {
                // TODO: ahora el monitor de gameloops tiene que cerrar los gameloops
                // game_loop.stop();
                // game_loop.join();
                // clean all
                return;
            }
        }
        // limpiar_clientes_que_terminaron(lista_clientes);
    }
}

void Aceptador::limpiar_clientes_que_terminaron(std::list<ClienteAceptado>& lista_clientes) {
    auto it = lista_clientes.begin();
    while (it != lista_clientes.end()) {
        if (it->is_dead()) {
            it = lista_clientes.erase(it);
        } else {
            ++it;
        }
    }
}

void Aceptador::stop() {
    was_closed_aceptador = true;
    socket_server.shutdown(SHUT_RDWR);
    socket_server.close();
}

Aceptador::~Aceptador() {}
