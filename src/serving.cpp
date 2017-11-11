#include <iostream> // debugging
#include <vector>
#include <string>

#include "serving.h"
#include "container.h"
#include "topping.h"
#include "scoop.h"

Serving::Serving(mice::Container container) : _container{&container} {}
Serving::Serving() {  }
mice::Container Serving::container() { return *_container; }
std::vector<Scoop *> Serving::scoops() { return _scoops; }
Topping Serving::toppings() { return *_toppings; }

void Serving::add_scoop(Scoop scoop) { _scoops.push_back(&scoop); }

Serving * Serving::create(mice::Container * cont, std::vector<Scoop *> scoops,
                          Topping * topping) {

    Serving * serving = new Serving();
    serving->_container = cont;
    serving->_scoops = scoops;
    serving->_toppings = topping;
    return serving;
}


double Serving::wholesaleCost()
{
    double total = _container->wholesaleCost();
    for (Scoop * scoop : _scoops)
        total += scoop->wholesaleCost();
    total += _toppings->wholesaleCost();
    return total;
}

double Serving::price()
{
    double total = _container->retailCost();
    for (Scoop * scoop : _scoops)
        total += scoop->retailCost();
    total += _toppings->retailCost();
    return total;
}
// std::string Serving::preview(){
//     std::string selected="";
//     for(Item * i: _items){
//         selected += i->name() +" "+"("+i->description()+")"+"\t"+std::to_string(i->retailCost())+
//         "\n";
//     }
//     return selected;
// }   
