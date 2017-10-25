#include <string>

#include "item.h"

Item(std::string name, std::string desc, double wsc, double rtc, int stock, Gtk::Image img)
: _name{name}, _description{desc}, _wholesaleCost{wsc},
  _retail{rtc}, _stockRemaining{stock}, _image{image}
{ }

Item::Item(std::string name, std::string desc, double wsc, double rtc, int stock)
: _name(name), _description(desc), _wholesaleCost(wsc),
  _retailCost(rtc), _stockRemaining(stock)
{ }

bool Item::isInStock() {
    return _stockRemaining != 0;
}

void Item::restock(int addedStock) {
    _stockRemaining += addedStock;
}

void Item::changeRetailCost(double newCost) {
    _retailCost = newCost;
}

void Item::updateDescription(std::string newDesc) {
    _description = newDesc;
}

std::string Item::getName() {
    return _name;
}

double Item::getWholesaleCost() {
    return _wholesaleCost;
}

double Item::getRetailCost() {
    return _retailCost;
}

int Item::getStock() {
    return _stockRemaining;
}

