#ifndef COLLECTIBLE_H
#define PERSONAJE_H

#include<vector>
#include <iostream>
#include <netinet/in.h>

class Collectible {

    private:
    float punto;

    public:
    Personaje();
};

class Gema  : public Collectible {

    public:
    Gema();
};

class Moneda  : public Collectible {
    
    public:
    Moneda();
};

#endif
