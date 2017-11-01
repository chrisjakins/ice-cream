#ifndef _CONTAINER_H
#define _CONTAINER_H

#include <string>

#include "item.h"

class Container : public Item {
  public:
    Container(std::string, std::string, double, double, int, int);

    std::string type() override;
    
    int max();

  private:
    int maxScoops;
};
#endif
