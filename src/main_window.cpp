#include "main_window.h"
#include "controller.h"

Main_window::Main_window(Emporium& emp) 
: _controller(emp)
{

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 400);
    
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

    //     CREATE
    // Create a 'Create' menu and add to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //         CREATE ITEM
    // Append Item to the Create menu
    Gtk::MenuItem *menuitem_createItem = Gtk::manage(new Gtk::MenuItem("_Item...", true));
    menuitem_createItem->signal_activate().connect(sigc::mem_fun(*this, &Main_window::createItem));
    createmenu->append(*menuitem_createItem);

    //         CREATE SERVER
    // Append Server to the Create menu
    Gtk::MenuItem *menuitem_createServer = Gtk::manage(new Gtk::MenuItem("_Server...", true));
    menuitem_createServer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::createServer));
    createmenu->append(*menuitem_createServer);

    //         CREATE CUSTOMER
    // Append Customer to the Create menu
    Gtk::MenuItem *menuitem_createCustomer = Gtk::manage(new Gtk::MenuItem("_Customer...", true));
    menuitem_createCustomer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::createCustomer));
    createmenu->append(*menuitem_createCustomer);

    //         CREATE ORDER
    // Append Order to the Create menu
    Gtk::MenuItem *menuitem_createOrder = Gtk::manage(new Gtk::MenuItem("_Order...", true));
    menuitem_createOrder->signal_activate().connect(sigc::mem_fun(*this, &Main_window::createOrder));
    createmenu->append(*menuitem_createOrder);

    //     HELP
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);
    //append about to help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem{"_About", true});
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);

    // /////////////
    // T O O L B A R    
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);
    //create item
    Gtk::ToolButton *create_item = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    create_item->set_tooltip_markup("Create Item");
    create_item->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createItem));
    toolbar->append(*create_item);
    //create server
    Gtk::Image *server_img = Gtk::manage(new Gtk::Image("img/server.png"));
    Gtk::ToolButton *create_server = Gtk::manage(new Gtk::ToolButton(*server_img));
    create_server->set_tooltip_markup("Create Server");
    create_server->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createServer));
    toolbar->append(*create_server);
    //create customer
    Gtk::Image *customer_img = Gtk::manage(new Gtk::Image("img/customer.png"));
    Gtk::ToolButton *create_customer = Gtk::manage(new Gtk::ToolButton(*customer_img));
    create_customer->set_tooltip_markup("Create Customer");
    create_customer->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createCustomer));
    toolbar->append(*create_customer);
    //create order
    Gtk::Image *order_img = Gtk::manage(new Gtk::Image("img/order.png"));
    Gtk::ToolButton *create_order = Gtk::manage(new Gtk::ToolButton(*order_img));
    create_order->set_tooltip_markup("Create Order");
    create_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createOrder));
    toolbar->append(*create_order);
    //help icon
/*    Gtk::ToolButton *help_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::HELP));
    help_button->set_tooltip_markup("Help");
    help_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_help_click));
    toolbar->append(*help_button);*/
    //exit button
    Gtk::ToolButton *exit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    exit_button->set_tooltip_markup("Exit");
    exit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    toolbar->append(*exit_button);
    vbox->show_all();
}

// /////////////////
// C A L L B A C K S
// /////////////////

// File Menu
void Main_window::on_quit_click() {
    hide();
}

// Create Menu
// Should figure out how to make numbers match the static variables in 
// controller.h
void Main_window::createServer() {
    _controller.execute(Controller::CREATE_SERVER);
}

void Main_window::createCustomer() {
    _controller.execute(Controller::CREATE_CUSTOMER);
}

void Main_window::createOrder() {}

void Main_window::createItem(){
    _controller.execute(Controller::CREATE_ITEM);
}

//help callback goes here
void Main_window::on_help_click(){
    
}
void Main_window::on_about_click(){
    Glib::ustring s = "<span size='24000' weight='bold'>Credits</span>\n<span size='large'>Server icon made by <b>Vectors Market</b> from www.flaticon.com\nCustomer icon,list icon made by <b>Freepik</b> from www.flaticon.com  </span>";
    Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.run();
}

Main_window::~Main_window() { }
