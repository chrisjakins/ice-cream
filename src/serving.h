#ifndef SERVING_H
#define SERVING_H

#include <vector>
#include <memory>

#include "item.h"

/* Employs Factory Pattern */
class Serving {
    public:
        static Serving * create(std::vector<Item *>);

        int numItems();

    private:
        std::vector<Item *> _items;
        void addItem(Item *);
};
#endif
