#include <deque>
#include <string>

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

/***************************
          Listing
***************************/
// what do these functions actually list?
// name and what else?
// formatting?

std::string Emporium::listItems() {
    std::string list = "";
    for (int i = 0; i < _items.size(); i++) {
        list += _items[i]->name();
        list += '\n';
        list += _items[i]->description();
        list += '\n\n';
    }
    return list;
}

std::string Emporium::listPersons() {
    std::string list = "";
    for (int i = 0; i < _persons.size(); i++) {
        list += _persons[i]->id();
        list += '\n';
        list += _persons[i]->name();
        list += '\n\n';
    }
    return list;
}

std::string Emporium::listOrders() {
    std::string list = "";
    for (int i = 0; i < _orders.size(); i++) {
        list += _orders[i]->id();
        list += '\n';
        list += "Served by: \n";
        list += _orders[i]->server();
        list += "Ordered by: \n";
        list += _orders[i]->customer();
        list += '\n\n';
    }
    return list;
}
