#ifndef EMPORIUM_H
#define EMPORIUM_H

#include <deque>
#include <string>

#include "item.h"
#include "order.h"
#include "person.h"

class Emporium {
    public:
        Emporium(int, double);

        void addItems(Item *);
        void removeItems(int); // consider not having this removed = stock to 0
        std::string listItems();

        void addPerson(Person *);
        std::string listPersons();
        
        void addOrder(Order *);
        std::string listOrders();

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
