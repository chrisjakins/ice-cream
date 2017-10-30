#include "server.h"

Server::Server(std::string name, int id, std::string phone, double salary) :
    Person(name, id, phone), _salary{salary} { }

int Server::numOrders() {
    return _numOrders;
}

double Server::salary() {
    return _salary;
}