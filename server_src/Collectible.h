#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include <iostream>
#include <vector>

class Collectible {

private:
    float punto;

public:
    Collectible();
};

class Gema: public Collectible {

public:
    Gema();
};

class Moneda: public Collectible {

public:
    Moneda();
};

#endif
