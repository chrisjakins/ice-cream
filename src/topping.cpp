#include <string>

#include "item.h"
#include "topping.h"

// Topping::Topping(std::string name, std::string desc, double wsc, double rtc, int stock, Gtk::Image img, int quant)
// : Item(name, desc, wsc, rtc, stock, img)
// { 
//     _quantity{quant};
// }

Topping::Topping(std::string name, std::string desc, double wsc, double rtc, int stock)
: Item(name, desc, wsc, rtc, stock)
{ }

std::string Topping::type() {
    return "Topping";
}

int Topping::amount() {
    return _quantity;
}
