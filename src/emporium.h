#ifndef EMPORIUM_H
#define EMPORIUM_H

#include <deque>
#include <vector>
#include <string>

#include "item.h"
#include "order.h"
#include "person.h"

class Emporium {
    public:
        Emporium(int, double);

        void addItem(int, std::vector<std::string>);
        void removeItem(int); // consider not having this removed = stock to 0
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

        void createContainer(std::vector<std::string>);
        void createFlavor(std::vector<std::string>);
        void createTopping(std::vector<std::string>);
};
#endif
