#include "container.h"


Container::Container(std::string name, std::string description, double wholesaleCost, double retailCost, int stockRemaining, int maxScoop) :  
maxScoop{maxScoop}
{_name = name;
_description = description;
_wholesaleCost = wholesaleCost;
_retailCost = retailCost;
_stockRemaining = stockRemaining;
}


int Container::getMax(){
	return maxScoop;
}
