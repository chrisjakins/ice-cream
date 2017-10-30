#ifndef SERVING_H
#define SERVING_H

#include <list>
#include <memory> // not sure if needed

#include "item.h"

/* Employs Factory Pattern */
class Serving {
    public:
        static Serving * create(std::list<Item *>);

        int numItems();
        double price();

    private:
        std::list<Item *> _items;
        void addItem(Item *);
};
#endif
