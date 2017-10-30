#include <iostream>
#include "customer.h"

int main() {
    Customer cust("Bob", 9901050, "817-990-1050");

    if (cust.getName() != "Bob") {
        std::cerr << "Bob test failed - expected Bob got: " << cust.getName() << std::endl;
        return 1;
    }
    return 0;
}