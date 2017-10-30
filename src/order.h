#ifndef ORDER_H
#define ORDER_H

#include <list>

#include "serving.h"
#include "customer.h"
#include "server.h"

class Order {
    public:
        Order(Customer, Server, int);

        /* how do these two work */
        void addServing(Serving *);
        void removeServing();

        double price();

        void updateState();

        const static int UNFILLED = 0;
        const static int FILLED = 1;
        const static int CANCELLED = 2;
        const static int PAID = 3;

    private:
        const int _id;
        int _state = 0;
         
        Customer _customer;
        Server _server;
        std::list<Serving *> _servings;
};
#endif
