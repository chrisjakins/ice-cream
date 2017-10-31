#include <deque>

#include "emporium.h"
#include "item.h"
#include "person.h"
#include "order.h"

Emporium::Emporium(int id, double cash)
: _id{id}, _register{cash}
{  }

void Emporium::addItems(Item * item) {
    _items.push_back(item);
}

void Emporium::removeItems(int index) {
    _items.erase(_items.begin() + index);
}
