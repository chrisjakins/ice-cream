#include <iostream>
#include "customer.h"

int main() {
    Customer cust("Bob", 9901050, "817-990-1050");

    if (cust.name() != "Bob") {
        std::cerr << "Bob test failed - expected Bob got: " << cust.name() << std::endl;
        return 1;
    }
    return 0;
}