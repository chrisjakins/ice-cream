#include <list>
#include <memory> // unique_ptr?
/* #include <exception>  // Do we need? */
#include <iostream> // debugging

#include "serving.h"
#include "item.h"

Serving * Serving::create(std::list<Item *> items) {
    /* consider error checking here? maybe it should be in upper level
        There is no way that you can have multiple containers in one serving 
        Need to know the container max scoops to error check containers */

    Serving * serving = new Serving();
    for (auto it = items.begin(); it != items.end(); *it++) {
        serving->addItem(*it);
    }
    /* for (unsigned int i = 0; i < items.size(); i++) { */
    /*     serving->addItem(items[i]); */
    /* } */

    return serving;
}

void Serving::addItem(Item * item) {
    _items.push_back(item);
}

int Serving::numItems() {
    return _items.size();
}

double Serving::price() {
    double total = 0;
    for (Item * i : _items) {
        total += i->retailCost();
    }
    return total;
}
