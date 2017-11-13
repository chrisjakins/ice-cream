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

        /* FILE I/O */
        /* void load(std::istream); */
        /* void save(std::ostream&); */

        // OPERATOR OVERLOADING
        // Insertion operator
        friend std::ostream &operator<<(std::ostream& os, const Emporium& e)
        {
            // write out individual members of e
            os << e._id << std::endl;
            for (unsigned int i = 0; i < e._containers.size(); i++) {
                os << e._containers[i]->name() << ' ' << e._containers[i]->description() << ' '
                << e._containers[i]->wholesaleCost() << ' ' << e._containers[i]->retailCost() << ' '
                << e._containers[i]->stock() << ' ' << e._containers[i]->max() << ' ';
            }
            os << std::endl;
            for (unsigned int i = 0; i < e._scoops.size(); i++) {
                os << e._scoops[i]->name() << ' ' << ' ' << e._scoops[i]->description() << ' '
                << e._scoops[i]->wholesaleCost() << ' ' << e._scoops[i]->retailCost() << ' '
                << e._scoops[i]->stock() << ' ';
            }
            os << std::endl;
            for (unsigned int i = 0; i < e._toppings.size(); i++) {
                os << e._toppings[i]->name() << ' ' << ' ' << e._toppings[i]->description() << ' '
                << e._toppings[i]->wholesaleCost() << ' ' << e._toppings[i]->retailCost() << ' '
                << e._toppings[i]->stock() << ' ';
            }
            os << std::endl;
            for (unsigned int i = 0; i < e._customers.size(); i++) {
                os << e._customers[i]->name() << ' ' << ' ' << e._customers[i]->id() << ' '
                << e._customers[i]->phone() << ' ';
            }
            // os << std::endl;
            // for (unsigned int i = 0; i < e._servers.size(); i++) {
            //     os << e._servers[i]->name() << ' ' << ' ' << e.servers[i]->id() << ' '
            //     << e.servers[i]->phone() << ' ' << e.servers[i]->salary();
            // }
            return os;
        }

        // // Extraction operator
        // friend std::istream &operator>>(std::istream &is, Emporium &e)
        // {
        //     // write out individual members of e
        //     is >> e._id;
        //     for (unsigned int i = 0; i < e._containers.size(); i++) {
        //         is >> e._containers[i];
        //     }
        //     for (unsigned int i = 0; i < e._scoops.size(); i++) {
        //         is >> e._scoops[i];
        //     }
        //     for (unsigned int i = 0; i < e._toppings.size(); i++) {
        //         is >> e._toppings[i];
        //     }
        //     for (unsigned int i = 0; i < e._customers.size(); i++) {
        //         is >> e._customers[i];
        //     }
        //     for (unsigned int i = 0; i < e._servers.size(); i++) {
        //         is >> e._servers[i];
        //     }
        //     return is;
        // }

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

// std::ostream &operator<<(std::ostream &os, const Emporium &e)
// {
//     // write out individual members of e
//     os << e._id << std::endl;
//     // for (unsigned int i = 0; i < e._containers.size(); i++) {
//     //     os << e._containers[i];
//     // }
//     // os << std::endl;

//     // for (unsigned int i = 0; i < e._scoops.size(); i++)
//     // {
//     //     os << e._scoops[i];
//     // }
//     // os << std::endl;

//     // for (unsigned int i = 0; i < e._toppings.size(); i++)
//     // {
//     //     os << e._toppings[i];
//     // }
//     // os << std::endl;

//     // for (unsigned int i = 0; i < e._customers.size(); i++)
//     // {
//     //     os << e._customers[i];
//     // }
//     // os << std::endl;

//     // for (unsigned int i = 0; i < e._servers.size(); i++)
//     // {
//     //     os << e._servers[i];
//     // }
//     // os << std::endl;

//     // for (unsigned int i = 0; i < e._orders.size(); i++)
//     // {
//     //     os << e._orders[i];
//     // }
//     // os << std::endl;

//     return os;
// }


// std::istream &operator>>(std::istream &is, Emporium &e)
// {
//     // read in individual members of s
//     is >> e._id;
//     return is;
// }
