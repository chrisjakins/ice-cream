#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <string>
#include "emporium.h"

class Controller {
    public:
        Controller(Emporium&);

        void execute(int);


        const static int CREATE_ITEM = 1;
        const static int CREATE_SERVER = 2;
        const static int CREATE_CUSTOMER = 3;
        const static int CREATE_EMPORIUM = 4;
        const static int CREATE_SERVING = 5;

        void error(std::string);

    private:
        Emporium& _emp;

        /* helpers */
        int itemType();

        void createItem();
        void createServer();
        void createCustomer();
        void createEmporium();
        void createServing();
};
#endif
