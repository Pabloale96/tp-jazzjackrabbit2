#include "server_aceptador.h"

#include <list>
#include <utility>  // move()

#include <sys/socket.h>  // para usar el flag para hacer shutdown del socket

#include "common_liberror.h"
#include "server_cliente_aceptado.h"
#include "server_juego.h"
#include "server_protocol.h"

Aceptador::Aceptador(const std::string& servname, Juego& juego):
        socket_server(servname.c_str()), was_closed_aceptador(false), juego(juego) {}

void Aceptador::run() {
    std::list<ClienteAceptado> lista_clientes;
    while (!was_closed_aceptador) {
        try {
            Socket socket_cliente = socket_server.accept();
            lista_clientes.emplace_back(std::move(socket_cliente), juego);
            lista_clientes.back().start();
            limpiar_clientes_que_terminaron(lista_clientes);
        } catch (const std::exception& err) {
            if (!is_alive() or was_closed_aceptador) {
                limpiar_lista(lista_clientes);
                return;
            }
        }
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

void Aceptador::limpiar_lista(std::list<ClienteAceptado>& lista_clientes) {
    lista_clientes.clear();
}

void Aceptador::stop() {
    was_closed_aceptador = true;
    socket_server.shutdown(SHUT_RDWR);
    socket_server.close();
}


Aceptador::~Aceptador() {
    // socket_server.shutdown(SHUT_RDWR);
    // socket_server.close();
}
