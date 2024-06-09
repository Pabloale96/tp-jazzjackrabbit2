#ifndef TEXTURAS_H
#define TEXTURAS_H

#include <chrono>
#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "gui_defines_frames.h"
#include "gui_frame.h"

using SDL2pp::Renderer;
using SDL2pp::Surface;
using SDL2pp::Texture;


class ClaseTexturas {
private:
    Renderer& renderer;
    Surface jazz{Surface(IMG_PATH "/jazz.png")};
    Surface spaz{Surface(IMG_PATH "/spaz.png")};
    Surface lori{Surface(IMG_PATH "/lori.png")};
    Surface beach{Surface(IMG_PATH "/beach.png")};

    Texture jazz_tex{Texture(renderer,
                             jazz.SetColorKey(true, SDL_MapRGB(jazz.Get()->format, 44, 102, 150)))};
    Texture spaz_tex{Texture(renderer,
                             spaz.SetColorKey(true, SDL_MapRGB(spaz.Get()->format, 44, 102, 150)))};
    Texture lori_tex{Texture(renderer,
                             lori.SetColorKey(true, SDL_MapRGB(lori.Get()->format, 44, 102, 150)))};
    Texture beach_tex{Texture(
            renderer, beach.SetColorKey(true, SDL_MapRGB(beach.Get()->format, 87, 0, 203)))};

    std::map<std::string, std::vector<Frame>> frames_map;

public:
    explicit ClaseTexturas(Renderer& render);
    ~ClaseTexturas();

    // Metodo de busqueda en el map:
    Texture& jazz_text();
    Texture& spaz_text();
    Texture& lori_text();
    Texture& beach_text();

    std::vector<Frame>& findFrame(std::string);

    void addFrames(std::string, std::vector<Frame>);
    void addFrames(int, Frame);

    // Definiciones de frames:

    void plataformaTipo1();
    // void plataformaTipo2();
    // void plataformaTipo3();

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
};

#endif
