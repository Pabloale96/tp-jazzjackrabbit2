#ifndef SERVER_ENEMIGO_H
#define SERVER_ENEMIGO_H

#define ITERACIONES_PARA_REVIVIR 15

class Enemigo {

private:
    bool vivo;
    unsigned int iteraciones;

public:
    // Constructor
    // Inicializa vivo en true y las iteraciones en 0
    Enemigo();

    // Mata al enemigo
    void matar_enemigo();

    // Aumenta las iteraciones del enemigo. Si llega a 15 llama a revivir_enemigo
    void aumentar_iteraciones();

    // Revive al enemigo
    void revivir_enemigo();

    // Devuelve true si el enemigo esta vivo
    bool esta_vivo();
};

#endif
