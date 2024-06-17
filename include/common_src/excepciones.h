// Copyright 2024 Martin Di Paola

#ifndef ERROR_ENVIO_ESCENARIO_H
#define ERROR_ENVIO_ESCENARIO_H

#include <exception>

struct ErrorEnviarDatos: public std::runtime_error {
    ErrorEnviarDatos(): std::runtime_error("The queue is closed") {}
};

#endif
