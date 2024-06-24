#include "../../include/client_src/gui/gui_keyhandler.h"


KeyboardHandler::KeyboardHandler() {}


bool KeyboardHandler::checkKeyPress(SDL_Keycode key) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    return currentKeyStates[key];
}

bool KeyboardHandler::keyBoardManaged(Queue<msgAccion>& client_commands, const uint8_t& animacion) {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        msgAccion msg_to_sent;
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_q:
                    return true;
                case SDLK_RIGHT:
                    if ((this->checkKeyPress(SDL_SCANCODE_LCTRL) ||
                         this->checkKeyPress(SDL_SCANCODE_RCTRL)) &&
                        animacion != (uint8_t)efectos::CORRIENDO_RAPIDO) {
                        msg_to_sent = msgAccion(
                                static_cast<uint8_t>(acciones::MOVER_DERECHA_RAPIDO), true);
                        client_commands.push(msg_to_sent);
                    } else if (animacion != (uint8_t)efectos::CORRIENDO ||
                               animacion != (uint8_t)efectos::CORRIENDO_RAPIDO) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::MOVER_DERECHA), true);
                        client_commands.push(msg_to_sent);
                    }
                    break;
                case SDLK_LEFT:
                    if ((this->checkKeyPress(SDL_SCANCODE_LCTRL) ||
                         this->checkKeyPress(SDL_SCANCODE_RCTRL)) &&
                        animacion != (uint8_t)efectos::CORRIENDO_RAPIDO) {
                        msg_to_sent = msgAccion(
                                static_cast<uint8_t>(acciones::MOVER_IZQUIERDA_RAPIDO), true);
                        client_commands.push(msg_to_sent);
                    } else if (animacion != (uint8_t)efectos::CORRIENDO ||
                               animacion != (uint8_t)efectos::CORRIENDO_RAPIDO) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::MOVER_IZQUIERDA), true);
                        client_commands.push(msg_to_sent);
                    }
                    break;
                case SDLK_UP:
                    if (this->checkKeyPress(SDL_SCANCODE_A) &&
                        animacion != (uint8_t)efectos::DISPARANDO_SALTANDO) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::SALTAR_DISPARANDO), true);
                        client_commands.push(msg_to_sent);
                    } else if (animacion != (uint8_t)efectos::SALTANDO) {
                        msg_to_sent = msgAccion(static_cast<uint8_t>(acciones::SALTAR), true);
                        client_commands.push(msg_to_sent);
                    }
                    break;
                case SDLK_s:
                    if (animacion != (uint8_t)efectos::ACCION_ESPECIAL) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::ACCION_ESPECIAL), true);
                        client_commands.push(msg_to_sent);
                    }
                    break;
                case SDLK_a:
                    if (animacion != (uint8_t)efectos::DISPARANDO) {
                        msg_to_sent = msgAccion(static_cast<uint8_t>(acciones::DISPARAR), true);
                        client_commands.push(msg_to_sent);
                    }
                    break;
            }
        } else if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    if (animacion != (uint8_t)efectos::IDLE) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::MOVER_DERECHA), false);
                        client_commands.push(msg_to_sent);
                    }
                    break;
                case SDLK_LEFT:
                    if (animacion != (uint8_t)efectos::IDLE) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::MOVER_IZQUIERDA), false);
                        client_commands.push(msg_to_sent);
                    }
                    break;
                case SDLK_UP:
                    if (animacion != (uint8_t)efectos::IDLE) {
                        msg_to_sent = msgAccion(static_cast<uint8_t>(acciones::SALTAR), false);
                        client_commands.push(msg_to_sent);
                    }
                    break;
                case SDLK_a:
                    if (animacion != (uint8_t) efectos::IDLE) {
                        msg_to_sent = msgAccion(static_cast<uint8_t>(acciones::DISPARAR), false);
                        client_commands.push(msg_to_sent);
                    }
                    break;
                case SDLK_s:
                    if (animacion != (uint8_t)efectos::IDLE) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::ACCION_ESPECIAL), false);
                        client_commands.push(msg_to_sent);
                    }
                    break;
            }
        }
    }
    return false;
}
