#include "../../include/server_src/game/game_personaje.h"

#include "../../include/common_src/msgToSent.h"
#include "../../include/server_src/yaml_config.h"

#define ID_BALA_INICIAL 0

#define VEL_X_INICIAL 0
#define VEL_Y_INICIAL 0

#define SEGUNDOS_DE_SALTO 1

Personaje::Personaje(uint16_t partida_id, uint16_t client_id,
                     std::chrono::seconds tiempo_restante_de_partida):
        partida_id(partida_id),
        client_id(client_id),
        tipo_personaje(),
        puntos(YAMLConfig::getConfig().personaje.puntos),
        vida(YAMLConfig::getConfig().personaje.vidas),

        arma(std::make_unique<ArmaInicial>()),
        bala_id(ID_BALA_INICIAL),

        posicion(YAMLConfig::getConfig().personaje.pos_x, YAMLConfig::getConfig().personaje.pos_y),
        gravedad(-0.1f),
        velocidad(0, gravedad),
        ancho(1.0f),
        alto(1.0f),
        altura_salto(1.0f),
        altura_acumulada(0.0f),

        tiempo_restante_de_partida(tiempo_restante_de_partida),
        duracion_muerto(0),

        estados() {}

Personaje::Personaje(msgPersonaje& personaje):
        partida_id(0),
        client_id(ntohs(personaje.personaje[POS_ID_PERSONAJE])),
        tipo_personaje(personaje.tipo_personaje),
        puntos(personaje.personaje[POS_PUNTOS_PERSONAJE]),
        vida(ntohs(personaje.personaje[POS_VIDA_PERSONAJE])),

        arma(arma->crear_arma(ntohs(personaje.personaje[POS_MUNICION_PERSONAJE]),
                              personaje.tipo_arma)),

        posicion(personaje.personaje[POS_POSX_PERSONAJE], personaje.personaje[POS_POSY_PERSONAJE]),
        estados() {
    // estados.setear_estado_respuesta(personaje.estado);
}

void Personaje::asignar_tipo_personaje(uint8_t tipo_personaje) {
    this->tipo_personaje = tipo_personaje;
}

void Personaje::intoxicar() { estados.setIntoxicado(true); }

EstadoPersonaje& Personaje::obtener_estados() { return estados; }

uint8_t Personaje::obtener_estado_actual() {
    // Combinaciones
    //      Con disparar
    if (estados.getDisparando() && estados.getCorriendo()) {
        return (uint8_t)efectos::DISPARANDO_CORRIENDO;
    } else if (estados.getDisparando() && estados.getSaltando()) {
        return (uint8_t)efectos::DISPARANDO_SALTANDO;
    } else if (estados.getDisparando() && estados.getCayendo()) {
        return (uint8_t)efectos::DISPARANDO_CAYENDO;

        //      Con correr
    } else if (estados.getCorriendo() && estados.getSaltando()) {
        return (uint8_t)efectos::CORRIENDO_SALTANDO;

        // Estados individuales
    } else if (estados.esta_intoxicado()) {
        return (uint8_t)efectos::INTOXICADO;
    } else if (estados.getCorriendo()) {
        return (uint8_t)efectos::CORRIENDO;
    } else if (estados.getCorriendoMuyRapido()) {
        return (uint8_t)efectos::CORRIENDO_RAPIDO;
    } else if (estados.getSaltando()) {
        return (uint8_t)efectos::SALTANDO;
    } else if (estados.getCayendo()) {
        return (uint8_t)efectos::CAYENDO;
    } else if (estados.getDisparando()) {
        return (uint8_t)efectos::DISPARANDO;
    } else if (estados.getAccionEspecial()) {
        return (uint8_t)efectos::ACCION_ESPECIAL;
    } else if (estados.getMuerto()) {
        return (uint8_t)efectos::MUERTO;
    } else {
        // caso default
        return (uint8_t)efectos::IDLE;
    }
}

uint8_t Personaje::obtener_animacion() { return animacion; }

void Personaje::actualizar(std::chrono::seconds tiempo_restante_de_partida,
                           std::vector<Plataforma>& plataformas) {
    //std::cout << "ACTUALIZANDO Personaje: " << client_id << std::endl;
    set_tiempo_restante_de_partida(tiempo_restante_de_partida);
    for (auto& municion: municiones_disparadas) {
    //    std::cout << "Bala: " << municion.obtener_id() << std::endl;
    //    std::cout << "PRE Posicion: (" << municion.obtener_posicion().get_posicion_x() << ", "
    //                << municion.obtener_posicion().get_posicion_y() << ")." << std::endl;
    //    std::cout << "PRE Velocidad: (" << municion.obtener_velocidad().obtener_velocidad_x() << ", "
    //                << municion.obtener_velocidad().obtener_velocidad_y() << ")." << std::endl;
        municion.mover();
    //    std::cout << "POST Posicion: (" << municion.obtener_posicion().get_posicion_x() << ", "
    //                << municion.obtener_posicion().get_posicion_y() << ")." << std::endl;
    }

    if (vida == 0) {
        velocidad.idle();
        estados.setMuerto(true);
        duracion_muerto++;
        if (duracion_muerto ==
            std::chrono::seconds(YAMLConfig::getConfig().personaje.segundos_para_revivir)) {
            vida = YAMLConfig::getConfig().personaje.vidas;
            estados.setMuerto(false);
            estados.reset();
            estados.setIdle(true);
            duracion_muerto = std::chrono::seconds(0);
        }
        return;
    }

    if (!estados.getMuerto()) {
        this->mover(plataformas);
    }
}

void Personaje::set_tiempo_restante_de_partida(std::chrono::seconds tiempo_restante_de_partida) {
    this->tiempo_restante_de_partida = tiempo_restante_de_partida;
}

void Personaje::mover(std::vector<Plataforma>& plataformas) {
    chequear_colisiones(plataformas);
}

void Personaje::chequear_colisiones(const std::vector<Plataforma>& plataformas) {
    float prox_pos_x = posicion.get_posicion_x() + velocidad.obtener_velocidad_x();
    float prox_pos_y = posicion.get_posicion_y() + velocidad.obtener_velocidad_y();

    for (const auto& plataforma : plataformas) {
        if (velocidad.obtener_velocidad_x() < 0) {
            if (plataforma.estoy_adentro_de_la_plataforma(prox_pos_x, prox_pos_y)) {
                velocidad.setear_velocidad_x(0);
                estados.setCorriendo(false);
                estados.setIdle(true);
                break;
            }
        } else if (velocidad.obtener_velocidad_x() > 0) {
            if (plataforma.estoy_adentro_de_la_plataforma(prox_pos_x + ancho, prox_pos_y)) {
                velocidad.setear_velocidad_x(0);
                estados.setCorriendo(false);
                estados.setIdle(true);
                break;
            }
        }
    }

    bool hay_piso = false;
    for (const auto& plataforma : plataformas) {
        if (velocidad.obtener_velocidad_y() < 0) {
            if (plataforma.estoy_adentro_de_la_plataforma(prox_pos_x, prox_pos_y)) {
                hay_piso = true;
                // std::cout << "COLISION CON PISO" << std::endl;
                velocidad.setear_velocidad_y(0);
                estados.setCayendo(false);
                estados.setIdle(true);
                break;
            }
        } else if (velocidad.obtener_velocidad_y() > 0) {
            if (plataforma.estoy_adentro_de_la_plataforma(prox_pos_x, prox_pos_y)) {
                // std::cout << "COLISION CON TECHO" << std::endl;
                altura_acumulada = 0;
                velocidad.setear_velocidad_y(0); // Detener la subida
                velocidad.caer(); // Iniciar la caída
                estados.setSaltando(false);
                estados.setCayendo(true);
                return;
            }
        }
    }

    if ( !hay_piso && estados.getCayendo()) {
        // std::cout << "NO HAY PISO" << std::endl;
        velocidad.caer();
        estados.setCayendo(true);
    }

    if (velocidad.obtener_velocidad_y() > 0) {
        if (altura_acumulada >= altura_salto) {
            // std::cout << "ALTURA MAXIMA DEL SALTO" << std::endl;
            velocidad.setear_velocidad_y(0); // Detener la subida
            velocidad.caer(); // Iniciar la caída
            estados.setSaltando(false);
            estados.setCayendo(true);
            altura_acumulada = 0;
        } else {
            altura_acumulada += velocidad.obtener_velocidad_y();
        }
    }

    this->posicion.mover(this->velocidad);
}

/*
bool Game::colision_diagonal(const Personaje& personaje, const Plataforma& plataforma) {
    float personajeCenterX = personaje.getLeft() + personaje.obtener_ancho() / 2;
    float personajeBottomY = personaje.getBottom();

    float plataformaStartX = plataforma.obtener_vertice_izq_abajo().get_posicion_x();
    float plataformaEndX = plataforma.obtener_vertice_der_abajo().get_posicion_x();
    float plataformaStartY = plataforma.obtener_vertice_izq_abajo().get_posicion_y();
    float plataformaEndY = plataforma.obtener_vertice_der_arriba().get_posicion_y();

    float m = (plataformaEndY - plataformaStartY) / (plataformaEndX - plataformaStartX);
    float b = plataformaStartY - m * plataformaStartX;

    float plataformaYatJugadorX = m * personajeCenterX + b;

    bool interseca = personajeBottomY >= plataformaYatJugadorX &&
                     personajeBottomY <= plataformaYatJugadorX + 1 &&
                     personajeCenterX >= plataformaStartX && personajeCenterX <= plataformaEndX;

    return interseca;
}
*/

void Personaje::disminuir_vida(uint16_t danio) {
    if (vida > danio) {
        vida -= danio;
        estados.setRecibiendoDanio(true);
    } else {
        vida = 0;
        estados.setMuerto(true);
    }
}

void Personaje::disparar() {
    if (arma->obtener_municion() == 0) {
        return;
    } else {
        arma->disminuir_municion();
        this->estados.reset();
        this->estados.setDisparando(true);
        float vel_dis_con_direccion_personaje = arma->obtener_vel_dis();
        if (this->obtener_velocidad().obtener_velocidad_x() < 0) {
            vel_dis_con_direccion_personaje *= -1;
        }
        municiones_disparadas.emplace_back(
                obtener_posicion().get_posicion_x(), obtener_posicion().get_posicion_y(),
                vel_dis_con_direccion_personaje, arma->obtener_nombre_arma(), generar_id_bala());
    }
}

void Personaje::cambiar_arma() {
    if (arma->obtener_nombre_arma() == static_cast<uint8_t>(armas::ARMA_INICIAL)) {
        arma = std::make_unique<Arma1>();
        // El orden es: arma inicial -> arma 1 -> arma 2
        // } else if (arma->obtener_nombre_arma() == static_cast<uint8_t>(armas::ARMA_1)) {
        //    arma = std::make_unique<Arma2>();
    } else {
        arma = std::make_unique<ArmaInicial>();
    }
}

void Personaje::eliminar_bala(uint16_t id_bala) {
    for (auto it = municiones_disparadas.begin(); it != municiones_disparadas.end(); ++it) {
        if (it->obtener_id() == id_bala) {
            municiones_disparadas.erase(it);
            break;
        }
    }
}

std::vector<Municion> Personaje::obtener_balas() const { return municiones_disparadas; }

size_t Personaje::obtener_cantidad_balas() const { return municiones_disparadas.size(); }

void Personaje::disminuir_municion() { arma->disminuir_municion(); }

Posicion Personaje::obtener_posicion() const { return posicion; }

Velocidad& Personaje::obtener_velocidad() { return velocidad; }

uint16_t Personaje::obtener_partida_id() const { return partida_id; }

uint16_t Personaje::obtener_personaje_id() const { return client_id; }

uint8_t Personaje::obtener_tipo_personaje() const { return tipo_personaje; }

uint16_t Personaje::obtener_puntos() const { return puntos; }

uint16_t Personaje::obtener_vida() const { return vida; }

uint16_t Personaje::obtener_municion() const { return arma->obtener_municion(); }

uint16_t Personaje::generar_id_bala() { return bala_id++; }

uint8_t Personaje::obtener_nombre_arma() const { return arma->obtener_nombre_arma(); }

std::chrono::seconds Personaje::obtener_tiempo_restante_de_partida() const {
    return tiempo_restante_de_partida;
}

float Personaje::getBottom() const { return posicion.get_posicion_y(); }
float Personaje::getTop() const { return posicion.get_posicion_y() + alto; }
float Personaje::getLeft() const { return posicion.get_posicion_x(); }
float Personaje::getRight() const { return posicion.get_posicion_x() + ancho; }

float Personaje::obtener_ancho() const { return ancho; }

void Personaje::setear_posicion_en_x(float x) { posicion.set_posicion_en_x(x); }

void Personaje::setear_posicion_en_y(float y) { posicion.set_posicion_en_y(y); }


// ************  JAZZ  ************
Jazz::Jazz(uint16_t partida_id, uint16_t client_id,
           std::chrono::seconds tiempo_restante_de_partida):
        Personaje(partida_id, client_id, tiempo_restante_de_partida) {
    asignar_tipo_personaje(static_cast<uint8_t>(personajes::JAZZ));
}

Jazz::Jazz(msgPersonaje& personaje): Personaje(personaje) {}

void Jazz::accion_especial() {  // Punietazo hacia arriba
    // Jazz puede hacer un salto vertical, sin posiilidad de moverse lateralemten, pero realizando
    // daño con todo lo que toque
    obtener_velocidad().setear_velocidad_x(0);
    obtener_velocidad().saltar();
}


// ************  LORI  ************
Lori::Lori(uint16_t partida_id, uint16_t client_id,
           std::chrono::seconds tiempo_restante_de_partida):
        Personaje(partida_id, client_id, tiempo_restante_de_partida) {
    asignar_tipo_personaje(static_cast<uint8_t>(personajes::LORI));
}

Lori::Lori(msgPersonaje& personaje): Personaje(personaje) {}

void Lori::accion_especial() {  // Patada de corto alcance
    // Lori puede hacer una patada voladora de corto alcance mientras da un salto (tal como si fuese
    // una accion de salto), realizando daño con todo lo que toque
    obtener_velocidad().saltar();
}


// ************  SPAZZ  ************
Spazz::Spazz(uint16_t partida_id, uint16_t client_id,
             std::chrono::seconds tiempo_restante_de_partida):
        Personaje(partida_id, client_id, tiempo_restante_de_partida) {
    asignar_tipo_personaje(static_cast<uint8_t>(personajes::SPAZZ));
}

Spazz::Spazz(msgPersonaje& personaje): Personaje(personaje) {}

void Spazz::accion_especial() {  // Patada hacia un costado
    // Spazz puede hacer una patada que la desplaza de forma lateral, sin poder saltar hacia arriba,
    // realizando daño con todo lo que toque
    obtener_velocidad().setear_velocidad_y(0);
}

Personaje* crear_personaje(uint16_t partida_id, uint16_t client_id, uint8_t personaje,
                           std::chrono::seconds tiempo_restante_de_partida) {
    if (personaje == static_cast<uint8_t>(personajes::JAZZ)) {
        return new Jazz(partida_id, client_id, tiempo_restante_de_partida);
    } else if (personaje == static_cast<uint8_t>(personajes::SPAZZ)) {
        return new Spazz(partida_id, client_id, tiempo_restante_de_partida);
    } else if (personaje == static_cast<uint8_t>(personajes::LORI)) {
        return new Lori(partida_id, client_id, tiempo_restante_de_partida);
    } else {
        return nullptr;
    }
}
