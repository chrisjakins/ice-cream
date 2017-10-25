#include "scoop.h"
#include <iostream>

int main() {
    Scoop scoop(Scoop::chocolate);

    if (scoop.to_string() != "chocolate") {
      cerr << "chocolate failed: got " << scoop.to_string() << endl;
      return 1;
    }

    return 0;
}
