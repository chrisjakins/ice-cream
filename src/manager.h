#ifndef _MANAGER_H
#define _MANAGER_H

#include <string>
#include "person.h"

class Manager: public Person {
    public:
        Manager(std::string, int, std::string);
};
#endif
