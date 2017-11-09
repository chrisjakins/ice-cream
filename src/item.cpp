#include <string>
//#include <gtkmm.h>

#include "item.h"

//Item::Item(std::string name, std::string desc, double wsc, double rtc, int stock, Gtk::Image img)
//: _name{name}, _description{desc}, _wholesaleCost{wsc},
//  _retailCost{rtc}, _stockRemaining{stock}, _image{img}
//{ }

Item::Item(std::string name, std::string desc, double wsc, double rtc, int stock,std::string item_img)
: _name(name), _description(desc), _wholesaleCost(wsc),
  _retailCost(rtc), _stockRemaining(stock),_img(item_img)
{ }

bool Item::isInStock() {
    return _stockRemaining != 0;
}

void Item::restock(int addedStock) {
    _stockRemaining += addedStock;
}

void Item::consume(int quantity) {
    _stockRemaining -= quantity;
}

void Item::changeRetailCost(double newCost) {
    _retailCost = newCost;
}

void Item::updateDescription(std::string newDesc) {
    _description = newDesc;
}

std::string Item::name() {
    return _name;
}
std::string Item::img(){
    return _img;
}
double Item::wholesaleCost() {
    return _wholesaleCost;
}

double Item::retailCost() {
    return _retailCost;
}

int Item::stock() {
    return _stockRemaining;
}

std::string Item::description() {
    return _description;
}
