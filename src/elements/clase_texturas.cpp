#include "../../include/clase_texturas.h"


ClaseTexturas::~ClaseTexturas() {}

void ClaseTexturas::addFrames(std::string key, std::vector<Frame> value) { frames[key] = value; }

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
    addFrames("jazzStand", frame_aux);
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
    addFrames("jazzWalk", frame_aux);
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
    addFrames("jazzJump", frame_aux);
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
    addFrames("jazzRun", frame_aux);
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
    addFrames("jazzJumpAndMove", frame_aux);
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
    addFrames("jazzIntoxicated", frame_aux);
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
    addFrames("jazzHurt", frame_aux);
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
    addFrames("jazzShoot", frame_aux);
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
    addFrames("jazzStopShoot", frame_aux);
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
    addFrames("jazzShootUp", frame_aux);
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
    addFrames("jazzShootAndMove", frame_aux);
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
    addFrames("jazzStopShootAndMove", frame_aux);
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
    addFrames("jazzShootAndFalling", frame_aux);
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
    addFrames("jazzStopShootAndFalling", frame_aux);
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
    addFrames("jazzDash", frame_aux);
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
    addFrames("jazzSpecial", frame_aux);
}

void ClaseTexturas::spazStand() {

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
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("spazStand", frame_aux);
}

void ClaseTexturas::spazWalk() {

    int x_frames[] = {2, 56, 114, 170, 228, 284, 340, 397};
    int y_frames[] = {795, 792, 792, 796, 794, 792, 792, 796};
    int w_frames[] = {41, 44, 44, 40, 42, 44, 44, 40};
    int h_frames[] = {52, 45, 54, 55, 54, 55, 56, 56};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("spazWalk", frame_aux);
}

void ClaseTexturas::spazJump() {

    int x_frames[] = {7, 50, 102, 1131, 1130, 1131, 1129, 1132, 1130, 1124, 1124, 1123};
    int y_frames[] = {1123, 1128, 1130, 154, 200, 241, 283, 333, 338, 445, 502, 563};
    int w_frames[] = {50, 47, 47, 48, 48, 47, 44, 44, 45, 46, 45};
    int h_frames[] = {38, 46, 47, 40, 38, 45, 51, 54, 54, 57, 56};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("spazJump", frame_aux);
}

void ClaseTexturas::spazRunning() {

    int x_frames[] = {3, 67, 139, 205, 272, 337, 409, 472};
    int y_frames[] = {856, 857, 856, 856, 857, 856, 857, 858};
    int w_frames[] = {35, 34, 35, 35, 34, 34, 33};
    int h_frames[] = {61, 67, 62, 63, 62, 58, 61};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("spazRun", frame_aux);
}

void ClaseTexturas::spazJumpAndMove() {

    int x_frames[] = {4, 54, 92, 134, 183, 230, 282, 332, 384, 430, 466, 502};
    int y_frames[] = {1210, 1208, 1210, 1210, 1209, 1209, 1208, 1208, 1203, 1199, 1199, 1200};
    int w_frames[] = {44, 47, 44, 45, 48, 47, 45, 38, 43, 47, 47, 46};
    int h_frames[] = {47, 34, 40, 45, 44, 47, 47, 48, 41, 34, 33, 33};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, spaz_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("spazJumpAndMove", frame_aux);
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
    addFrames("spazIntoxicated", frame_aux);
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
    addFrames("spazHurt", frame_aux);
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
    addFrames("spazShoot", frame_aux);
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
    addFrames("spazStopShoot", frame_aux);
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
    addFrames("spazShootUp", frame_aux);
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
    addFrames("spazShootAndMove", frame_aux);
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
    addFrames("spazStopShootAndMove", frame_aux);
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
    addFrames("spazShootAndFalling", frame_aux);
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
    addFrames("spazStopShootAndFalling", frame_aux);
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
    addFrames("spazDash", frame_aux);
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
    addFrames("spazSpecial", frame_aux);
}


void ClaseTexturas::loriStand() {

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
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("loriStand", frame_aux);
}

void ClaseTexturas::loriWalk() {

    int x_frames[] = {2, 56, 114, 170, 228, 284, 340, 397};
    int y_frames[] = {795, 792, 792, 796, 794, 792, 792, 796};
    int w_frames[] = {41, 44, 44, 40, 42, 44, 44, 40};
    int h_frames[] = {52, 45, 54, 55, 54, 55, 56, 56};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("loriWalk", frame_aux);
}

void ClaseTexturas::loriJump() {

    int x_frames[] = {7, 50, 102, 1131, 1130, 1131, 1129, 1132, 1130, 1124, 1124, 1123};
    int y_frames[] = {1123, 1128, 1130, 154, 200, 241, 283, 333, 338, 445, 502, 563};
    int w_frames[] = {50, 47, 47, 48, 48, 47, 44, 44, 45, 46, 45};
    int h_frames[] = {38, 46, 47, 40, 38, 45, 51, 54, 54, 57, 56};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("loriJump", frame_aux);
}

void ClaseTexturas::loriRunning() {

    int x_frames[] = {3, 67, 139, 205, 272, 337, 409, 472};
    int y_frames[] = {856, 857, 856, 856, 857, 856, 857, 858};
    int w_frames[] = {35, 34, 35, 35, 34, 34, 33};
    int h_frames[] = {61, 67, 62, 63, 62, 58, 61};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("loriRun", frame_aux);
}

void ClaseTexturas::loriJumpAndMove() {

    int x_frames[] = {4, 54, 92, 134, 183, 230, 282, 332, 384, 430, 466, 502};
    int y_frames[] = {1210, 1208, 1210, 1210, 1209, 1209, 1208, 1208, 1203, 1199, 1199, 1200};
    int w_frames[] = {44, 47, 44, 45, 48, 47, 45, 38, 43, 47, 47, 46};
    int h_frames[] = {47, 34, 40, 45, 44, 47, 47, 48, 41, 34, 33, 33};

    std::vector<Frame> frame_aux;
    for (size_t i = 0; i < (sizeof(x_frames) / sizeof(x_frames[0])); i++) {
        Frame frame(renderer, lori_tex);
        frame.setFrame(x_frames[i], y_frames[i], h_frames[i], w_frames[i]);
        frame_aux.emplace_back(frame);
    }
    addFrames("loriJumpAndMove", frame_aux);
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
    addFrames("loriIntoxicated", frame_aux);
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
    addFrames("loriHurt", frame_aux);
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
    addFrames("loriShoot", frame_aux);
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
    addFrames("loriStopShoot", frame_aux);
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
    addFrames("loriShootUp", frame_aux);
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
    addFrames("loriShootAndMove", frame_aux);
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
    addFrames("loriStopShootAndMove", frame_aux);
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
    addFrames("loriShootAndFalling", frame_aux);
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
    addFrames("loriStopShootAndFalling", frame_aux);
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
    addFrames("loriDash", frame_aux);
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
    addFrames("loriSpecial", frame_aux);
}
