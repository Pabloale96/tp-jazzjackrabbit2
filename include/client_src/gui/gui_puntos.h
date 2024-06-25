#ifndef PUNTOS_H
#define PUNTOS_H

#include <exception>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "defines_msg.h"
#include "gui_clase_texturas.h"
#include "gui_frame.h"
#include "msgToSent.h"
#include "protocol_utils.h"

class PuntosGui {
private:
    ClaseTexturas& texturas;
    int puntos;

public:
    PuntosGui(ClaseTexturas&, int);
    ~PuntosGui();

    void show(int);
    void setPuntos(int puntos);
    int getPuntos() const;
};

#endif
