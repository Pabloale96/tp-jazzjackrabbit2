#ifndef LENEMIGO_H
#define LENEMIGO_H

#include<vector>
#include <iostream>
#include <netinet/in.h>
#include "common_vectorProtected.h"

#include "server_enemigo.h"
#include "server_structMsg.h"

#define STARTED_ENEMY 5
#define STARTED_ENEMY_DIED 0

class logicaEnemigos {

    private:
    std::vector<Enemigo> vivos;
    std::vector<Enemigo> muertos;

    public:
    logicaEnemigos();

    void changedOneEnemytoDied(VectorProtected<Queue<msg_client_t> *> *);
    void changedEnemisToAlive(VectorProtected<Queue<msg_client_t> *> *);
};
#endif
