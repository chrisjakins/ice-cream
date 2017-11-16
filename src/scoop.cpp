#include <string>

#include "scoop.h"

// Scoop::Scoop(std::string name, std::string desc, double wsc, double rtc, int stock, Gtk::Image img)
// : Item(name, desc, wsc, rtc, stock, img)
// { }

Scoop::Scoop(std::string name, std::string desc, double wsc, double rtc, int stock,std::string item_img)
: Item(name, desc, wsc, rtc, stock,item_img)
{ }

std::string Scoop::type() {
    return "Scoop";
}
