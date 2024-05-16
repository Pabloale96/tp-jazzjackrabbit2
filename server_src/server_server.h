#ifndef __SERVER_H__
#define __SERVER_H__

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../common_src/common_queue.h"
#include "../common_src/common_sockets.h"
#include "../common_src/common_thread.h"
#include "../server_src/server_aceptador.h"
#include "../server_src/server_juego.h"
#include "../server_src/server_protocol.h"

class Server {

private:
    Juego juego;
    Aceptador aceptador;

public:
    // Constructor
    // Crea el juego y el aceptador al cual le pasa el servname y el juego
    explicit Server(const std::string& servname);

    // Le da start al aceptador y espera a que el usuario aprete 'q' para terminar
    void jugar();

    // Destructor
    ~Server();

    // Constructor y asignacion por copia deshabilitados
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

    Server(Server&& other) = delete;
    Server& operator=(Server&& other) = delete;
};

#endif
