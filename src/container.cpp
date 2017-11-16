#include <string>

#include "container.h"
#include "item.h"

Container::Container(std::string name, std::string description, double wholesale,
                     double retail, int stockRemaining, int maxScoop)
: Item(name, description, wholesale, retail, stockRemaining), maxScoops{maxScoop}
{  }

int Container::max() {
	return maxScoops;
}

std::string Container::type() {
    return "Container";
}
