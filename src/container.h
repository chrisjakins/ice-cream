#ifndef _CONTAINER_H
#define _CONTAINER_H

#include <string>

#include "item.h"

class Container : protected Item {
  public:
    Container(std::string, std::string, double, double, int, int);
    
    int getMax();

  private:
    int maxScoop;
};
#endif
