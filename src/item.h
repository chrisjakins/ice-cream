#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <gtkmm.h>

class Item {
    public:
        Item();

        bool isInStock();
        void restock(int);

        void changeRetailCost(double);
        void updateDescription(std::string);
        
        std::string getName();
        double getWholesaleCost();
        double getRetailCost();
        int getStock();

    protected:
        std::string _name;
        std::string _description;
        double _wholesaleCost;
        double _retailCost;
        int _stockRemaining;
        Gtk::Image _image;
};
#endif
