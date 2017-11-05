#ifndef EMPORIUM_H
#define EMPORIUM_H

#include <deque>
#include <vector>
#include <string>

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "server.h"
#include "customer.h"
#include "order.h"
#include "person.h"

class Emporium {
    public:
        Emporium(int, double);

        void addItem(int, std::vector<std::string>);
        // void removeItem(int); // consider not having this removed = stock to 0
        std::vector<mice::Container *> containers();
        std::vector<Scoop *> scoops();
        std::vector<Topping *> toppings();

        void addServer(std::vector<std::string>);
        std::string listServers();

        void addCustomer(std::vector<std::string>);
        std::string listCustomers();

        void addOrder(Order *);
        std::string listOrders();

        /* FILE I/O */
        /* void load(std::istream); */
        /* void save(std::ostream); */

        void createContainer(std::vector<std::string>);
        void createFlavor(std::vector<std::string>);
        void createTopping(std::vector<std::string>);
        
    private:
        int _id;
        double _register = 0;
        std::vector<mice::Container *> _containers;
        std::vector<Scoop *> _scoops;
        std::vector<Topping *> _toppings;
        std::vector<Customer *> _customers;
        std::vector<Server *> _servers;       
        std::deque<Order *> _orders;

};
#endif
