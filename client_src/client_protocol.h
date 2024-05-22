#ifndef __PROTOCOL_CLIENT_H__
#define __PROTOCOL_CLIENT_H__

#include <string>
#include <unordered_map>
#include <vector>

#include "../common_src/common_sockets.h"

enum class TipoAccion : char {
    Disparar,
    MoverDerecha,
    MoverDerechaRapido,
    MoverIzquierda,
    MoverIzquierdaRapido,
    MoverArriba,
    MoverAbajo,
    Saltar
};

struct Respuesta {
    // cppcheck-suppress unusedStructMember
    uint16_t enemigos_vivos;
    // cppcheck-suppress unusedStructMember
    uint16_t enemigos_muertos;
    std::string tipo_evento;
};

class ProtocolClient {
private:
    Socket socket_cliente;
    bool was_closed;

public:
    // Constructor
    // Carga en el diccionario las acciones posibles y su valor asociado
    ProtocolClient(const std::string& hostname, const std::string& servicio);

    // Recibe del cliente la accion para serializar y enviar al server
    void enviar_accion(TipoAccion accion);

    // Envia las acciones ya con su valor asociado al server
    void enviar_accion_serializada(uint8_t accion_serializada, bool& was_closed);

    // Para poder recivir comandos
    bool recibir_respuesta(Respuesta& respuesta);

    // Destructor
    ~ProtocolClient();
};

#endif
