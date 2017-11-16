#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <string>
#include <iostream>
#include <vector>

#include "emporium.h"
#include "serving.h"
#include "item.h"

class Controller {
    public:
        Controller(Emporium&);

        void execute(int);
        std::string stateMachine(int);

        void createServing(std::string, std::vector<std::string>, std::string);
        bool showServing(int);
        void deleteServing(int);
        void eraseServings();

        void completeOrder();

        void updateServerSalary();
        void updateItemStock();
        void updateItem();

        void createManager();

        const static int CREATE_ITEM = 1;
        const static int CREATE_SERVER = 2;
        const static int CREATE_CUSTOMER = 3;
        const static int CREATE_EMPORIUM = 4;
        const static int CREATE_ORDER = 5;

        const static int UNFILLED = 1;
        const static int CANCELLED = 2;
        const static int FILLED = 3;
        const static int PAID = 4;

        void errorMessage(std::string);
        void loadInventory();
        void save(std::ostream&);
        void load(std::istream&);
        void reportInventory();
        void reportCustomers();
        void reportServers();
        std::string getFilename();

        std::vector<mice::Container *> containers();
        std::vector<Scoop *> scoops();
        std::vector<Topping *> toppings();

    private:
        Emporium& _emp;
        std::string _filename = "untitled.ice";

        std::vector<Serving *> _servings;

        void createItem();
        void createServer();
        void createCustomer();
        void createOrder();
        void createEmporium();

        /* helpers */
        int itemType();
        Item * pickItem();
};
#endif
