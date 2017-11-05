#include <iostream> // debugging

#include "serving.h"

Serving::Serving(mice::Container container) : _container{container} {}
mice::Container Serving::container() { return _container; }
std::vector<Scoop> Serving::scoops() { return _scoops; }
std::vector<Topping> Serving::toppings() { return _toppings; }

void Serving::add_scoop(Scoop scoop) { _scoops.push_back(scoop); }
void Serving::add_topping(Topping topping) { _toppings.push_back(topping); }

double Serving::wholesaleCost()
{
    double total = _container.wholesaleCost();
    for (Scoop scoop : _scoops)
        total += scoop.wholesaleCost();
    for (Topping topping : _toppings)
        total += topping.wholesaleCost();
    return total;
}

double Serving::price()
{
    double total = _container.retailCost();
    for (Scoop scoop : _scoops)
        total += scoop.retailCost();
    for (Topping topping : _toppings)
        total += topping.retailCost();
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