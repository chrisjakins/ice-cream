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
        void save();
        void on_quit_click();       // Exit Ice Cream Application

        // Are NOT defined. Will need to
        // discuss implementation
        void createItem();          // Prompts dialog to create various items
        void createServer();        // Prompts dialog to create Server
        void createCustomer();      // Prompts dialog to create beloved Customer
        void createOrder();         // Prompts dialog to create Order
        void createManager();

        void on_about_click();
        void on_help_click();

        void onOwnerClick();
        void onMngrClick();
        void onServerClick();
        void onCustomerClick();

        void onSalaryClick();
        void onStockClick();
        void onItemPropClick();

        void loadInventory();

        void refresh();
        void onContainerClicked();
        void onScoopClicked(int);
        void onToppingClicked(int);

        void onConfirmClicked();
        void clearServPanel();

        void onServingClicked(int);
        void onCancelClicked();
        void onPayClicked();

        void onReportInventoryClicked();
        void onReportCustomersClicked();
        void onReportServersClicked();

    private:
        Controller& _controller;

        /* Main window box */
        Gtk::Box * mainBox;


        /*****************
             MENU BAR
        *****************/
        Gtk::MenuItem * mi_loadSample;
        Gtk::MenuItem * mi_save;
        Gtk::MenuItem * mi_quit;
        Gtk::MenuItem * mi_createServer;
        Gtk::MenuItem * mi_createManager;
        Gtk::MenuItem * up_salary;
        Gtk::MenuItem * mi_report_inventory;
        Gtk::MenuItem * mi_report_customers;
        Gtk::MenuItem * mi_report_servers;
        Gtk::MenuItem * up_itemStock;
        Gtk::MenuItem * up_itemProps;

        /****************
             TOOL BAR
        ****************/
        Gtk::ToolButton * cr_item;
        Gtk::ToolButton * cr_server;
        Gtk::ToolButton * cr_customer;
        Gtk::ToolButton * exit_button;

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

        Gtk::HBox * buttonBox;
        Gtk::Button * cancel;
        Gtk::Button * pay;


        /* helpers */
        void initMenubar();
        void initToolbar();
        void initMainscreen();

        int servingsInOrder = 0;
};
#endif 
