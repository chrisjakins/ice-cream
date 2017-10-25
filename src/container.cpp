#include "container.h"


Container::Container(std::string name, std::string description, double wholesaleCost, double retailCost, int stockRemaining, int maxScoop) :
Item(name, description, wholesaleCost, retailCost, stockRemaining),
maxScoop{maxScoop}
{}


int Container::getMax(){
	return maxScoop;
}
