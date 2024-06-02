#ifndef TEXTURAS_H
#define TEXTURAS_H

#include <chrono>
#include <exception>
#include <iostream>
#include <map>
#include <string>

#include <SDL2pp/SDL2pp.hh>

#include "frame.h"

using namespace SDL2pp;
class ClaseTexturas {
    private:
        Renderer & renderer;
        Surface jazz{Surface(IMG_PATH "/jazz.png")};
        Surface spaz{Surface(IMG_PATH "/spaz.png")};
        Surface lori{Surface(IMG_PATH "/lori.png")};
        Texture jazz_tex{Texture(renderer, jazz.SetColorKey(true, SDL_MapRGB(jazz.Get()->format, 44, 102, 150)))};
        Texture spaz_tex{Texture(renderer, spaz.SetColorKey(true, SDL_MapRGB(spaz.Get()->format, 44, 102, 150)))};
        Texture lori_tex{Texture(renderer, lori.SetColorKey(true, SDL_MapRGB(lori.Get()->format, 44, 102, 150)))};

        std::map<std::string, std::vector<Frame>> frames;

    public:
        ClaseTexturas(Renderer & render):renderer(render){
                this->jazzWalk();
                this->jazzStand();
                this->jazzJump();
                this->jazzRunning();
                this->jazzJumpAndMove();
                this->jazzIntoxicated();
                this->jazzHurt();
                this->jazzShoot();
                this->jazzStopShoot();
                this->jazzShootUp();
                this->jazzShootAndMove();
                this->jazzStopShootAndMove();
                this->jazzShootAndFalling();
                this->jazzStopShootAndFalling();
                this->jazzDash();
                this->jazzSpecial();
                
                this->spazWalk();
                this->spazStand();
                this->spazJump();
                this->spazRunning();
                this->spazJumpAndMove();
                this->spazIntoxicated();
                this->spazHurt();
                this->spazShoot();
                this->spazStopShoot();
                this->spazShootUp();
                this->spazShootAndMove();
                this->spazStopShootAndMove();
                this->spazShootAndFalling();
                this->spazStopShootAndFalling();
                this->spazDash();
                this->spazSpecial();

                this->loriWalk();
                this->loriStand();
                this->loriJump();
                this->loriRunning();
                this->loriJumpAndMove();
                this->loriIntoxicated();
                this->loriHurt();
                this->loriShoot();
                this->loriStopShoot();
                this->loriShootUp();
                this->loriShootAndMove();
                this->loriStopShootAndMove();
                this->loriShootAndFalling();
                this->loriStopShootAndFalling();
                this->loriDash();
                this->loriSpecial();

        }
        ~ClaseTexturas();


        void loriStand();
        void loriWalk();
        void loriJump();
        void loriRunning();
        void loriJumpAndMove();
        void loriIntoxicated();
        void loriHurt();
        void loriShoot();
        void loriStopShoot();
        void loriShootUp();
        void loriShootAndMove();
        void loriStopShootAndMove();
        void loriShootAndFalling();
        void loriStopShootAndFalling();
        void loriDash();
        void loriSpecial();

        void jazzStand();
        void jazzWalk();
        void jazzJump();
        void jazzRunning();
        void jazzJumpAndMove();
        void jazzIntoxicated();
        void jazzHurt();
        void jazzShoot();
        void jazzStopShoot();
        void jazzShootUp();
        void jazzShootAndMove();
        void jazzStopShootAndMove();
        void jazzShootAndFalling();
        void jazzStopShootAndFalling();
        void jazzDash();
        void jazzSpecial();

        void spazStand();
        void spazWalk();
        void spazJump();
        void spazRunning();
        void spazJumpAndMove();
        void spazIntoxicated();
        void spazHurt();
        void spazShoot();
        void spazStopShoot();
        void spazShootUp();
        void spazShootAndMove();
        void spazStopShootAndMove();
        void spazShootAndFalling();
        void spazStopShootAndFalling();
        void spazDash();
        void spazSpecial();

        void addFrames(std::string, std::vector<Frame>);

};

#endif
