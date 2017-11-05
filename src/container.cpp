#include <string>

#include "container.h"

namespace mice {

Container::Container(std::string name, std::string description, double wholesaleCost,
                     double retailCost, int stockRemaining, int maxScoop)
: Item(name, description, wholesaleCost, retailCost, stockRemaining), maxScoop{maxScoop}
{  }

int Container::max() {
	return maxScoop;
}

std::string Container::type() {
    return "Container";
}

}
