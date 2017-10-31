#include "main_window.h"

Main_window::Main_window() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    
    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);

    //     MANAGER
    // Create a Manager menu and add to the menu bar
    Gtk::MenuItem *menuitem_manager = Gtk::manage(new Gtk::MenuItem("_Manager", true));
    menubar->append(*menuitem_manager);
    Gtk::Menu *managermenu = Gtk::manage(new Gtk::Menu());
    menuitem_manager->set_submenu(*managermenu);

    //         CREATE ITEM
    // Append Create Item to the Manager menu
    Gtk::MenuItem *menuitem_createItem = Gtk::manage(new Gtk::MenuItem("_Create Item", true));
    menuitem_createItem->signal_activate().connect(sigc::mem_fun(*this, &Main_window::createItem));
    managermenu->append(*menuitem_createItem);

    //     SERVER
    // Create a Server menu and add to the menu bar
    Gtk::MenuItem *menuitem_server = Gtk::manage(new Gtk::MenuItem("_Server", true));
    menubar->append(*menuitem_server);
    Gtk::Menu *servermenu = Gtk::manage(new Gtk::Menu());
    menuitem_server->set_submenu(*servermenu);

    //         ADD SERVING
    // Append Add Serving to the Server menu
    Gtk::MenuItem *menuitem_addServing = Gtk::manage(new Gtk::MenuItem("_Add Serving", true));
    menuitem_addServing->signal_activate().connect(sigc::mem_fun(*this, &Main_window::addServing));
    servermenu->append(*menuitem_addServing);

    //         ADD CUSTOMER
    // Append Add Customer to the Server menu
    Gtk::MenuItem *menuitem_addCustomer = Gtk::manage(new Gtk::MenuItem("_Add Customer", true));
    menuitem_addCustomer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::addCustomer));
    servermenu->append(*menuitem_addCustomer);

    //         ADD ORDER
    // Append Add Order to the Server menu
    Gtk::MenuItem *menuitem_addOrder = Gtk::manage(new Gtk::MenuItem("_Add Order", true));
    menuitem_addOrder->signal_activate().connect(sigc::mem_fun(*this, &Main_window::addOrder));
    servermenu->append(*menuitem_addOrder);

    //     CUSTOMER
    // Create a Customer menu and add to the menu bar
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menubar->append(*menuitem_customer);
    Gtk::Menu *customermenu = Gtk::manage(new Gtk::Menu());
    menuitem_customer->set_submenu(*customermenu);


    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);
    
    vbox->show_all();
}

// /////////////////
// C A L L B A C K S
// /////////////////

void Main_window::on_quit_click() {
    hide();
}

// Server Menu
void Main_window::addServing() {}
void Main_window::addCustomer() {}
void Main_window::addOrder() {}

// Manager menu
void Main_window::createItem(){}

Main_window::~Main_window() { }
