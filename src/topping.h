#ifndef TOPPING_H
#define TOPPING_H

#include "item.h"

class Topping : public Item {
    public:
        Topping(std::string, std::string, double, double, int, Gtk::Image, int);

        /* for testing purposes before we are ready to work with images */
        Topping(std::string, std::string, double, double, int, int);

    private:
        int _quantity;
};
#endif
