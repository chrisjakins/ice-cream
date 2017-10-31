#ifndef EMPORIUM_H
#define EMPORIUM_H

#include <deque>

#include "item.h"
#include "order.h"
#include "person.h"

class Emporium {
    public:
        Emporium(int, double);

        void addItems(Item *);
        void removeItems(int);

        /* FILE I/O */
        /* void load(std::istream); */
        /* void save(std::ostream); */
    private:
        int _id;
        double _register = 0;
        std::deque<Item *> _items;
        std::deque<Person *> _persons;        
        std::deque<Order *> _orders;
};
#endif
