#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include <vector>

#include "controller.h"

class Main_window : public Gtk::Window
{
    public:
        Main_window(Controller&);
        virtual ~Main_window();

    protected:
        void on_quit_click();       // Exit Ice Cream Application

        // Are NOT defined. Will need to
        // discuss implementation
        void createItem();          // Prompts dialog to create various items
        void createServer();        // Prompts dialog to create Server
        void createCustomer();      // Prompts dialog to create beloved Customer
        void createOrder();         // Prompts dialog to create Order
        void on_about_click();
        void on_help_click();
        void loadInventory();

        void refresh();

    private:
        Controller& _controller;

        Gtk::Box * mainBox;

        Gtk::HBox * screenBox;
        Gtk::VBox * leftBox;
        Gtk::VBox * midBox;
        Gtk::VBox * rightBox;
        Gtk::VBox * contBox;
        Gtk::VBox * scoopBox;
        Gtk::VBox * toppBox;
        Gtk::HBox * contList;
        Gtk::HBox * scoopList;
        Gtk::HBox * toppList;

        Gtk::Label * cLabel;
        Gtk::Label * sLabel;
        Gtk::Label * tLabel;
        Gtk::Label * servLabel;
        Gtk::Label * orderLabel;

        std::vector<Gtk::RadioButton *> contRbs;
        Gtk::RadioButtonGroup group;
        std::vector<Gtk::Button *> flavButtons;
        std::vector<Gtk::Button *> topButtons;

        Gtk::Button * servConfirm;
        Gtk::Button * cancel;
        Gtk::Button * Pay;

        std::vector<Gtk::Button *> servings;

        /* helpers */
        void initMenubar();
        void initToolbar();
        void initMainscreen();
};
#endif 
