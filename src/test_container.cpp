#include "container.h"
#include <iostream>

int main() {
    Container container("vanila","vanilla duh",5.0,6.0,3,5);
    if (container.getMax() != 5) {
      std::cerr << "bowl failed: got " << container.getMax() << std::endl;
      return 1;
    }

    return 0;
}
