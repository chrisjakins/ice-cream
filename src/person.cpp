#include "person.h"

Person::Person(std::string name, int id, std::string phone) {
    _name = name;
    _id = id;
    _phone = phone;
}

std::string Person::getName() {
    return _name;
}

int Person::getId() {
    return _id;
}

std::string Person::getPhone() {
    return _phone;
}

bool Person::isActive() {
    return _active;
}

void Person::toggle_active() {
    _active = !_active;
}
