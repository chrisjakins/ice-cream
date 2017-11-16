#ifndef ITEM_H
#define ITEM_H
#include <gtkmm.h>
#include <string>

class Item {
    public:
        Item(std::string, std::string, double, double, int,std::string);//, Gtk::Image);
        /* constructor without image */
       // Item(std::string, std::string, double, double, int);

        virtual std::string type() = 0;


        std::string name();
        void updateName(std::string);

        std::string description();
        void updateDescription(std::string);

        int stock();
        bool isInStock();
        void restock(int);
        void consume(int);

        double wholesaleCost();
        void updateWholesaleCost(double);

        double retailCost();
        void updateRetailCost(double);

        Gtk::Image * img();
        Gtk::Image updateImg();

    protected:
        std::string _name;
        std::string _description;
        double _wholesaleCost;
        double _retailCost;
        int _stockRemaining;
        Gtk::Image * _image;
};
#endif
