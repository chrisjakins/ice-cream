#include "scoop.h"
#include <iostream>

int main() {
    Scoop scoop(Scoop::vanilla);

    if (scoop.to_string() != "vanilla") {
      cerr << "vanilla failed: got " << scoop.to_string() << endl;
      return 1;
    }

    return 0;
}