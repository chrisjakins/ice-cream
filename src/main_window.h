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
    private:
};
#endif 

