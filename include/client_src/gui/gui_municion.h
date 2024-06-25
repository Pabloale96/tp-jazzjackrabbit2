#ifndef CantidadMunicionGui_H
#define CantidadMunicionGui_H

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

class CantidadMunicionGui {
private:
    ClaseTexturas& texturas;
    int municion;
    int tipo_arma;

public:
    CantidadMunicionGui(ClaseTexturas&, int, int);
    ~CantidadMunicionGui();

    void show(int);
    void showInf(int);
    void run(int);
    void setMunicion(int municion);
    int getMunicion() const;
    void setTipoArma(int tipo_arma);
    int getTipoArma() const;
};

#endif
