#include "person.h"

Person::Person(std::string name, int id, std::string phone)
: _name{name}, _id{id}, _phone{phone} 
{ }

void Person::toggle_active() {
    _active = !_active;
}
