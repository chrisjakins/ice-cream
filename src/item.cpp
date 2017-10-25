#include <string>

#include "item.h"

bool Item::isInStock() {
    return _stockRemaining != 0;
}

void Item::restock(int addedStock) {
    _stockRemaining += addedStock;
}

void Item::changeRetailCost(double newCost) {
    _retailCost = newCost;
}

void Item::updateDescription(std::string newDesc) {
    _description = newDesc;
}
