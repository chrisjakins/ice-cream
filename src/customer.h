#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>
#include "person.h"

class Customer: public Person {
    public:
        Customer(std::string, int, std::string);
};
#endif
