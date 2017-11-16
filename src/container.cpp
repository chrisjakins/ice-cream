#include <string>

#include "container.h"
#include "item.h"

namespace mice {

Container::Container(std::string name, std::string description, double wholesaleCost,
                     double retailCost, int stockRemaining, int maxScoop,std::string item_img)
: Item(name, description, wholesaleCost, retailCost, stockRemaining,item_img), maxScoops{maxScoop}

{  }

int Container::max() {
	return maxScoops;
}

void Container::updateMax(int newMax) {
    maxScoops = newMax;
}

std::string Container::type() {
    return "Container";
}

}
