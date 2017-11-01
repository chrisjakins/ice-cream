#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <string>
#include "emporium.h"

class Controller {
    public:
        Controller(Emporium&);

    private:
        Emporium _emp;
};
#endif