#include <iostream>
#include <exception>

#include <SDL2pp/SDL2pp.hh>
#include "../../include/personaje.h"

Spaz::Spaz(Renderer & renderer):Personaje(renderer)
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
Spaz::~Spaz(){}

void Spaz::show(int animacion){
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


void Spaz::setFramesStand(){

    int x_frames[6] = {6,43,79,116,155,205};
    int y_frames[6] = {817,817,813,813,813,817};
    int w_frames[6] = {42,42,46,46,46,42};
    int h_frames[6] = {30,27,29,29,29,33};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_stand.emplace_back(frame);
    }
}

void Spaz::setFramesWalk(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_walk.emplace_back(frame);
    }
}

void Spaz::setFramesJump(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_jump.emplace_back(frame);
    }
}

void Spaz::setFramesRunning(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_running.emplace_back(frame);
    }
}

void Spaz::setFramesJumpAndMove(){

    int x_frames[8] = {4,52,103,154,205,257,307,356};
    int y_frames[8] = {944,944,944,944,944,944,944,944};
    int w_frames[8] = {43,43,43,43,43,43,43,43};
    int h_frames[8] = {45,46,45,45,46,45,45,46};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_jump_and_move.emplace_back(frame);
    }
}

void Spaz::setFramesIntoxicated(){

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

void Spaz::setFramesHurt(){

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

void Spaz::setFramesShoot(){

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

void Spaz::setFramesStopShoot(){

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

void Spaz::setFramesShootUp(){

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

void Spaz::setFramesShootAndMove(){

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

void Spaz::setFramesStopShootAndMove(){

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

void Spaz::setFramesShootAndFalling(){

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

void Spaz::setFramesStopShootAndFalling(){

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

void Spaz::setFramesDash(){

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

void Spaz::setFramesSpecial(){

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

