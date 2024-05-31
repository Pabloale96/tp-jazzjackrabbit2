#include "../../include/animaciones.h"


Animacion::~Animacion() {}

Animacion::Animacion(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        render(render), sprites(sprites), frames(vect) {}

void Animacion::setFlip(bool flip) { this->flip = flip; }

void Animacion::run(int pos_x, int pos_y) {
    frames[scr_x].copy(flip, pos_x, pos_y);
    scr_x++;
    if (scr_x == frames.size())
        scr_x = 0;
}

AnimacionWalk::AnimacionWalk(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}

AnimacionWalk::~AnimacionWalk() {}

AnimacionStand::AnimacionStand(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionStand::~AnimacionStand() {}

AnimacionJump::AnimacionJump(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionJump::~AnimacionJump() {}

AnimacionRunning::AnimacionRunning(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionRunning::~AnimacionRunning() {}

AnimacionJumpAndMove::AnimacionJumpAndMove(Renderer& render, Texture& sprites,
                                           std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionJumpAndMove::~AnimacionJumpAndMove() {}

AnimacionIntoxicated::AnimacionIntoxicated(Renderer& render, Texture& sprites,
                                           std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionIntoxicated::~AnimacionIntoxicated() {}

AnimacionHurt::AnimacionHurt(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionHurt::~AnimacionHurt() {}

AnimacionShoot::AnimacionShoot(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionShoot::~AnimacionShoot() {}

AnimacionStopShoot::AnimacionStopShoot(Renderer& render, Texture& sprites,
                                       std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionStopShoot::~AnimacionStopShoot() {}

AnimacionShootUp::AnimacionShootUp(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionShootUp::~AnimacionShootUp() {}

AnimacionShootAndMove::AnimacionShootAndMove(Renderer& render, Texture& sprites,
                                             std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionShootAndMove::~AnimacionShootAndMove() {}

AnimacionStopShootAndMove::AnimacionStopShootAndMove(Renderer& render, Texture& sprites,
                                                     std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionStopShootAndMove::~AnimacionStopShootAndMove() {}

AnimacionShootAndFalling::AnimacionShootAndFalling(Renderer& render, Texture& sprites,
                                                   std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionShootAndFalling::~AnimacionShootAndFalling() {}

AnimacionStopShootAndFalling::AnimacionStopShootAndFalling(Renderer& render, Texture& sprites,
                                                           std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionStopShootAndFalling::~AnimacionStopShootAndFalling() {}

AnimacionDash::AnimacionDash(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionDash::~AnimacionDash() {}


AnimacionSpecial::AnimacionSpecial(Renderer& render, Texture& sprites, std::vector<Frame>& vect):
        Animacion(render, sprites, vect) {}
AnimacionSpecial::~AnimacionSpecial() {}
