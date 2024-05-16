#ifndef _SERVER_JUEGO_H_
#define _SERVER_JUEGO_H_

#include <cstdint>
#include <string>
#include <vector>

#include "../common_src/common_queue.h"
#include "../common_src/common_thread.h"
#include "../server_src/server_enemigo.h"
#include "../server_src/server_monitor.h"

class Juego: public Thread {
private:
    Queue<std::string>* client_commands;
    std::vector<Enemigo> enemigos;
    ServerMonitor monitor_lista_de_queues_server_msg;

public:
    // Constructor
    // Crea una cola de comandos de clientes y un vector de 5 enemigos
    Juego();

    // Agrega una cola de mensajes del servidor de un cliente aceptado al vector
    // de colas
    void agregar_queue_server_msg_de_cliente_aceptado(Queue<ServerJuegoMensaje>* nueva_queue);

    // Popea un comando de la cola de comandos de clientes y lo procesa
    void run() override;

    // Disminuye en 1 la cant de enemigos vivos y aumenta en 1 la cant de enemigos
    // matados
    void atacar();

    // Mata un enemigo si hay alguno vivo y devuelve true, sino devuelve false
    bool matar_enemigo();

    // Aumenta las iteraciones de los enemigos y devuelve true si se revivio
    // alguno
    bool aumentar_iteraciones();

    // Devuelve la cantidad de enemigos vivos
    uint16_t obtener_cant_vivos();

    // Devuelve la cantidad de enemigos muertos
    uint16_t obtener_cant_muertos();

    // Broadcastea un mensaje a todos los clientes
    void broadcastear(uint8_t accion);

    // Duerme el hilo por 200 segundos
    void dormir();

    void borrar_queue_server_msg_de_cliente_aceptado(Queue<ServerJuegoMensaje>* queue);

    // Cierra la cola de comandos de clientes
    // Cierra las colas de mensajes de los clientes
    void stop() override;

    // Destructor
    ~Juego();
};

#endif
