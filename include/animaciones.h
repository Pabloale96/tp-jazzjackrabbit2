#ifndef ANIMACIONES_H
#define ANIMACIONES_H

#include <exception>
#include <iostream>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "frame.h"

using SDL2pp::Renderer;
using SDL2pp::Texture;

class Animacion {
private:
    Renderer& render;
    Texture& sprites;
    std::vector<Frame>& frames;
    bool flip = false;
    int scr_x = 0;
    int scr_y = 0;

public:
    Animacion(Renderer&, Texture&, std::vector<Frame>&);
    ~Animacion();

    void run(int, int);
    void setFlip(bool);
};

class AnimacionWalk: public Animacion {
public:
    AnimacionWalk(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionWalk();
};

class AnimacionStand: public Animacion {
public:
    AnimacionStand(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionStand();
};

class AnimacionJump: public Animacion {
public:
    AnimacionJump(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionJump();
};

class AnimacionRunning: public Animacion {
public:
    AnimacionRunning(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionRunning();
};

class AnimacionJumpAndMove: public Animacion {
public:
    AnimacionJumpAndMove(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionJumpAndMove();
};

class AnimacionIntoxicated: public Animacion {
public:
    AnimacionIntoxicated(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionIntoxicated();
};

class AnimacionHurt: public Animacion {
public:
    AnimacionHurt(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionHurt();
};

class AnimacionShoot: public Animacion {
public:
    AnimacionShoot(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionShoot();
};

class AnimacionStopShoot: public Animacion {
public:
    AnimacionStopShoot(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionStopShoot();
};

class AnimacionShootUp: public Animacion {
public:
    AnimacionShootUp(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionShootUp();
};

class AnimacionShootAndMove: public Animacion {
public:
    AnimacionShootAndMove(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionShootAndMove();
};

class AnimacionStopShootAndMove: public Animacion {
public:
    AnimacionStopShootAndMove(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionStopShootAndMove();
};

class AnimacionShootAndFalling: public Animacion {
public:
    AnimacionShootAndFalling(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionShootAndFalling();
};

class AnimacionStopShootAndFalling: public Animacion {
public:
    AnimacionStopShootAndFalling(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionStopShootAndFalling();
};

class AnimacionDash: public Animacion {
public:
    AnimacionDash(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionDash();
};

class AnimacionSpecial: public Animacion {
public:
    AnimacionSpecial(Renderer&, Texture&, std::vector<Frame>&);
    ~AnimacionSpecial();
};


#endif
