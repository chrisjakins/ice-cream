#include <vector>
#include <string>

#include "order.h"
#include "item.h"
#include "customer.h"
#include "server.h"
#include "serving.h"

Order::Order(int id, Customer cust, Server serv)
: _id{id}, _customer{cust}, _server{serv}
{ }

void Order::addServing(Serving * serv) {
    _servings.push_back(serv);
}

void Order::removeServing(int index) {
    _servings.erase(_servings.begin() + index);
}

double Order::price() {
    double total = 0;
    for (Serving * s : _servings) {
        total += s->price();
    }
    return total;
}

void Order::updateState(const int newState) {
    _state = newState;
}

/*************************
        Listing
*************************/

std::string customer() {
    std::string cust = "";
    cust += _customer->name();
}

std::string server() {
    std::string serv = "";
    serv += _server->name();
}
