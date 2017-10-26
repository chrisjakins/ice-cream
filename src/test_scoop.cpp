#include "scoop.h"
#include <iostream>

int main() {
    Scoop vanilla("Vanilla", "for those who like to keep it classy", 2.0, 5.0, 30);

    if (vanilla.getName() != "Vanilla") {
        std::cerr << "Vanilla test failed: got " << vanilla.getName() << std::endl;
    }

    return 0;
}
