#ifndef _SERVER_H
#define _SERVER_H

#include <string>
#include "person.h"

class Server : public Person {
    public:
        Server(std::string, int, std::string, double);
        
        int numOrders();

        double salary();
        void setSalary(double);
        void setActive(bool);
        bool isActive();

    private:
        int _numOrders = 0;
        double _salary;
        bool _active = true;
};
#endif
