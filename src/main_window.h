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
        void onContainerClicked();
        /* void onScoopClicked(Glib::ustring); */
        void onScoopClicked(int);
        void onToppingClicked(int);

    private:
        Controller& _controller;

        /* Main window box */
        Gtk::Box * mainBox;

        /* everything other than menubar and toolbar */
        Gtk::HBox * screenBox;

        /*****************
            ITEM PANEL
        *****************/
        Gtk::VBox * leftBox;

        Gtk::VBox * contBox;
        Gtk::VBox * scoopBox;
        Gtk::VBox * toppBox;

        Gtk::HBox * contList;
        Gtk::HBox * scoopList;
        Gtk::HBox * toppList;

        Gtk::Label * cLabel;
        Gtk::Label * sLabel;
        Gtk::Label * tLabel;

        std::vector<Gtk::RadioButton *> contRbs;
        Gtk::RadioButtonGroup group;
        std::vector<Gtk::Button *> scoopBs;
        std::vector<Gtk::Button *> topBs;

        /******************************
                 SERVING PANEL
        *******************************/
        Gtk::VBox * midBox;

        Gtk::Label * servLabel;

        /* Temporary till we get images set up */
        Gtk::Label * contServLabel;
        std::vector<Gtk::Label *> scoopServLabels;
        Gtk::Label * toppServLabel;
        /* end temporary stuff */

        Gtk::Button * servConfirm;

        /*************************
                ORDER PANEL
        *************************/
        Gtk::VBox * rightBox;

        Gtk::Label * orderLabel;

        std::vector<Gtk::Button *> servings;

        Gtk::Button * cancel;
        Gtk::Button * Pay;


        /* helpers */
        void initMenubar();
        void initToolbar();
        void initMainscreen();
};
#endif 
