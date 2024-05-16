#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <vector>

class Estado {

private:
public:
    Estado();
    virtual void run();  // la joda es hacer directamente estado->run.
};

class Normal: public Estado {
public:
    Normal();
    void run() override;
};

class Intoxicado: public Estado {
public:
    Intoxicado();
    void run() override;
};

class Impacto: public Estado {
public:
    Impacto();
    void run() override;
};

class Muerte: public Estado {
public:
    Muerte();
    void run() override;
};

class RecibirDanio: public Estado {
public:
    RecibirDanio();
    void run() override;
};

#endif
