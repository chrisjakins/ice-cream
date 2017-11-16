#ifndef TOPPING_H
#define TOPPING_H

#include <string>

#include "item.h"

class Topping : public Item {
    public:
        // Topping(std::string, std::string, double, double, int, Gtk::Image, int);

        /* for testing purposes before we are ready to work with images */
        Topping(std::string, std::string, double, double, int);

        std::string type() override;
        int amount();


        const static int LIGHT = 1;
        const static int NORMAL = 2;
        const static int EXTRA = 3;
        const static int DRENCHED = 4;
        
    private:
        int _quantity;
};
#endif
