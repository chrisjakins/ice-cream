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
        static Serving * create(mice::Container *, std::vector<Scoop *>, Topping *);

        Serving(mice::Container container);
        Serving();

        void add_scoop(Scoop scoop);
        mice::Container container();
        std::vector<Scoop *> scoops();
        Topping toppings();
        double wholesaleCost();
        double price();
        // std::string preview();

        friend std::ostream & operator<<(std::ostream & os, const Serving & serv);

      private:
        mice::Container * _container;
        std::vector<Scoop *> _scoops;
        Topping * _toppings;

        /**** private constructor ****/
        /* Serving(mice::Container *,) */
};
#endif
