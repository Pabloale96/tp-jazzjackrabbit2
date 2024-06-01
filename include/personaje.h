#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <exception>
#include <memory>

#include <SDL2pp/SDL2pp.hh>

#include "animaciones.h"

using namespace SDL2pp;
class Personaje {
    protected:
        Renderer & renderer;
        Surface spaz{Surface(IMG_PATH "/spaz.png")}; //inicializo cualquier cosa en total se pisa a crear un personaje
        Texture sprites{Texture(renderer, spaz.SetColorKey(true, SDL_MapRGB(spaz.Get()->format, 44, 102, 150)))};//inicializo cualquier cosa en total se pisa a crear un personaje
        //Animacion movimiento{Animacion(std::ref(renderer),std::ref(sprites))};//inicializo cualquier cosa en total se pisa a crear un personaje
    public:
        Personaje(Renderer & renderer):renderer(renderer){}
        ~Personaje(){}
        virtual void show(int){}
};

class Spaz : public Personaje {
    private:
        Surface spaz{Surface(IMG_PATH "/spaz.png")};
        Texture sprites{Texture(renderer, spaz.SetColorKey(true, SDL_MapRGB(spaz.Get()->format, 44, 102, 150)))};

        std::vector<Frame> frames_stand;
        std::vector<Frame> frames_walk;
        std::vector<Frame> frames_jump;
        std::vector<Frame> frames_running;
        std::vector<Frame> frames_jump_and_move;
        std::vector<Frame> frames_intoxicated;
        std::vector<Frame> frames_hurt;
        std::vector<Frame> frames_shoot;
        std::vector<Frame> frames_stop_shoot;
        std::vector<Frame> frames_shoot_up;
        std::vector<Frame> frames_shoot_and_move;
        std::vector<Frame> frames_stop_shoot_up_move;
        std::vector<Frame> frames_shoot_and_falling;
        std::vector<Frame> frames_stop_shoot_and_falling;
        std::vector<Frame> frames_dash;
        std::vector<Frame> frames_special;

        // Animaciones:

        Animacion animacion{frames};

        AnimacionWalk aniWalk{AnimacionWalk(renderer,sprites,frames_walk)};
        AnimacionStand aniStand{AnimacionStand(renderer,sprites,frames_stand)};
        AnimacionJump aniJump{AnimacionJump(renderer,sprites,frames_jump)};
        AnimacionRunning aniRun{AnimacionRunning(renderer,sprites,frames_running)};
        AnimacionJumpAndMove aniJumpAndMove{AnimacionJumpAndMove(renderer,sprites,frames_jump_and_move)};
        AnimacionIntoxicated aniIntoxicated{AnimacionIntoxicated(renderer,sprites,frames_intoxicated)};
        AnimacionHurt aniHurt{AnimacionHurt(renderer,sprites,frames_hurt)};
        AnimacionShoot aniShoot{AnimacionShoot(renderer,sprites,frames_shoot)};
        AnimacionStopShoot aniStopShoot{AnimacionStopShoot(renderer,sprites,frames_stop_shoot)};
        AnimacionShootUp aniShootUp{AnimacionShootUp(renderer,sprites,frames_shoot_up)};
        AnimacionShootAndMove aniShootAndMove{AnimacionShootAndMove(renderer,sprites,frames_shoot_and_move)};
        AnimacionStopShootAndMove aniStopShootAndMove{AnimacionStopShootAndMove(renderer,sprites,frames_stop_shoot_up_move)};
        AnimacionShootAndFalling aniShootAndFalling{AnimacionShootAndFalling(renderer,sprites,frames_shoot_and_falling)};
        AnimacionStopShootAndFalling aniStopShootAndFalling{AnimacionStopShootAndFalling(renderer,sprites,frames_stop_shoot_and_falling)};
        AnimacionDash aniDash{AnimacionDash(renderer,sprites,frames_dash)};
        AnimacionSpecial aniSpecial{AnimacionSpecial(renderer,sprites,frames_special)};

        
        
    public:
        Spaz(Renderer &);
        ~Spaz();
        
        void show(int);

        void setFramesStand();
        void setFramesWalk();
        void setFramesJump();
        void setFramesRunning();
        void setFramesJumpAndMove();
        void setFramesIntoxicated();
        void setFramesHurt();
        void setFramesShoot();
        void setFramesStopShoot();
        void setFramesShootUp();
        void setFramesShootAndMove();
        void setFramesStopShootAndMove();
        void setFramesShootAndFalling();
        void setFramesStopShootAndFalling();
        void setFramesDash();
        void setFramesSpecial();
};


class Jazz : public Personaje {
    private:
        Surface jazz{Surface(IMG_PATH "/jazz.png")};
        Texture sprites{Texture(renderer, jazz.SetColorKey(true, SDL_MapRGB(jazz.Get()->format, 44, 102, 150)))};
        //State state; agregar el estado.
        // Clase nueva de mapa.

        std::vector<Frame> frames_stand;
        std::vector<Frame> frames_walk;
        std::vector<Frame> frames_jump;
        std::vector<Frame> frames_running;
        std::vector<Frame> frames_jump_and_move;
        std::vector<Frame> frames_intoxicated;
        std::vector<Frame> frames_hurt;
        std::vector<Frame> frames_shoot;
        std::vector<Frame> frames_stop_shoot;
        std::vector<Frame> frames_shoot_up;
        std::vector<Frame> frames_shoot_and_move;
        std::vector<Frame> frames_stop_shoot_up_move;
        std::vector<Frame> frames_shoot_and_falling;
        std::vector<Frame> frames_stop_shoot_and_falling;
        std::vector<Frame> frames_dash;
        std::vector<Frame> frames_special;

        // Animaciones:

        Animacion animacion;

        AnimacionWalk aniWalk{AnimacionWalk(renderer,sprites,frames_walk)};
        AnimacionStand aniStand{AnimacionStand(renderer,sprites,frames_stand)};
        AnimacionJump aniJump{AnimacionJump(renderer,sprites,frames_jump)};
        AnimacionRunning aniRun{AnimacionRunning(renderer,sprites,frames_running)};
        AnimacionJumpAndMove aniJumpAndMove{AnimacionJumpAndMove(renderer,sprites,frames_jump_and_move)};
        AnimacionIntoxicated aniIntoxicated{AnimacionIntoxicated(renderer,sprites,frames_intoxicated)};
        AnimacionHurt aniHurt{AnimacionHurt(renderer,sprites,frames_hurt)};
        AnimacionShoot aniShoot{AnimacionShoot(renderer,sprites,frames_shoot)};
        AnimacionStopShoot aniStopShoot{AnimacionStopShoot(renderer,sprites,frames_stop_shoot)};
        AnimacionShootUp aniShootUp{AnimacionShootUp(renderer,sprites,frames_shoot_up)};
        AnimacionShootAndMove aniShootAndMove{AnimacionShootAndMove(renderer,sprites,frames_shoot_and_move)};
        AnimacionStopShootAndMove aniStopShootAndMove{AnimacionStopShootAndMove(renderer,sprites,frames_stop_shoot_up_move)};
        AnimacionShootAndFalling aniShootAndFalling{AnimacionShootAndFalling(renderer,sprites,frames_shoot_and_falling)};
        AnimacionStopShootAndFalling aniStopShootAndFalling{AnimacionStopShootAndFalling(renderer,sprites,frames_stop_shoot_and_falling)};
        AnimacionDash aniDash{AnimacionDash(renderer,sprites,frames_dash)};
        AnimacionSpecial aniSpecial{AnimacionSpecial(renderer,sprites,frames_special)};

        
        
    public:
        Jazz(Renderer &);
        ~Jazz();
        
        void show(int);

        void setFramesStand();
        void setFramesWalk();
        void setFramesJump();
        void setFramesRunning();
        void setFramesJumpAndMove();
        void setFramesIntoxicated();
        void setFramesHurt();
        void setFramesShoot();
        void setFramesStopShoot();
        void setFramesShootUp();
        void setFramesShootAndMove();
        void setFramesStopShootAndMove();
        void setFramesShootAndFalling();
        void setFramesStopShootAndFalling();
        void setFramesDash();
        void setFramesSpecial();
};

class Lori : public Personaje {
    private:
        Surface lori{Surface(IMG_PATH "/lori.png")};
        Texture sprites{Texture(renderer, lori.SetColorKey(true, SDL_MapRGB(lori.Get()->format, 44, 102, 150)))};

        std::vector<Frame> frames_stand;
        std::vector<Frame> frames_walk;
        std::vector<Frame> frames_jump;
        std::vector<Frame> frames_running;
        std::vector<Frame> frames_jump_and_move;
        std::vector<Frame> frames_intoxicated;
        std::vector<Frame> frames_hurt;
        std::vector<Frame> frames_shoot;
        std::vector<Frame> frames_stop_shoot;
        std::vector<Frame> frames_shoot_up;
        std::vector<Frame> frames_shoot_and_move;
        std::vector<Frame> frames_stop_shoot_up_move;
        std::vector<Frame> frames_shoot_and_falling;
        std::vector<Frame> frames_stop_shoot_and_falling;
        std::vector<Frame> frames_dash;
        std::vector<Frame> frames_special;

        // Animaciones:
        AnimacionWalk aniWalk{AnimacionWalk(renderer,sprites,frames_walk)};
        AnimacionStand aniStand{AnimacionStand(renderer,sprites,frames_stand)};
        AnimacionJump aniJump{AnimacionJump(renderer,sprites,frames_jump)};
        AnimacionRunning aniRun{AnimacionRunning(renderer,sprites,frames_running)};
        AnimacionJumpAndMove aniJumpAndMove{AnimacionJumpAndMove(renderer,sprites,frames_jump_and_move)};
        AnimacionIntoxicated aniIntoxicated{AnimacionIntoxicated(renderer,sprites,frames_intoxicated)};
        AnimacionHurt aniHurt{AnimacionHurt(renderer,sprites,frames_hurt)};
        AnimacionShoot aniShoot{AnimacionShoot(renderer,sprites,frames_shoot)};
        AnimacionStopShoot aniStopShoot{AnimacionStopShoot(renderer,sprites,frames_stop_shoot)};
        AnimacionShootUp aniShootUp{AnimacionShootUp(renderer,sprites,frames_shoot_up)};
        AnimacionShootAndMove aniShootAndMove{AnimacionShootAndMove(renderer,sprites,frames_shoot_and_move)};
        AnimacionStopShootAndMove aniStopShootAndMove{AnimacionStopShootAndMove(renderer,sprites,frames_stop_shoot_up_move)};
        AnimacionShootAndFalling aniShootAndFalling{AnimacionShootAndFalling(renderer,sprites,frames_shoot_and_falling)};
        AnimacionStopShootAndFalling aniStopShootAndFalling{AnimacionStopShootAndFalling(renderer,sprites,frames_stop_shoot_and_falling)};
        AnimacionDash aniDash{AnimacionDash(renderer,sprites,frames_dash)};
        AnimacionSpecial aniSpecial{AnimacionSpecial(renderer,sprites,frames_special)};

        
        
    public:
        Lori(Renderer &);
        ~Lori();
        
        void show(int);

        void setFramesStand();
        void setFramesWalk();
        void setFramesJump();
        void setFramesRunning();
        void setFramesJumpAndMove();
        void setFramesIntoxicated();
        void setFramesHurt();
        void setFramesShoot();
        void setFramesStopShoot();
        void setFramesShootUp();
        void setFramesShootAndMove();
        void setFramesStopShootAndMove();
        void setFramesShootAndFalling();
        void setFramesStopShootAndFalling();
        void setFramesDash();
        void setFramesSpecial();
};
#endif
