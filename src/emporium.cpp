#include <deque>
#include <vector>
#include <string>
#include <sstream>

#include "emporium.h"
#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "item.h"
#include "person.h"
#include "order.h"

Emporium::Emporium(int id, double cash)
: _id{id}, _register{cash}
{  }

void Emporium::addItem(int type, std::vector<std::string> ins) {
    switch (type) {
        case 0: createContainer(ins); break;
        case 1: createFlavor(ins); break;
        case 2: createTopping(ins); break;
        default: break;
    }
}

void Emporium::removeItem(int index) {
    _items.erase(_items.begin() + index);
}

void Emporium::addServer(std::vector<std::string> ins) {
    std::string name, number;
    int id;
    double salary;
    std::stringstream ss;
    for (unsigned int i = 0; i < ins.size(); i++) {
        ss << ins[i];
    }
    ss >> name >> id >> number >> salary;
    _persons.push_back(new Server{name, id, number, salary});
}

void Emporium::addCustomer(std::vector<std::string> ins) {
    std::string name, number;
    int id;
    std::stringstream ss;
    for (unsigned int i = 0; i < ins.size(); i++) {
        ss << ins[i];
    }
    ss >> name >> id >> number;
    _persons.push_back(new Customer{name, id, number});
}

/***************************
          Listing
***************************/
// what do these functions actually list?
// name and what else?
// formatting?
std::vector<Item *> Emporium::containers() {
    std::vector<Item *> cont;
    for (unsigned int i = 0; i < _items.size(); i++) {
        if (_items[i]->type() == "Container") {
            cont.push_back(_items[i]);
        }
    }
    return cont;
}

std::vector<Item *> Emporium::scoops() {
    std::vector<Item *> scps;
    for (unsigned int i = 0; i < _items.size(); i++) {
        if (_items[i]->type() == "Scoop") {
            scps.push_back(_items[i]);
        }
    }
    return scps;
}

std::vector<Item *> Emporium::toppings() {
    std::vector<Item *> topp;
    for (unsigned int i = 0; i < _items.size(); i++) {
        if (_items[i]->type() == "Topping") {
            topp.push_back(_items[i]);
        }
    }
    return topp;
}

std::string Emporium::listPersons() {
    std::string list = "";
    for (unsigned int i = 0; i < _persons.size(); i++) {
        list += _persons[i]->id();
        list += "\n";
        list += _persons[i]->name();
        list += "\n\n";
    }
    return list;
}

std::string Emporium::listOrders() {
    std::string list = "";
    for (unsigned int i = 0; i < _orders.size(); i++) {
        list += _orders[i]->id();
        list += "\n";
        list += "Served by: \n";
        list += _orders[i]->server();
        list += "Ordered by: \n";
        list += _orders[i]->customer();
        list += "\n\n";
    }
    return list;
}

/****************************
           Creation
****************************/
void Emporium::createContainer(std::vector<std::string> ins) {
    std::stringstream ss;
    int maxScoops, stock;
    double cost, price;

    std::string name = ins[0];
    std::string desc = ins[1];
    ss << ins[2] << ins[3] << ins[4] << ins[5];
    ss >> cost >> price >> stock >> maxScoops;

    _items.push_back(new Container{name, desc, cost, price, stock, maxScoops});
}

void Emporium::createFlavor(std::vector<std::string> ins) {
    std::stringstream ss;
    int stock;
    double cost, price;

    std::string name = ins[0];
    std::string desc = ins[1];
    ss << ins[2] << ins[3] << ins[4];
    ss >> cost >> price >> stock;

    _items.push_back(new Scoop{name, desc, cost, price, stock});
}

void Emporium::createTopping(std::vector<std::string> ins) {
    std::stringstream ss;
    int stock;
    double cost, price;

    std::string name = ins[0];
    std::string desc = ins[1];
    ss << ins[2] << ins[3] << ins[4];
    ss >> cost >> price >> stock;

    _items.push_back(new Topping{name, desc, cost, price, stock});
}
