#ifndef _GAME_COLLECTIBLE_H_
#define _GAME_COLLECTIBLE_H_

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
