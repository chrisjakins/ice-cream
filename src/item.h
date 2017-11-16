#ifndef ITEM_H
#define ITEM_H
//#include <gtkmm.h>
#include <string>

class Item {
    public:
        /* without image for now */
        Item(std::string, std::string, double, double, int);//, Gtk::Image);

        virtual std::string type() = 0;

        /* stock operations */
        bool isInStock();
        void restock(int);
        void consume(int);

        /* Updating values */
        void changeRetail(double);
        void changeWholesale(double);
        void updateDescription(std::string);

        /* Getters */
        std::string name();
        std::string description();
        int stock();
        double wholesaleCost();
        double retailCost();

    protected:
        const std::string _name;
        std::string _description;
        double _wholesaleCost;
        double _retailCost;
        int _stockRemaining;
      //  Gtk::Image _image;
};
#endif
