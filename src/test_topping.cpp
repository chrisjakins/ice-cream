#include <iostream>

#include "topping.h"

int main() {
    Topping peanutButter("Peanut Butter", "feeling nutty, this is the way to go", .05, .20, 30, 5);

    if (peanutButter.name() != "Peanut Butter") {
        std::cerr << "Peanut Butter test failed: got " << peanutButter.name() << std::endl;
    }

    return 0;
}
