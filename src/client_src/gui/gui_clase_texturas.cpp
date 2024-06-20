#include "../../include/client_src/gui/gui_clase_texturas.h"

Texture& ClaseTexturas::jazz_text() { return jazz_tex; }
Texture& ClaseTexturas::spaz_text() { return spaz_tex; }
Texture& ClaseTexturas::lori_text() { return lori_tex; }
Texture& ClaseTexturas::beach_text() { return beach_tex; }

std::shared_ptr<std::vector<Frame>>& ClaseTexturas::findFrame(std::string frame_string) {
    auto it = frames_map.find(frame_string);
    return it->second;
}

// Definiciones de la clase, de aca para abajo solo se toca
// si se cambio el sprite:

ClaseTexturas::ClaseTexturas(Renderer& render): renderer(render) {

    this->plataformaTipo1();

    this->enemigo1();
    this->enemigo2();
    this->enemigo3();


    this->enemigo1();
    this->enemigo2();
    this->enemigo3();

    this->zanahoria();
    this->municion();
    this->moneda();
    this->gema();
    this->balas1();
    this->balas2();

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

void ClaseTexturas::addFrames(const std::string& key, std::shared_ptr<std::vector<Frame>> & frame){
    frames_map.emplace(key, frame);
}

void ClaseTexturas::add_frames_to_map(int* x_frames, int* y_frames, int* w_frames, int* h_frames,
                                      int frame_count, Texture& textura_del_personaje,
                                      const std::string& key) {
    std::shared_ptr<std::vector<Frame>> frame_aux = std::make_shared<std::vector<Frame>>();
    for (int i = 0; i < frame_count; i++) {
        Frame frame(renderer, textura_del_personaje, x_frames[i], y_frames[i], w_frames[i],
                    h_frames[i]);
        frame_aux->emplace_back(frame);
    }
    addFrames(key, frame_aux);
}

void ClaseTexturas::balas1() {

    int x_frames[] = {86, 103, 120, 136, 152, 168, 184, 199, 213, 229};
    int y_frames[] = {361, 361, 361, 361, 361, 361, 361, 361, 361, 361};
    int w_frames[] = {14, 14, 14, 14, 14, 14, 14, 14, 14, 14};
    int h_frames[] = {14, 13, 13, 13, 13, 13, 12, 11, 13, 13};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, items_tex, BALA1);
}

void ClaseTexturas::balas2() {

    int x_frames[] = {86, 103, 120, 136, 152, 168, 184, 199, 213, 229};
    int y_frames[] = {378, 378, 378, 378, 378, 378, 378, 378, 378, 378};
    int w_frames[] = {13, 13, 13, 13, 13, 13, 13, 13, 13, 13};
    int h_frames[] = {14, 13, 13, 13, 13, 13, 12, 11, 13, 13};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, items_tex, BALA2);
}

void ClaseTexturas::zanahoria() {

    int x_frames[] = {807, 835, 862, 883, 901, 939, 967, 993, 1015, 1033};
    int y_frames[] = {1163, 1163, 1163, 1163, 1163, 1163, 1163, 1163, 1163, 1163};
    int w_frames[] = {34, 34, 34, 34, 34, 34, 34, 34, 34, 34};
    int h_frames[] = {25, 23, 18, 15, 34, 25, 23, 18, 15, 34};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, items_tex, ZANAHORIA);
}
void ClaseTexturas::municion() {

    int x_frames[] = {65, 88, 110, 126, 142, 164, 187, 209, 225, 241};
    int y_frames[] = {302, 302, 302, 302, 302, 302, 302, 302, 302, 302};
    int w_frames[] = {17, 17, 17, 17, 17, 17, 17, 17, 17, 17};
    int h_frames[] = {20, 19, 13, 13, 19, 20, 19, 13, 13, 19};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, items_tex, MUNICION);
}
void ClaseTexturas::gema() {

    int x_frames[] = {56, 107, 159, 212, 265, 318, 371, 424};
    int y_frames[] = {1190, 1190, 1190, 1190, 1190, 1190, 1190, 1190, 1190};
    int w_frames[] = {49, 49, 49, 49, 49, 49, 49, 49};
    int h_frames[] = {49, 49, 49, 49, 49, 49, 49, 49};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, items_tex, GEMA);
}
void ClaseTexturas::moneda() {

    int x_frames[] = {484, 510, 535, 558, 577, 592, 602, 617, 636, 660,
                      686, 712, 738, 762, 781, 796, 806, 820, 838, 861};
    int y_frames[] = {1220, 1220, 1220, 1220, 1220, 1220, 1220, 1220, 1220, 1220,
                      1220, 1220, 1220, 1220, 1220, 1220, 1220, 1220, 1220, 1220};
    int w_frames[] = {23, 23, 23, 23, 23, 23, 23, 23, 23, 23,
                      23, 23, 23, 23, 23, 23, 23, 23, 23, 23};
    int h_frames[] = {23, 22, 20, 16, 12, 7, 12, 16, 21, 23, 23, 23, 21, 16, 12, 7, 12, 16, 21, 21};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, items_tex, MONEDA);
}


void ClaseTexturas::enemigo1() {

    int x_frames[] = {17, 99, 165, 220, 299, 368, 434, 512, 597, 679, 753, 831};
    int y_frames[] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
    int w_frames[] = {61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61};
    int h_frames[] = {62, 52, 44, 67, 52, 51, 59, 59, 62, 60, 70, 73};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, enemigos_tex,
                      ENEMIGO1_GUI);
}

void ClaseTexturas::enemigo2() {

    int x_frames[] = {728, 800, 872, 947, 30,  111, 192, 274,
                      358, 434, 506, 579, 663, 746, 826, 914};
    int y_frames[] = {662, 662, 662, 662, 700, 700, 700, 700,
                      700, 700, 700, 700, 700, 700, 700, 700};
    int w_frames[] = {33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33};
    int h_frames[] = {67, 63, 70, 73, 78, 75, 75, 73, 71, 68, 67, 72, 73, 73, 80, 83};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, enemigos_tex,
                      ENEMIGO2_GUI);
}

void ClaseTexturas::enemigo3() {

    int x_frames[] = {18, 89, 153, 222, 291, 356, 403, 439};
    int y_frames[] = {392, 392, 392, 392, 392, 392, 392, 392};
    int w_frames[] = {40, 40, 40, 40, 40, 40, 40, 40};
    int h_frames[] = {62, 57, 64, 63, 59, 42, 24, 60};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, enemigos_tex,
                      ENEMIGO3_GUI);
}

void ClaseTexturas::plataformaTipo1() {

    int x_frame = 0;
    int y_frame = 2560;
    int w_frame = 29;
    int h_frame = 192;

    std::shared_ptr<std::vector<Frame>> frame_aux = std::make_shared<std::vector<Frame>>();
    Frame frame(renderer, beach_tex, x_frame, y_frame, w_frame, h_frame);
    frame_aux->emplace_back(frame);
    addFrames(PLATFORM_BEACH_TYPE_1, frame_aux);
}

void ClaseTexturas::jazzStand() {

    int x_frames[] = {2,   41,  81, 122, 163, 205, 253, 303, 353, 403, 448, 491, 535, 580,
                      625, 671, 2,  50,  100, 150, 194, 233, 275, 313, 354, 394, 434};
    int y_frames[] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                      12, 12, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63};
    int w_frames[] = {49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
                      49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49};
    int h_frames[] = {34, 34, 34, 35, 37, 40, 46, 44, 38, 38, 38, 38, 39, 39,
                      39, 39, 43, 45, 45, 40, 35, 34, 33, 35, 34, 35, 33};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex, JAZZ_STAND);
}

void ClaseTexturas::jazzWalk() {

    int x_frames[] = {2, 58, 116, 172, 230, 286, 342, 399};
    int y_frames[] = {792, 792, 792, 792, 792, 792, 792, 792};
    int w_frames[] = {44, 44, 44, 44, 44, 44, 44, 44};
    int h_frames[] = {54, 55, 53, 54, 54, 54, 55, 55};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex, JAZZ_WALK);
}

void ClaseTexturas::jazzJump() {

    int x_frames[] = {6, 50, 102, 154, 200, 241, 283, 332, 388, 445, 502, 563};
    int y_frames[] = {1122, 1122, 1122, 1122, 1122, 1122, 1122, 1122, 1122, 1122, 1122, 1122};
    int w_frames[] = {57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57};
    int h_frames[] = {39, 46, 48, 40, 38, 38, 45, 52, 54, 53, 57, 55};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex, JAZZ_JUMP);
}

void ClaseTexturas::jazzRunning() {

    int x_frames[] = {3, 73, 139, 210};
    int y_frames[] = {996, 996, 996, 996};
    int w_frames[] = {39, 39, 39, 39};
    int h_frames[] = {66, 63, 67, 62};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex, JAZZ_RUN);
}

void ClaseTexturas::jazzJumpAndMove() {

    int x_frames[] = {2, 54, 92, 134, 183, 230, 282, 332, 384, 430, 466, 502};
    int y_frames[] = {1198, 1198, 1198, 1198, 1198, 1198, 1198, 1198, 1198, 1198, 1198, 1198};
    int w_frames[] = {59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59};
    int h_frames[] = {46, 34, 39, 44, 43, 47, 47, 48, 41, 32, 33, 33};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex,
                      JAZZ_JUMPANDMOVE);
}

void ClaseTexturas::jazzIntoxicated() {

    int x_frames[] = {4, 54, 106, 157, 209, 261, 314, 369};
    int y_frames[] = {2166, 2166, 2166, 2166, 2166, 2166, 2166, 2166};
    int w_frames[] = {49, 49, 49, 49, 49, 49, 49, 49};
    int h_frames[] = {41, 41, 40, 42, 40, 39, 42, 41};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex,
                      JAZZ_INTOXICATED);
}

void ClaseTexturas::jazzHurt() {

    int x_frames[] = {4, 46, 86, 128, 175, 228, 294, 366, 446};
    int y_frames[] = {3011, 3011, 3011, 3011, 3011, 3011, 3011, 3011, 3011};
    int w_frames[] = {61, 61, 61, 61, 61, 61, 61, 61, 61};
    int h_frames[] = {34, 31, 32, 35, 41, 58, 68, 71, 72};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex, JAZZ_HURT);
}

void ClaseTexturas::jazzShoot() {

    int x_frames[] = {2, 52};
    int y_frames[] = {557, 557};
    int w_frames[] = {56, 56};
    int h_frames[] = {45, 42};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex, JAZZ_SHOOT);
}

void ClaseTexturas::jazzStopShoot() {

    int x_frames[] = {105, 144, 187, 229};
    int y_frames[] = {557, 557, 557, 557};
    int w_frames[] = {56, 56, 56, 56};
    int h_frames[] = {31, 34, 32, 32};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex,
                      JAZZ_STOPSHOOT);
}

void ClaseTexturas::jazzShootUp() {

    int x_frames[] = {106, 149};
    int y_frames[] = {634, 634};
    int w_frames[] = {66, 66};
    int h_frames[] = {38, 38};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex, JAZZ_SHOOTUP);
}

// creo que conviene directamente usar WALK
void ClaseTexturas::jazzShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex,
                      JAZZ_SHOOTANDMOVE);
}

// creo que conviene directamente usar WALK
void ClaseTexturas::jazzStopShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex,
                      JAZZ_STOPSHOOTANDMOVE);
}

// creo que conviene directamente usar WALK
void ClaseTexturas::jazzShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex,
                      JAZZ_SHOOTANDFALLING);
}

// creo que conviene directamente usar WALK
void ClaseTexturas::jazzStopShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex,
                      JAZZ_STOPSHOOTANDFALLING);
}

// no hace falta
void ClaseTexturas::jazzDash() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex, JAZZ_DASH);
}

void ClaseTexturas::jazzSpecial() {

    int x_frames[] = {2, 59, 114, 160, 204, 240, 273, 303, 329, 355, 388, 430};
    int y_frames[] = {716, 716, 716, 716, 716, 716, 716, 716, 716, 716, 716, 716};
    int w_frames[] = {56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56};
    int h_frames[] = {54, 51, 41, 37, 32, 28, 23, 22, 23, 22, 39, 49};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, jazz_tex, JAZZ_SPECIAL);
}

void ClaseTexturas::spazStand() {

    int x_frames[] = {5, 42, 78, 115, 154, 204};
    int y_frames[] = {11, 11, 11, 11, 11, 11};
    int w_frames[] = {46, 46, 46, 46, 46, 46};
    int h_frames[] = {30, 27, 29, 29, 29, 33};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex, SPAZ_STAND);
}

void ClaseTexturas::spazWalk() {

    int x_frames[] = {3, 51, 103, 154, 204, 256, 306, 355};
    int y_frames[] = {749, 749, 749, 749, 749, 749, 749, 749};
    int w_frames[] = {42, 42, 42, 42, 42, 42, 42, 42};
    int h_frames[] = {44, 46, 43, 44, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex, SPAZ_WALK);
}

void ClaseTexturas::spazJump() {

    int x_frames[] = {2, 40, 83, 126, 174, 219, 263};
    int y_frames[] = {1066, 1066, 1066, 1066, 1066, 1066, 1066};
    int w_frames[] = {48, 48, 48, 48, 48, 48, 48};
    int h_frames[] = {31, 34, 32, 42, 39, 37, 45};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex, SPAZ_JUMP);
}

void ClaseTexturas::spazRunning() {

    int x_frames[] = {4, 60, 115, 168};
    int y_frames[] = {939, 939, 939, 939};
    int w_frames[] = {38, 38, 38, 38};
    int h_frames[] = {64, 48, 49, 49};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex, SPAZ_RUN);
}

void ClaseTexturas::spazJumpAndMove() {

    int x_frames[] = {4, 46, 83, 125, 166, 206, 247, 289};
    int y_frames[] = {1142, 1142, 1142, 1142, 1142, 1142, 1142, 1142};
    int w_frames[] = {38, 32, 36, 36, 34, 35, 37, 40};
    int h_frames[] = {51, 51, 51, 51, 51, 51, 51, 51};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex,
                      SPAZ_JUMPANDMOVE);
}

void ClaseTexturas::spazIntoxicated() {

    int x_frames[] = {4, 48, 92, 136, 184, 231, 279, 320};
    int y_frames[] = {2067, 2067, 2067, 2067, 2067, 2067, 2067, 2067};
    int w_frames[] = {51, 51, 51, 51, 51, 51, 51, 51};
    int h_frames[] = {36, 34, 36, 36, 38, 37, 31, 34};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex,
                      SPAZ_INTOXICATED);
}

void ClaseTexturas::spazHurt() {

    int x_frames[] = {4, 46, 107, 163, 234, 320, 408, 491, 554, 619, 679};
    int y_frames[] = {2916, 2916, 2916, 2916, 2916, 2916, 2916, 2916, 2916, 2916, 2916};
    int w_frames[] = {62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62};
    int h_frames[] = {40, 40, 44, 58, 69, 65, 62, 54, 57, 50, 41};


    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex, SPAZ_HURT);
}

void ClaseTexturas::spazShoot() {

    int x_frames[] = {5, 56};
    int y_frames[] = {504, 504};
    int w_frames[] = {45, 45};
    int h_frames[] = {45, 40};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex, SPAZ_SHOOT);
}

void ClaseTexturas::spazStopShoot() {

    int x_frames[] = {106, 156, 188, 235};
    int y_frames[] = {504, 504, 504, 504};
    int w_frames[] = {45, 45, 45, 45};
    int h_frames[] = {45, 32, 43, 42};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex,
                      SPAZ_STOPSHOOT);
}

void ClaseTexturas::spazShootUp() {

    int x_frames[] = {95, 136};
    int y_frames[] = {600, 600};
    int w_frames[] = {59, 59};
    int h_frames[] = {36, 36};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex, SPAZ_SHOOTUP);
}


// creo que conviene directamente usar WALK
void ClaseTexturas::spazShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex,
                      SPAZ_SHOOTANDMOVE);
}

// creo que conviene directamente usar stop shoot
void ClaseTexturas::spazStopShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex,
                      SPAZ_STOPSHOOTANDMOVE);
}

// creo que conviene directamente usar stop shoot
void ClaseTexturas::spazShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex,
                      SPAZ_SHOOTANDFALLING);
}

// creo que conviene directamente usar shoot
void ClaseTexturas::spazStopShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex,
                      SPAZ_STOPSHOOTANDFALLING);
}

// no hace falta
void ClaseTexturas::spazDash() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex, SPAZ_DASH);
}

void ClaseTexturas::spazSpecial() {

    int x_frames[] = {4, 52, 104, 145, 184, 228, 275, 327, 383, 436, 496, 546};
    int y_frames[] = {681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681, 681};
    int w_frames[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
    int h_frames[] = {43, 47, 36, 34, 40, 44, 48, 53, 53, 53, 45, 42};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, spaz_tex, SPAZ_SPECIAL);
}

void ClaseTexturas::loriStand() {

    int x_frames[] = {5, 48, 93, 138, 182, 227, 269, 313, 357, 403, 447, 493};
    int y_frames[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int w_frames[] = {54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54};
    int h_frames[] = {36, 36, 36, 36, 36, 36, 35, 37, 36, 37, 36, 37};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex, LORI_STAND);
}

void ClaseTexturas::loriWalk() {

    int x_frames[] = {5, 53, 106, 155, 207, 257, 310, 360};
    int y_frames[] = {557, 557, 557, 557, 557, 557, 557, 557};
    int w_frames[] = {49, 49, 49, 49, 49, 49, 49, 49};
    int h_frames[] = {43, 47, 42, 44, 43, 47, 43, 43};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex, LORI_WALK);
}

void ClaseTexturas::loriJump() {

    int x_frames[] = {5, 39, 80, 122, 163, 206, 253, 298, 343, 385, 421, 458};
    int y_frames[] = {888, 888, 888, 888, 888, 888, 888, 888, 888, 888, 888, 888};
    int w_frames[] = {57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57};
    int h_frames[] = {32, 59, 99, 35, 38, 38, 41, 38, 35, 29, 30, 31};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex, LORI_JUMP);
}

void ClaseTexturas::loriRunning() {

    int x_frames[] = {3, 67, 130, 198, 264, 330, 395, 458};
    int y_frames[] = {763, 763, 763, 763, 763, 763, 763, 763};
    int w_frames[] = {42, 42, 42, 42, 42, 42, 42, 42};
    int h_frames[] = {67, 59, 63, 57, 59, 59, 58, 61};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex, LORI_RUN);
}

void ClaseTexturas::loriJumpAndMove() {

    int x_frames[] = {9, 57, 102, 147, 193, 240, 289, 342, 394, 447, 487, 528, 567};
    int y_frames[] = {965, 965, 965, 965, 965, 965, 965, 965, 965, 965, 965, 965, 965};
    int w_frames[] = {66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66};
    int h_frames[] = {36, 36, 38, 40, 41, 44, 48, 49, 49, 34, 33, 32, 33};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex,
                      LORI_JUMPANDMOVE);
}

void ClaseTexturas::loriIntoxicated() {

    int x_frames[] = {5, 63, 122, 182, 255, 311, 373, 425, 475, 527, 580, 635};
    int y_frames[] = {1903, 1903, 1903, 1903, 1903, 1903, 1903, 1903, 1903, 1903, 1903, 1903};
    int w_frames[] = {48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48};
    int h_frames[] = {47, 50, 51, 53, 54, 55, 42, 42, 40, 42, 45, 45};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex,
                      LORI_INTOXICATED);
}

void ClaseTexturas::loriHurt() {

    int x_frames[] = {4, 55, 102, 141, 186, 240, 300, 357, 410, 456, 504};
    int y_frames[] = {2568, 2568, 2568, 2568, 2568, 2568, 2568, 2568, 2568, 2568, 2568};
    int w_frames[] = {54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54};
    int h_frames[] = {43, 39, 30, 38, 47, 53, 47, 46, 39, 37, 33};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex, LORI_HURT);
}

void ClaseTexturas::loriShoot() {

    int x_frames[] = {6, 54};
    int y_frames[] = {343, 343};
    int w_frames[] = {54, 54};
    int h_frames[] = {38, 34};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex, LORI_SHOOT);
}

void ClaseTexturas::loriStopShoot() {

    int x_frames[] = {102, 143, 184, 225};
    int y_frames[] = {343, 343, 343, 343};
    int w_frames[] = {54, 54, 54, 54};
    int h_frames[] = {33, 32, 35, 34};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex,
                      LORI_STOPSHOOT);
}

void ClaseTexturas::loriShootUp() {

    int x_frames[] = {96, 138};
    int y_frames[] = {416, 416};
    int w_frames[] = {52, 52};
    int h_frames[] = {36, 37};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex, LORI_SHOOTUP);
}

// creo que conviene directamente usar walk
void ClaseTexturas::loriShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex,
                      LORI_SHOOTANDMOVE);
}

// creo que conviene directamente usar walk
void ClaseTexturas::loriStopShootAndMove() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex,
                      LORI_STOPSHOOTANDMOVE);
}

// creo que conviene directamente usar walk
void ClaseTexturas::loriShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex,
                      LORI_SHOOTANDFALLING);
}

// creo que conviene directamente usar walk
void ClaseTexturas::loriStopShootAndFalling() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex,
                      LORI_STOPSHOOTANDFALLING);
}

// no hace falta
void ClaseTexturas::loriDash() {

    int x_frames[8] = {4, 52, 103, 154, 205, 257, 307, 356};
    int y_frames[8] = {944, 944, 944, 944, 944, 944, 944, 944};
    int w_frames[8] = {43, 43, 43, 43, 43, 43, 43, 43};
    int h_frames[8] = {45, 46, 45, 45, 46, 45, 45, 46};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex, LORI_DASH);
}

void ClaseTexturas::loriSpecial() {

    int x_frames[] = {6, 54, 102, 148, 194, 244, 300, 357, 422, 493};
    int y_frames[] = {483, 483, 483, 483, 483, 483, 483, 483, 483, 483};
    int w_frames[] = {59, 59, 59, 59, 59, 59, 59, 59, 59, 59};
    int h_frames[] = {40, 37, 36, 39, 40, 40, 43, 57, 59, 58};

    int frame_count = sizeof(x_frames) / sizeof(x_frames[0]);
    add_frames_to_map(x_frames, y_frames, w_frames, h_frames, frame_count, lori_tex, LORI_SPECIAL);
}
