#include "person.h"

Person::Person(std::string name, int id, std::string phone)
: _name{name}, _phone{phone}, _id{id}
{ }

std::string Person::name() {
    return _name;
}

int Person::id() {
    return _id;
}

std::string Person::phone() {
    return _phone;
}

bool Person::isActive() {
    return _active;
}

void Person::toggle_active() {
    _active = !_active;
}
