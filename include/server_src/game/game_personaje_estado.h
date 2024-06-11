#ifndef _GAME_PERSONAJE_ESTADO_H
#define _GAME_PERSONAJE_ESTADO_H

#include <iostream>
#include <vector>

class EstadoPersonaje {
private:
    bool idle;
    bool corriendo;
    bool corriendo_muy_rapido;
    bool saltando;
    bool cayendo;
    bool disparando;
    bool accion_especial;

    bool recibiendo_danio;
    bool muerto;

    bool intoxicado;

public:
    EstadoPersonaje() {
        idle = true;
        corriendo = false;
        corriendo_muy_rapido = false;
        saltando = false;
        cayendo = false;
        disparando = false;
        accion_especial = false;

        recibiendo_danio = false;
        muerto = false;

        intoxicado = false;
    }

    void setIdle(bool value) { idle = value; }

    bool getIdle() { return idle; }

    void setCorriendo(bool value) { corriendo = value; }

    bool getCorriendo() { return corriendo; }

    void setCorriendoMuyRapido(bool value) { corriendo_muy_rapido = value; }

    bool getCorriendoMuyRapido() { return corriendo_muy_rapido; }

    void setSaltando(bool value) { saltando = value; }

    bool getSaltando() { return saltando; }

    void setCayendo(bool value) { cayendo = value; }

    bool getCayendo() { return cayendo; }

    void setDisparando(bool value) {
        if (esta_intoxicado() == true) {
            disparando = false;
        } else {
            disparando = value;
        }
    }

    bool getDisparando() { return disparando; }

    void setAccionEspecial(bool value) { accion_especial = value; }

    bool getAccionEspecial() { return accion_especial; }

    void setRecibiendoDanio(bool value) { recibiendo_danio = value; }

    bool getRecibiendoDanio() { return recibiendo_danio; }

    void setMuerto(bool value) { muerto = value; }

    bool getMuerto() { return muerto; }

    void setIntoxicado(bool value) { intoxicado = value; }

    bool esta_intoxicado() { return intoxicado; }

    void reset() {
        idle = false;
        corriendo = false;
        corriendo_muy_rapido = false;
        saltando = false;
        cayendo = false;
        disparando = false;
        accion_especial = false;

        recibiendo_danio = false;
        muerto = false;

        intoxicado = false;
    }

    void obtener_estado(std::vector<bool>& estados) {
        estados.push_back(idle);
        estados.push_back(corriendo);
        estados.push_back(corriendo_muy_rapido);
        estados.push_back(saltando);
        estados.push_back(cayendo);
        estados.push_back(disparando);
        estados.push_back(accion_especial);

        estados.push_back(recibiendo_danio);
        estados.push_back(muerto);

        estados.push_back(intoxicado);
    }

    void getAll() {
        std::cout << "idle: " << idle << std::endl;
        std::cout << "corriendo: " << corriendo << std::endl;
        std::cout << "corriendo_muy_rapido: " << corriendo_muy_rapido << std::endl;
        std::cout << "saltando: " << saltando << std::endl;
        std::cout << "cayendo: " << cayendo << std::endl;
        std::cout << "disparando: " << disparando << std::endl;
        std::cout << "accion_especial: " << accion_especial << std::endl;

        std::cout << "recibiendo_danio: " << recibiendo_danio << std::endl;
        std::cout << "muerto: " << muerto << std::endl;

        std::cout << "intoxicado: " << intoxicado << std::endl;
    }

    void setear_estado_respuesta(uint8_t estado_recibido) {
        reset();
        switch (estado_recibido) {
            case 1:
                setIdle(true);
                break;
            case 2:
                setDisparando(true);
                break;
            case 3:
                setCorriendo(true);
                break;
            case 4:
                setCorriendoMuyRapido(true);
                break;
            case 5:
                setSaltando(true);
                break;
            case 6:
                setCayendo(true);
                break;
            case 7: 
                setIntoxicado(true);
                break;
            case 8:
                setRecibiendoDanio(true);
                break;
            case 9:
                setMuerto(true);
                break;
            case 10:
                setAccionEspecial(true);
                break;
            default:
                std::cout << "Estado no reconocido" << std::endl;
                break;
        }
    }

    ~EstadoPersonaje() {}
};

#endif
