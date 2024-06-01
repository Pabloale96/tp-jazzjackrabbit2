#ifndef STRUCTMSG_H
#define STRUCTMSG_H

#include <cstdint>

struct msg_personaje_accion_client {
    uint8_t accion;
    uint16_t id;

    msg_personaje_accion_client& operator=(const msg_personaje_accion_client& other) {
        if (this != &other) { // Evita autoasignación
            accion = other.accion;
            id = other.id;
        }
        return *this;
    }
} __attribute__((packed));

#endif