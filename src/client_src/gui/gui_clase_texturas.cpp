#include "../../include/client_src/gui/gui_clase_texturas.h"


Texture& ClaseTexturas::jazz_text() { return jazz_tex; }
Texture& ClaseTexturas::spaz_text() { return spaz_tex; }
Texture& ClaseTexturas::lori_text() { return lori_tex; }
Texture& ClaseTexturas::beach_text() { return beach_tex; }

std::vector<Frame>& ClaseTexturas::findFrame(std::string frame_string) {
    auto it = frames_map.find(frame_string);
    return it->second;
}

// Definiciones de la clase, de aca para abajo solo se toca
// si se cambio el sprite:

ClaseTexturas::ClaseTexturas(Renderer& render): renderer(render) {

    this->plataformaTipo1();

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


ClaseTexturas::~ClaseTexturas() {}

void ClaseTexturas::addFrames(std::string key, std::vector<Frame> value) {
    frames_map[key] = value;
}

void ClaseTexturas::plataformaTipo1() {

    int x_frame = 0;
    int y_frame = 2560;
    int w_frame = 29;
    int h_frame = 192;

    std::vector<Frame> frame_aux;
    Frame frame(renderer, beach_tex);
    frame.setFrame(x_frame, y_frame, h_frame, w_frame);
    frame_aux.emplace_back(frame);
    addFrames(PLATFORM_BEACH_TYPE_1, frame_aux);
}

void ClaseTexturas::jazzStand() {

    int x_frames[] = {2,   42,  81, 123, 163, 206, 252, 303, 353, 403, 448, 492, 553, 580,
                      625, 670, 2,  50,  100, 150, 194, 233, 275, 313, 354, 394, 434};
    int y_frames[] = {12, 12, 12, 12, 14, 16, 16, 20, 20, 20, 20, 20, 20, 20,
                      20, 20, 71, 71, 67, 67, 65, 64, 63, 63, 64, 64, 63};
    int w_frames[] = {49, 49, 49, 49, 47, 45, 45, 41, 41, 41, 41, 41, 41, 41,
                      41, 41, 41, 41, 45, 45, 47, 48, 49, 49, 48, 48, 49};
    int h_frames[] = {34, 34, 34, 34, 38, 37, 47, 42, 44, 38, 38, 38, 39, 39,
                      39, 39, 43, 45, 46, 41, 37, 34, 35, 35, 35, 35, 35};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_STAND, frame_aux);
}

void ClaseTexturas::jazzWalk() {

    int x_frames[] = {2, 56, 114, 170, 228, 284, 340, 397};
    int y_frames[] = {795, 792, 792, 796, 794, 792, 792, 796};
    int w_frames[] = {41, 44, 44, 40, 42, 44, 44, 40};
    int h_frames[] = {52, 45, 54, 55, 54, 55, 56, 56};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_WALK, frame_aux);
}

void ClaseTexturas::jazzJump() {

    int x_frames[] = {7, 50, 102, 1131, 1130, 1131, 1129, 1132, 1130, 1124, 1124, 1123};
    int y_frames[] = {1123, 1128, 1130, 154, 200, 241, 283, 333, 338, 445, 502, 563};
    int w_frames[] = {50, 47, 47, 48, 48, 47, 44, 44, 45, 46, 45};
    int h_frames[] = {38, 46, 47, 40, 38, 45, 51, 54, 54, 57, 56};


    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_JUMP, frame_aux);
}

void ClaseTexturas::jazzRunning() {

    int x_frames[] = {3, 67, 139, 205, 272, 337, 409, 472};
    int y_frames[] = {856, 857, 856, 856, 857, 856, 857, 858};
    int w_frames[] = {35, 34, 35, 35, 34, 34, 33};
    int h_frames[] = {61, 67, 62, 63, 62, 58, 61};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_RUN, frame_aux);
}

void ClaseTexturas::jazzJumpAndMove() {

    int x_frames[] = {4, 54, 92, 134, 183, 230, 282, 332, 384, 430, 466, 502};
    int y_frames[] = {1210, 1208, 1210, 1210, 1209, 1209, 1208, 1208, 1203, 1199, 1199, 1200};
    int w_frames[] = {44, 47, 44, 45, 48, 47, 45, 38, 43, 47, 47, 46};
    int h_frames[] = {47, 34, 40, 45, 44, 47, 47, 48, 41, 34, 33, 33};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_JUMPANDMOVE, frame_aux);
}

void ClaseTexturas::jazzIntoxicated() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_INTOXICATED, frame_aux);
}

void ClaseTexturas::jazzHurt() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_HURT, frame_aux);
}

void ClaseTexturas::jazzShoot() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_SHOOT, frame_aux);
}

void ClaseTexturas::jazzStopShoot() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_STOPSHOOT, frame_aux);
}

void ClaseTexturas::jazzShootUp() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_SHOOTUP, frame_aux);
}

void ClaseTexturas::jazzShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_SHOOTANDMOVE, frame_aux);
}

void ClaseTexturas::jazzStopShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_STOPSHOOTANDMOVE, frame_aux);
}

void ClaseTexturas::jazzShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_SHOOTANDFALLING, frame_aux);
}

void ClaseTexturas::jazzStopShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_STOPSHOOTANDFALLING, frame_aux);
}

void ClaseTexturas::jazzDash() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_DASH, frame_aux);
}

void ClaseTexturas::jazzSpecial() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, jazz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(JAZZ_SPECIAL, frame_aux);
}

void ClaseTexturas::spazStand() {

    int x_frames[] = {6, 43, 79, 116, 155, 205};
    int y_frames[] = {817, 817, 813, 813, 813, 817};
    int w_frames[] = {42, 42, 46, 46, 46, 42};
    int h_frames[] = {30, 27, 29, 29, 29, 33};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_STAND, frame_aux);
}

void ClaseTexturas::spazWalk() {

    int x_frames[] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_WALK, frame_aux);
}

void ClaseTexturas::spazJump() {

    int x_frames[] = {5, 59, 110, 156, 200, 241, 281, 323};
    int y_frames[] = {811, 883, 884, 888, 875, 869, 869, 875};
    int w_frames[] = {33, 31, 30, 26, 39, 45, 45, 39};
    int h_frames[] = {55, 47, 42, 41, 36, 35, 33, 32};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_JUMP, frame_aux);
}

void ClaseTexturas::spazRunning() {

    int x_frames[] = {4, 51, 110, 162, 212, 261, 319, 370};
    int y_frames[] = {668, 668, 669, 667, 669, 667, 666, 669};
    int w_frames[] = {36, 28, 37, 37, 35, 28, 39, 35};
    int h_frames[] = {44, 53, 46, 45, 45, 52, 45, 44};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_RUN, frame_aux);
}

void ClaseTexturas::spazJumpAndMove() {

    int x_frames[] = {3, 47, 84, 126, 167, 206, 248, 290, 333, 381, 416, 452};
    int y_frames[] = {606, 603, 604, 604, 604, 604, 604, 602, 598, 596, 596, 596};
    int w_frames[] = {39, 40, 40, 40, 43, 42, 40, 40, 41, 44, 44, 44};
    int h_frames[] = {38, 32, 36, 36, 34, 36, 37, 37, 39, 31, 32, 32};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_JUMPANDMOVE, frame_aux);
}

void ClaseTexturas::spazIntoxicated() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_INTOXICATED, frame_aux);
}

void ClaseTexturas::spazHurt() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_HURT, frame_aux);
}

void ClaseTexturas::spazShoot() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_SHOOT, frame_aux);
}

void ClaseTexturas::spazStopShoot() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_STOPSHOOT, frame_aux);
}

void ClaseTexturas::spazShootUp() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_SHOOTUP, frame_aux);
}

void ClaseTexturas::spazShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_SHOOTANDMOVE, frame_aux);
}

void ClaseTexturas::spazStopShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_STOPSHOOTANDMOVE, frame_aux);
}

void ClaseTexturas::spazShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_SHOOTANDFALLING, frame_aux);
}

void ClaseTexturas::spazStopShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_STOPSHOOTANDFALLING, frame_aux);
}

void ClaseTexturas::spazDash() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_DASH, frame_aux);
}

void ClaseTexturas::spazSpecial() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(SPAZ_SPECIAL, frame_aux);
}


void ClaseTexturas::loriStand() {

    int x_frames[] = {5, 48, 93, 138, 182, 227, 269, 313, 357, 403, 447, 493};
    int y_frames[] = {14, 12, 11, 13, 14, 14, 12, 13, 13, 12, 12, 12};
    int w_frames[] = {51, 53, 54, 52, 51, 51, 53, 52, 52, 53, 53, 53};
    int h_frames[] = {36, 37, 38, 36, 36, 35, 36, 33, 36, 37, 37, 37};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_STAND, frame_aux);
}

void ClaseTexturas::loriWalk() {

    int x_frames[] = {4, 53, 106, 155, 207, 257, 310, 360};
    int y_frames[] = {559, 559, 561, 562, 561, 560, 561, 562};
    int w_frames[] = {47, 38, 44, 43, 45, 37, 43, 44};
    int h_frames[] = {46, 47, 44, 46, 45, 47, 44, 45};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_WALK, frame_aux);
}

void ClaseTexturas::loriJump() {

    int x_frames[] = {5, 39, 80, 122, 163, 206, 253, 298, 343, 385, 421, 458};
    int y_frames[] = {889, 896, 897, 897, 898, 898, 898, 894, 891, 891, 890, 890};
    int w_frames[] = {55, 48, 48, 49, 47, 47, 47, 49, 51, 51, 51, 52};
    int h_frames[] = {31, 36, 34, 36, 41, 41, 40, 39, 35, 30, 30, 30};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_JUMP, frame_aux);
}

void ClaseTexturas::loriRunning() {

    int x_frames[] = {5, 46, 115, 168, 223, 274, 333, 388};
    int y_frames[] = {629, 630, 631, 630, 630, 630, 630, 630};
    int w_frames[] = {38, 27, 36, 37, 37, 27, 37, 37};
    int h_frames[] = {45, 50, 45, 45, 45, 50, 45, 45};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_RUN, frame_aux);
}

void ClaseTexturas::loriJumpAndMove() {

    int x_frames[] = {9, 57, 102, 147, 193, 240, 289, 342, 394, 447, 487, 528, 567};
    int y_frames[] = {980, 980, 979, 979, 979, 979, 979, 979, 979, 966, 966, 966, 966};
    int w_frames[] = {49, 51, 52, 52, 52, 50, 45, 42, 42, 51, 51, 51, 51};
    int h_frames[] = {37, 36, 38, 40, 43, 43, 48, 49, 49, 34, 35, 34, 35};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_JUMPANDMOVE, frame_aux);
}

void ClaseTexturas::loriIntoxicated() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_INTOXICATED, frame_aux);
}

void ClaseTexturas::loriHurt() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_HURT, frame_aux);
}

void ClaseTexturas::loriShoot() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_SHOOT, frame_aux);
}

void ClaseTexturas::loriStopShoot() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_STOPSHOOT, frame_aux);
}

void ClaseTexturas::loriShootUp() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_SHOOTUP, frame_aux);
}

void ClaseTexturas::loriShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_SHOOTANDMOVE, frame_aux);
}

void ClaseTexturas::loriStopShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_STOPSHOOTANDMOVE, frame_aux);
}

void ClaseTexturas::loriShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_SHOOTANDFALLING, frame_aux);
}

void ClaseTexturas::loriStopShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_STOPSHOOTANDFALLING, frame_aux);
}

void ClaseTexturas::loriDash() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_DASH, frame_aux);
}

void ClaseTexturas::loriSpecial() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames(LORI_SPECIAL, frame_aux);
}
