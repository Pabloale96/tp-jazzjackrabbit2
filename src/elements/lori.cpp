#include <iostream>
#include <exception>

#include <SDL2pp/SDL2pp.hh>
#include "../../include/personaje.h"

Lori::Lori(Renderer & renderer):Personaje(renderer)
{
    sprites.SetBlendMode(SDL_BLENDMODE_BLEND);

    this->setFramesWalk();
    this->setFramesStand();
    this->setFramesJump();
    this->setFramesRunning();
    this->setFramesJumpAndMove();
    this->setFramesIntoxicated();
    this->setFramesHurt();
    this->setFramesShoot();
    this->setFramesStopShoot();
    this->setFramesShootUp();
    this->setFramesShootAndMove();
    this->setFramesStopShootAndMove();
    this->setFramesShootAndFalling();
    this->setFramesStopShootAndFalling();
    this->setFramesDash();
    this->setFramesSpecial();
}
Lori::~Lori(){}

void Lori::show(int animacion){
    switch (animacion)
    {
        case 0:
            aniStand.setFlip(false);
            aniStand.run(renderer.GetOutputWidth()/2-21, renderer.GetOutputHeight()/2-23);
            break;
        case 1:
            //animaciones = new AnimacionDerecha(renderer,sprites);
            aniWalk.setFlip(false);
            aniWalk.run(renderer.GetOutputWidth()/2-21, renderer.GetOutputHeight()/2-23);
            break;
        case 2:
            aniWalk.setFlip(true);
            aniWalk.run(renderer.GetOutputWidth()/2-21, renderer.GetOutputHeight()/2-23);
            break;
        case 3:
            aniJump.setFlip(true);
            aniJump.run(renderer.GetOutputWidth()/2-21, renderer.GetOutputHeight()/2-23);
            break;

        default:
            break;
    }
}


void Lori::setFramesStand(){

    int x_frames[] = {5,48,93,138,182,227,269,313,357,403,447,493};
    int y_frames[] = {14,12,11,13,14,14,12,13,13,12,12,12};
    int w_frames[] = {51,53,54,52,51,51,53,52,52,53,53,53};
    int h_frames[] = {36,37,38,36,36,35,36,33,36,37,37,37};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_stand.emplace_back(frame);
    }
}

void Lori::setFramesWalk(){

    int x_frames[] = {4,53,106,155,207,257,310,360};
    int y_frames[] = {559,559,561,562,561,560,561,562};
    int w_frames[] = {47,38,44,43,45,37,43,44};
    int h_frames[] = {46,47,44,46,45,47,44,45};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_walk.emplace_back(frame);
    }
}

void Lori::setFramesJump(){

    int x_frames[] = {5,39,80,122,163,206,253,298,343,385,421,458};
    int y_frames[] = {889,896,897,897,898,898,898,894,891,891,890,890};
    int w_frames[] = {55,48,48,49,47,47,47,49,51,51,51,52};
    int h_frames[] = {31,36,34,36,41,41,40,39,35,30,30,30};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_jump.emplace_back(frame);
    }
}

void Lori::setFramesRunning(){

    int x_frames[] = {5,46,115,168,223,274,333,388};
    int y_frames[] = {629,630,631,630,630,630,630,630};
    int w_frames[] = {38,27,36,37,37,27,37,37};
    int h_frames[] = {45,50,45,45,45,50,45,45};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_running.emplace_back(frame);
    }
}

void Lori::setFramesJumpAndMove(){

    int x_frames[] = {9,57,102,147,193,240,289,342,394,447,487,528,567};
    int y_frames[] = {980,980,979,979,979,979,979,979,979,966,966,966,966};
    int w_frames[] = {49,51,52,52,52,50,45,42,42,51,51,51,51};
    int h_frames[] = {37,36,38,40,43,43,48,49,49,34,35,34,35};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_jump_and_move.emplace_back(frame);
    }
}

void Lori::setFramesIntoxicated(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_intoxicated.emplace_back(frame);
    }
}

void Lori::setFramesHurt(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_hurt.emplace_back(frame);
    }
}

void Lori::setFramesShoot(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_shoot.emplace_back(frame);
    }
}

void Lori::setFramesStopShoot(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_stop_shoot.emplace_back(frame);
    }
}

void Lori::setFramesShootUp(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_shoot_up.emplace_back(frame);
    }
}

void Lori::setFramesShootAndMove(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_shoot_and_move.emplace_back(frame);
    }
}

void Lori::setFramesStopShootAndMove(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_stop_shoot_up_move.emplace_back(frame);
    }
}

void Lori::setFramesShootAndFalling(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_shoot_and_falling.emplace_back(frame);
    }
}

void Lori::setFramesStopShootAndFalling(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_stop_shoot_and_falling.emplace_back(frame);
    }
}

void Lori::setFramesDash(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_dash.emplace_back(frame);
    }
}

void Lori::setFramesSpecial(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_special.emplace_back(frame);
    }
}

