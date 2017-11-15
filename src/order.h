#ifndef ORDER_H
#define ORDER_H

/* Container choice:
    Data removal:
        front/back/middle
    Data access:
        sequentially/random/key
*/
#include <vector>

#include "serving.h"
#include "customer.h"
#include "server.h"

class Order {
    public:
        Order(int, Customer, Server, std::vector<Serving *> &);

        /* how do these two work */
        void addServing(Serving *);
        void removeServing(int);

        double price();

        void updateState(const int);
        int id();

        /*** listing ***/
        std::string customer();
        std::string server();

        const static int UNFILLED = 0;
        const static int FILLED = 1;
        const static int CANCELLED = 2;
        const static int PAID = 3;

    private:
        const int _id;
        int _state = 0;
         
        Customer _customer;
        Server _server;
        std::vector<Serving *> _servings;
};
#endif
