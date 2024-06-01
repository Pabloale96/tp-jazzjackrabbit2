#include <exception>
#include <iostream>

#include "../include/gui.h"

int main() try {

    Gui gui;
    gui.run();

    return 0;
} catch (std::exception& e) {
    // If case of error, print it and exit with error
    std::cerr << e.what() << std::endl;
    return 1;
}
