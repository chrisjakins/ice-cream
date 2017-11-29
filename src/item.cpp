#include <string>
//#include <gtkmm.h>

#include "item.h"

//Item::Item(std::string name, std::string desc, double wsc, double rtc, int stock, Gtk::Image img)
//: _name{name}, _description{desc}, _wholesaleCost{wsc},
//  _retailCost{rtc}, _stockRemaining{stock}, _image{img}
//{ }

Item::Item(std::string name, std::string desc, double wsc, double rtc, int stock,std::string item_img)
: _name(name), _description(desc), _wholesaleCost(wsc),
  _retailCost(rtc), _stockRemaining(stock)
{
    _image = Gtk::manage(new Gtk::Image(item_img));
 }

int Item::stock() {
    return _stockRemaining;
}

bool Item::isInStock() {
    return _stockRemaining != 0;
}

void Item::restock(int addedStock) {
    _stockRemaining += addedStock;
}

void Item::consume(int quantity) {
    _stockRemaining -= quantity;
}

std::string Item::name() {
    return _name;
}

void Item::updateName(std::string newName) {
    _name = newName;
}

Gtk::Image* Item::img(){
    return _image;
}

double Item::wholesaleCost() {
    return _wholesaleCost;
}

void Item::updateWholesaleCost(double newCost) {
    _wholesaleCost = newCost;
}

double Item::retailCost() {
    return _retailCost;
}

void Item::updateRetailCost(double newCost) {
    _retailCost = newCost;
}

std::string Item::description() {
    return _description;
}
void Item::updateDescription(std::string newDesc) {
    _description = newDesc;
}

bool Item::isActive() {
    return _active;
}

