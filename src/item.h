#ifndef ITEM_H
#define ITEM_H
//#include <gtkmm.h>
#include <string>
// #include <gtkmm.h>

class Item {
    public:
        Item(std::string, std::string, double, double, int);//, Gtk::Image);
        
        /* constructor without image */
       // Item(std::string, std::string, double, double, int);

        bool isInStock();
        void restock(int);
        int getStock();

        void changeRetailCost(double);
        void updateDescription(std::string);
        std::string getName();
        
        double getWholesaleCost();
        double getRetailCost();

    protected:
        std::string _name;
        std::string _description;
        double _wholesaleCost;
        double _retailCost;
        int _stockRemaining;
      //  Gtk::Image _image;
};
#endif
