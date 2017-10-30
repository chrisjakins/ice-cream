#include <list>

#include "item.h"
#include "customer.h"
#include "server.h"
#include "serving.h"

Order::Order(Customer cust, Server serv, int id)
: _customer{cust}, _server{serv}, _id{id}
{ }

void Order::addServing(Serving * serv) {
    _servings.push_back(serv);
}

void Order::removeServing(int index) {
    _servings.erase(_servings.begin() + i);
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
