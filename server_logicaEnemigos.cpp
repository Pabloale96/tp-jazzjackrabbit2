
#include "server_logicaEnemigos.h"
    
logicaEnemigos::logicaEnemigos(){
    
    Enemigo aliveEnemy(true);
    Enemigo deadEnemy(false);
    std::vector<Enemigo> vivosAux(STARTED_ENEMY);
    std::vector<Enemigo> muertosAux(STARTED_ENEMY_DIED);

    for (int i = 0; i < STARTED_ENEMY; i++)
    {
        vivosAux[i]=aliveEnemy;
    }
    for (int i = 0; i < STARTED_ENEMY_DIED; i++)
    {
        muertosAux[i]=deadEnemy;
    }
    
    vivos = vivosAux;
    muertos = muertosAux;
}

void logicaEnemigos::changedOneEnemytoDied(VectorProtected<Queue<msg_client_t> *> * client_queue){
    msg_client_t msg_client={0x00,0x0000,0x0000,0x00};
    if (vivos.size()!=0) {

        vivos.back().changedAlive();
        muertos.push_back(vivos.back());
        vivos.pop_back();
        std::cout << "Un enemigo ha muerto. "<< vivos.size() 
            <<" vivo(s) y "<< muertos.size()<< " muerto(s)." << std::endl;
        msg_client.header = 0x06;
        msg_client.method = 0x04;
        msg_client.size_alived = htons(vivos.size());
        msg_client.size_dead = htons(muertos.size());
        for (size_t i = 0; i < client_queue->size(); i++)
        {
            if ((*client_queue)[i]!=nullptr) {
                (*client_queue)[i]->try_push(msg_client);
            }
        }
    }
}
void logicaEnemigos::changedEnemisToAlive(VectorProtected<Queue<msg_client_t> *> * client_queue){
    msg_client_t msg_client={0x00,0x0000,0x0000,0x00};
    for (size_t i = 0; i < muertos.size(); i++)
    {
        muertos[i].sumTime();
        if (muertos[i].checkTime()){
            muertos[i].changedAlive();
            vivos.push_back(muertos[i]);
            muertos.erase(muertos.begin()+i);
            std::cout << "Un enemigo ha revivido. "<< vivos.size() 
                <<" vivo(s) y "<< muertos.size()<< " muerto(s)." << std::endl;
            msg_client.header = 0x06;
            msg_client.method = 0x05;
            msg_client.size_alived = htons(vivos.size());
            msg_client.size_dead = htons(muertos.size());
            for (size_t j = 0; j < client_queue->size(); j++)
            {
                if ((*client_queue)[j]!=nullptr) {
                    (*client_queue)[j]->try_push(msg_client);
                }
            }
        }
    }
}
