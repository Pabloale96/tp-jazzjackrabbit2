#ifndef TEXTURAS_H
#define TEXTURAS_H

#include <chrono>
#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <mutex>

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
    Surface enemigos{Surface(IMG_PATH "/enemigos.png")};
    Surface items{Surface(IMG_PATH "/items.png")};

    Texture jazz_tex{Texture(renderer,
                             jazz.SetColorKey(true, SDL_MapRGB(jazz.Get()->format, 44, 102, 150)))};
    Texture spaz_tex{Texture(renderer,
                             spaz.SetColorKey(true, SDL_MapRGB(spaz.Get()->format, 44, 102, 150)))};
    Texture lori_tex{Texture(renderer,
                             lori.SetColorKey(true, SDL_MapRGB(lori.Get()->format, 44, 102, 150)))};
    Texture beach_tex{Texture(renderer,
                             beach.SetColorKey(true, SDL_MapRGB(beach.Get()->format, 87, 0, 203)))};

    Texture enemigos_tex{Texture(renderer,
                    enemigos.SetColorKey(true, SDL_MapRGB(enemigos.Get()->format, 0, 128, 255)))};

    Texture items_tex{Texture(
            renderer, items.SetColorKey(true, SDL_MapRGB(items.Get()->format, 44, 102, 150)))};

    std::map<std::string, std::shared_ptr<std::vector<Frame>>> frames_map;
    std::map<int, Frame> frame_number;

public:
    explicit ClaseTexturas(Renderer& render);
    ~ClaseTexturas();

    // Metodo de busqueda en el map:
    Texture& jazz_text();
    Texture& spaz_text();
    Texture& lori_text();
    Texture& beach_text();

    std::shared_ptr<std::vector<Frame>>& findFrame(std::string);

    void add_frames_to_map(int* x_frames, int* y_frames, int* w_frames, int* h_frames,
                           int frame_count, Texture& textura_del_personaje, const std::string& key);

    void addFrames(const std::string& key, std::shared_ptr<std::vector<Frame>>& frame);

    // Definiciones de frames:

    void enemigo1();
    void enemigo2();
    void enemigo3();

    void zanahoria();
    void municion();
    void moneda();
    void gema();
    void balas1();
    void balas2();


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
