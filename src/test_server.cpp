#include <iostream>
#include "server.h"

int main() {

    Server serv("Sal", 6732373, "(478)-673-2373", 9.25);

    if (serv.name() != "Sal") {
        std::cerr << "##### Name test failed" << std::endl
        << "EXPECTED: Sal" << std::endl
        << "ACTUAL: " << serv.name() << std::endl;
    }

    return 0;
}
