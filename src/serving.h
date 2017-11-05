#ifndef SERVING_H
#define SERVING_H

#include <string>
#include <vector>

#include "container.h"
#include "scoop.h"
#include "topping.h"

/* Employs Factory Pattern */
class Serving {
    public:
        Serving(Container container);
        void add_scoop(Scoop scoop);
        void add_topping(Topping topping);
        Container container();
        std::vector<Scoop> scoops();
        std::vector<Topping> toppings();
        double wholesaleCost();
        double price();
        // std::string preview();

      private:
        Container _container;
        std::vector<Scoop> _scoops;
        std::vector<Topping> _toppings;
};
#endif
