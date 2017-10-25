#include "scoop.h"
#include <iostream>

int main() {
    Scoop vanilla("vanilla", "for those who like to keep it classy", 2.0, 5.0, 30);

    if (vanilla.getName() != "Vanilla") {
      cerr << "Vanilla test failed: got " << vanilla.getName() << endl;
      return 1;
    }

    return 0;
}
