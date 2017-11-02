#include <iostream>
#include <gtkmm.h>
#include "main_window.h"
#include "emporium.h"

int main(int argc, char *argv[]) {
    Glib::RefPtr<Gtk::Application> app = 
    Gtk::Application::create(argc, argv, "edu.uta.cse1325.ice-cream");
  
    Emporium emp(1, 10.9);
    Controller con{emp};
    Main_window win(con);
  
    // Set the window title
    win.set_title("Ice Cream");
  
    //Show the window and returns when it is closed or hidden
    return app->run(win);  
}
