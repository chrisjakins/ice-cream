#include <iostream>

#include "topping.h"

int main() {
    Topping peanutButter("Peanut Butter", "feeling nutty, this is the way to go", .05, .20, 30, 5);

    if (peanutButter.getName() != "Peanut Butter") {
        std::cerr << "Peanut Butter test failed: got " << peanutButter.getName() << std::endl;
    }

    return 0;
}
