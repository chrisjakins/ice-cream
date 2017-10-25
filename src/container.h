#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <string>
#include "item.h"


class Container: protected Item{
  public:
    Container(std::string name, std::string description, double wholesaleCost, double retailCost, int stockRemaining, int maxScoop);
    
    
    
    int getMax();

  private:
    int maxScoop;
};
#endif
