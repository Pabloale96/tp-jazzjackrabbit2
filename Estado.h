#ifndef ESTADO_H
#define ESTADO_H

#include<vector>
#include <iostream>
#include <netinet/in.h>

class Estado {

    private:

    public:
    Estado();
    void run(); // la joda es hacer directamente estado->run.
};

class Normal  : public Estado {

};

class Intoxicado  : public Estado {
    public:
    void run() override;
};

class Impacto  : public Estado {
    public:
    void run() override;
};

class Muerte  : public Estado {
    public:
    void run() override;
};

class RecibirDano  : public Estado {
    public:
    void run() override;
};

#endif
