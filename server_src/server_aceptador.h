#ifndef _SERVER_ACEPTADOR_H_
#define _SERVER_ACEPTADOR_H_

#include <list>
#include <string>

#include "../common_src/common_sockets.h"
#include "../common_src/common_thread.h"
#include "../server_src/gameloop_class.h"
#include "../server_src/gameloop_monitor.h"
#include "../server_src/server_cliente_aceptado.h"

class Aceptador: public Thread {
private:
    Socket socket_server;
    std::atomic<bool> was_closed_aceptador;
    GameloopMonitor monitor_diccionario_de_gameloops;

public:
    // Constructor
    // Recibe el nombre del servidor y una referencia al juego
    // Crea el socket del servidor y pone was_closed_aceptador en false
    explicit Aceptador(const std::string& servname);

    // Crea una lista de clientes aceptados y acepta clientes hasta que se cierre
    // el aceptador
    void run() override;

    // Limpia los clientes que terminaron de la lista de clientes
    void limpiar_clientes_que_terminaron(std::list<ClienteAceptado>& lista_clientes);

    // Cierra todos los clientes de la lista de clientes
    void limpiar_lista(std::list<ClienteAceptado>& lista_clientes);

    // Cierra el socket del servidor y pone was_closed_aceptador en true
    void stop() override;

    // Destructor
    ~Aceptador();
};

#endif
