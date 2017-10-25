#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
    public:
        virtual Item() = 0;

        bool isInStock();
        void restock();

        void changeRetailCost(double);
        void updateDescription(std::string);

    protected:
        std::string _name;
        std::string _description;
        double _wholesaleCost;
        double _retailCost;
        int _stockRemaining;
        Gtk::Image _image;
};
#endif
