#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "item.h"
#include "container.h"
#include "topping.h"
#include "scoop.h"
#include "serving.h"

int main() {
    std::list<Item *> items;
    Container cont{"Hat", "Hat bowl", 10.00, 15.00, 25, 1};
    items.push_back(&cont);
    Scoop scoop{"Vanilla", "Vanilla flavor", 5.00, 7.50, 25};
    items.push_back(&scoop);
    Topping topp{"M&M", "chocalate nutty stuff", 1.00, 3.50, 25, 2};
    items.push_back(&topp);

    Serving * serv = Serving::create(items);
    if (serv->numItems() != 3) {
        std::cerr << "Serving not created properly, or numItems() doesn't work\n"
                  << "expected: 3\nactual: " << serv->numItems() << std::endl;
    }

    if (serv->price() != 26.00) {
        std::cerr << "Serving not created properly, or price() doesn't work\n"
                  << "expected: 26.00\nactual: " << serv->price() << std::endl;
    }

    delete serv;
    return 0;
}
