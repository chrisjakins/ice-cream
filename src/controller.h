#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <string>
#include <vector>
#include "emporium.h"
#include "item.h"
#include <iostream>

class Controller {
    public:
        Controller(Emporium&);

        void execute(int);


        const static int CREATE_ITEM = 1;
        const static int CREATE_SERVER = 2;
        const static int CREATE_CUSTOMER = 3;
        const static int CREATE_EMPORIUM = 4;
        const static int CREATE_ORDER = 5;

        void errorMessage(std::string);
        void loadInventory();
        void save(std::ostream&);
        std::string getFilename();

        std::vector<mice::Container *> containers();
        std::vector<Scoop *> scoops();
        std::vector<Topping *> toppings();

    private:
        Emporium& _emp;
        std::string _filename = "untitled.ice";

        void createItem();
        void createServer();
        void createCustomer();
        void createOrder();
        void createEmporium();

        /* helpers */
        int itemType();
};
#endif
