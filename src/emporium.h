#ifndef EMPORIUM_H
#define EMPORIUM_H

#include <deque>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "server.h"
#include "customer.h"
#include "order.h"
#include "person.h"
#include "manager.h"

class Emporium {
    public:
        Emporium(int, double);

        Item * getItem(std::string);
        void updateItem(Item&, std::vector<std::string>);
        void addItem(int, std::vector<std::string>);
        void addItemStock(std::string, int);
        // void removeItem(int); // consider not having this removed = stock to 0
        std::vector<mice::Container *> containers();
        std::string listContainers();
        
        std::vector<Scoop *> scoops();
        std::string listScoops();

        std::vector<Topping *> toppings();
        std::string listToppings();

        void addServer(std::vector<std::string>);
        void changeServerSalary(int, double);
        std::vector<Server *> servers();
        std::string listServers();

        void addCustomer(std::vector<std::string>);
        std::string listCustomers();

        void addOrder(Order *);
        std::string listOrders();

        void addManager(std::vector<std::string>);

        /* FILE I/O */

        // OPERATOR OVERLOADING
        // Insertion operator
        friend std::ostream &operator<<(std::ostream& os, const Emporium& e);

        // Extraction operator
        friend std::istream &operator>>(std::istream &is, Emporium &e);

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
        std::vector<Manager *> _managers;       
        std::deque<Order *> _orders;
};
#endif
