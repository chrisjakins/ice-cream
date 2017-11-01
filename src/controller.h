#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <string>
#include "emporium.h"

class Controller {
    public:
        Controller(Emporium&);

        const static int CREATE_ITEM = 1;
        const static int CREATE_SERVER = 2;
        const static int CREATE_CUSTOMER = 3;

        void execute(int);

    private:
        Emporium _emp;
};
#endif