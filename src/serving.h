#ifndef SERVING_H
#define SERVING_H

#include <list>
#include <memory> // not sure if needed
#include <string>

#include "item.h"

/* Employs Factory Pattern */
class Serving {
    public:
        static Serving * create(std::list<Item *>);

        int numItems();
        double price();

        std::string preview();

    private:
        void addItem(Item *);

        std::list<Item *> _items;
};
#endif
