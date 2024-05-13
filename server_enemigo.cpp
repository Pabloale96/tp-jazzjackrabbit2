#include "server_enemigo.h"

Enemigo::Enemigo(){
    isAlive = true;
    time = 0;
}
Enemigo::Enemigo(bool alive){
    isAlive = alive;
    time = 0;
}
Enemigo::~Enemigo(){}

void Enemigo::sumTime(){
    time+=1;
}
int Enemigo::getTime(){
    return time;
}
bool Enemigo::checkTime(){
    return time==15;
}
void Enemigo::changedAlive(){
    time=0;
    isAlive=!isAlive;
}
