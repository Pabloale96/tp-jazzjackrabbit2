#ifndef _SERVER_ACEPTADOR_H_
#define _SERVER_ACEPTADOR_H_

#include <list>
#include <string>

#include "cliente_aceptado.h"
#include "gameloop_class.h"
#include "gameloop_monitor.h"
#include "sockets.h"
#include "thread.h"

class Aceptador: public Thread {
private:
    Socket socket_server;
    std::atomic<bool> was_closed_aceptador;
    GameloopMonitor monitor_de_partidas;

public:
    // Constructor
    // Recibe el nombre del servidor y una referencia al juego
    // Crea el socket del servidor y pone was_closed_aceptador en false
    explicit Aceptador(const std::string& servname);

    // Crea una lista de clientes aceptados y acepta clientes hasta que se cierre
    // el aceptador
    void run() override;

    // Limpia los clientes que terminaron de la lista de clientes
    void limpiar_clientes_que_terminaron(std::list<ClienteAceptado*>& lista_clientes);

    // Cierra todos los clientes de la lista de clientes
    void limpiar_lista(std::list<ClienteAceptado*>& lista_clientes);

    // Cierra el socket del servidor y pone was_closed_aceptador en true
    void stop() override;

    // Destructor
    ~Aceptador();
};

#endif
