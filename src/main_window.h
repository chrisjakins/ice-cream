#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "controller.h"
#include "emporium.h"

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

    private:
        Controller& _controller;
};
#endif 

