#include "server.h"

Server::Server(std::string name, int id, std::string phone, double salary) :
    Person(name, id, phone), _salary{salary} { }

int Server::numOrders() {
    return _numOrders;
}

double Server::salary() {
    return _salary;
}

void Server::setSalary(double newSalary) {
    _salary = newSalary;
}

bool Server::isActive() {
    return _active;
}

void Server::setActive() {
    _active = !_active;
}