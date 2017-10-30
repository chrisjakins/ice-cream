#ifndef ITEM_H
#define ITEM_H
//#include <gtkmm.h>
#include <string>

class Item {
    public:
        Item(std::string, std::string, double, double, int);//, Gtk::Image);
        /* constructor without image */
       // Item(std::string, std::string, double, double, int);

        virtual std::string type() = 0;

        /* stock operations */
        bool isInStock();
        void restock(int);
        void consume(int);

        /* Updating values */
        void changeRetailCost(double);
        void updateDescription(std::string);

        /* Getters */
        std::string getName();
        std::string getDescription();
        int getStock();
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
