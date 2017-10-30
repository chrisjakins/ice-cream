#include <iostream>

#include "container.h"

int main() {
    Container container("vanila","vanilla duh",5.0,6.0,3,5);
    if (container.max() != 5) {
        std::cerr << "bowl failed: got " << container.max() << std::endl;
    }

    return 0;
}
