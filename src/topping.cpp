#include "item.h"
#include "topping.h"

Topping::Topping(std::string name, std::string desc, double wsc, double rtc, int stock, Gtk::Image img, int quant)
: Item(name, desc, wsc, rtc, stock, img)
{ 
    _quantity{quant};
}

Topping::Topping(std::string name, std::string desc, double wsc, double rtc, int stock, int quant)
: Item(name, desc, wsc, rtc, stock), _quantity(quant)
{ }
