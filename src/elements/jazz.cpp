#include <iostream>
#include <exception>

#include <SDL2pp/SDL2pp.hh>
#include "../../include/personaje.h"

Jazz::Jazz(Renderer & renderer):Personaje(renderer)
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
Jazz::~Jazz(){}

void Jazz::show(int animacion){
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


void Jazz::setFramesStand(){

    int x_frames[] = {2,42,81,123,163,206,252,303,353,403,448,492,553,580,625,670,2,50,100,150,194,233,275,313,354,394,434};
    int y_frames[] = {12,12,12,12,14,16,16,20,20,20,20,20,20,20,20,20,71,71,67,67,65,64,63,63,64,64,63};
    int w_frames[] = {49,49,49,49,47,45,45,41,41,41,41,41,41,41,41,41,41,41,45,45,47,48,49,49,48,48,49};
    int h_frames[] = {34,34,34,34,38,37,47,42,44,38,38,38,39,39,39,39,43,45,46,41,37,34,35,35,35,35,35};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_stand.emplace_back(frame);
    }
}

void Jazz::setFramesWalk(){

    int x_frames[] = {2,56,114,170,228,284,340,397};
    int y_frames[] = {795,792,792,796,794,792,792,796};
    int w_frames[] = {41,44,44,40,42,44,44,40};
    int h_frames[] = {52,45,54,55,54,55,56,56};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_walk.emplace_back(frame);
    }
}

void Jazz::setFramesJump(){

    int x_frames[] = {7,50,102,1131,1130,1131,1129,1132,1130,1124,1124,1123};
    int y_frames[] = {1123,1128,1130,154,200,241,283,333,338,445,502,563};
    int w_frames[] = {50,47,47,48,48,47,44,44,45,46,45};
    int h_frames[] = {38,46,47,40,38,45,51,54,54,57,56};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_jump.emplace_back(frame);
    }
}

void Jazz::setFramesRunning(){

    int x_frames[] = {3,67,139,205,272,337,409,472};
    int y_frames[] = {856,857,856,856,857,856,857,858};
    int w_frames[] = {35,34,35,35,34,34,33};
    int h_frames[] = {61,67,62,63,62,58,61};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_running.emplace_back(frame);
    }
}

void Jazz::setFramesJumpAndMove(){

    int x_frames[] = {4,54,92,134,183,230,282,332,384,430,466,502};
    int y_frames[] = {1210,1208,1210,1210,1209,1209,1208,1208,1203,1199,1199,1200};
    int w_frames[] = {44,47,44,45,48,47,45,38,43,47,47,46};
    int h_frames[] = {47,34,40,45,44,47,47,48,41,34,33,33};

    for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
    {
      Frame frame(renderer,sprites);
      frame.setFrame(x_frames[i],y_frames[i],h_frames[i],w_frames[i]);
      frames_jump_and_move.emplace_back(frame);
    }
}

void Jazz::setFramesIntoxicated(){

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

void Jazz::setFramesHurt(){

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

void Jazz::setFramesShoot(){

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

void Jazz::setFramesStopShoot(){

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

void Jazz::setFramesShootUp(){

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

void Jazz::setFramesShootAndMove(){

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

void Jazz::setFramesStopShootAndMove(){

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

void Jazz::setFramesShootAndFalling(){

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

void Jazz::setFramesStopShootAndFalling(){

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

void Jazz::setFramesDash(){

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

void Jazz::setFramesSpecial(){

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

