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

void Emporium::addItemStock(std::string name, int newStock) {
    for (unsigned int i = 0; i < _containers.size(); i++) {
        if (name == _containers[i]->name()) {
            _containers[i]->restock(newStock);
            return;
        }
    }

    for (unsigned int i = 0; i < _scoops.size(); i++) {
        if (name == _scoops[i]->name()) {
            _scoops[i]->restock(newStock);
            return;
        }
    }
    for (unsigned int i = 0; i < _toppings.size(); i++) {
        if (name == _toppings[i]->name()) {
            _toppings[i]->restock(newStock);
            return;
        }
    }
}

// void Emporium::removeItem(int index) {
//     _items.erase(_items.begin() + index);
// }

void Emporium::addServer(std::vector<std::string> ins) {
    std::string name = ins[0], number = ins[1];
    int id = std::stoi(ins[2]);
    double salary = std::stod(ins[3]);
    _servers.push_back(new Server{name, id, number, salary});
}

void Emporium::addCustomer(std::vector<std::string> ins) {
    std::string name, number;
    int id;
    std::stringstream ss;
    for (unsigned int i = 0; i < ins.size(); i++) {
        ss << ins[i];
    }
    ss >> name >> id >> number;
    _customers.push_back(new Customer{name, id, number});
}

void Emporium::changeServerSalary(int serverNumber, double newSalary) {
    _servers[serverNumber]->setSalary(newSalary);
}

/***************************
          Listing
***************************/
// what do these functions actually list?
// name and what else?
// formatting?
std::vector<mice::Container *> Emporium::containers() {
    std::vector<mice::Container *> cont;
    for (unsigned int i = 0; i < _containers.size(); i++) {
        cont.push_back(_containers[i]);
    }
    return cont;
}

std::vector<Scoop *> Emporium::scoops() {
    std::vector<Scoop *> scps;
    for (unsigned int i = 0; i < _scoops.size(); i++) {
        scps.push_back(_scoops[i]);
    }
    return scps;
}

std::vector<Topping *> Emporium::toppings() {
    std::vector<Topping *> topp;
    for (unsigned int i = 0; i < _toppings.size(); i++) {
        topp.push_back(_toppings[i]);
    }
    return topp;
}

std::vector<Server *> Emporium::servers() {
    return _servers;
}

// std::string Emporium::listPersons() {
//     std::string list = "";
//     for (unsigned int i = 0; i < _persons.size(); i++) {
//         list += _persons[i]->id();
//         list += "\n";
//         list += _persons[i]->name();
//         list += "\n\n";
//     }
//     return list;
// }

std::string Emporium::listContainers() {
    std::string cont = "";
    for (unsigned int i = 0; i < _containers.size(); i++) {
        cont += _containers[i]->name() + " - ";
        cont += std::to_string(_containers[i]->stock()) + "\n";
    }
    return cont;
}

std::string Emporium::listScoops() {
    std::string scps = "";
    for (unsigned int i = 0; i < _containers.size(); i++) {
        scps += _scoops[i]->name() + " - ";
        scps += std::to_string(_scoops[i]->stock()) + "\n";
    }
    return scps;
}

std::string Emporium::listToppings() {
    std::string tops = "";
    for (unsigned int i = 0; i < _containers.size(); i++) {
        tops += _toppings[i]->name() + " - ";
        tops += std::to_string(_toppings[i]->stock()) + "\n";
    }
    return tops;
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
    std::string name = ins[1], desc = ins[2], img ="img/"+ins[6];
    int maxScoops, stock;
    double cost, price;
    
    maxScoops = stoi(ins[0]);
    cost = stof(ins[3]);
    price = stof(ins[4]);
    stock = stoi(ins[5]); 

    _containers.push_back(new mice::Container{name, desc, cost, price, stock, maxScoops,img});
}

void Emporium::createFlavor(std::vector<std::string> ins) {
    int stock;
    double cost, price;

    std::string name = ins[0];
    std::string desc = ins[1];
    std::string img = "img/"+ins[5];
    cost = stof(ins[2]);
    price = stof(ins[3]);
    stock = stoi(ins[4]);

    _scoops.push_back(new Scoop{name, desc, cost, price, stock,img});
}

void Emporium::createTopping(std::vector<std::string> ins) {
    int stock;
    double cost, price;

    std::string name = ins[0];
    std::string desc = ins[1];
    std::string img  = "img/"+ins[5];
    cost = stof(ins[2]);
    price = stof(ins[3]);
    stock = stoi(ins[4]);

    _toppings.push_back(new Topping{name, desc, cost, price, stock, img});
}
