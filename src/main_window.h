#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>

class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();
    protected:
        void on_quit_click();       // Exit Ice Cream Application

        // Are NOT defined. Will need to
        // discuss implementation
        void createItem();          // Prompts dialog to create item
        void addServing();
        void addCustomer();
        void addOrder();
        
    private:
};
#endif 

