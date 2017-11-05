#include "main_window.h"

#include "controller.h"
#include "container.h"
#include "topping.h"
#include "scoop.h"

#include <iostream>
Main_window::Main_window(Controller& con) 
: _controller{con}
{
    // G U I   S E T U P
    set_default_size(1000, 600);
    
    // Put a vertical box container as the Window contents
    mainBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*mainBox);

    initMenubar();
    initToolbar();
    initMainscreen();

    mainBox->show_all();
}

// /////////////
// H E L P E R S
// /////////////

void Main_window::initMenubar() {
    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    mainBox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //         F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *mi_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*mi_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    mi_file->set_submenu(*filemenu);

    //         lOAD SAMPLES
    // Append Load Samples to the File menu
    Gtk::MenuItem *menuitem_loadSamples = Gtk::manage(new Gtk::MenuItem("_Load Inventory", true));
    menuitem_loadSamples->signal_activate().connect(sigc::mem_fun(*this, &Main_window::loadInventory));
    filemenu->append(*menuitem_loadSamples);
    
    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *mi_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    mi_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*mi_quit);

    //     HELP
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *mi_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*mi_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    mi_help->set_submenu(*helpmenu);
    //append about to help menu
    Gtk::MenuItem *mi_about = Gtk::manage(new Gtk::MenuItem{"_About", true});
    mi_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*mi_about);
}

void Main_window::initToolbar() {
    // /////////////
    // T O O L B A R    
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    mainBox->add(*toolbar);

    //create item
    Gtk::ToolButton *cr_item = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    cr_item->set_tooltip_markup("Create Item");
    cr_item->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createItem));
    toolbar->append(*cr_item);

    //create server
    Gtk::Image *server_img = Gtk::manage(new Gtk::Image("img/server.png"));
    Gtk::ToolButton *cr_server = Gtk::manage(new Gtk::ToolButton(*server_img));
    cr_server->set_tooltip_markup("Create Server");
    cr_server->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createServer));
    toolbar->append(*cr_server);

    //create customer
    Gtk::Image *customer_img = Gtk::manage(new Gtk::Image("img/customer.png"));
    Gtk::ToolButton *cr_customer = Gtk::manage(new Gtk::ToolButton(*customer_img));
    cr_customer->set_tooltip_markup("Create Customer");
    cr_customer->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createCustomer));
    toolbar->append(*cr_customer);

    //create order
    Gtk::Image *order_img = Gtk::manage(new Gtk::Image("img/order.png"));
    Gtk::ToolButton *cr_order = Gtk::manage(new Gtk::ToolButton(*order_img));
    cr_order->set_tooltip_markup("Create Order");
    cr_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createOrder));
    toolbar->append(*cr_order);
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
}

void Main_window::initMainscreen() {
    // left
    leftBox = Gtk::manage(new Gtk::VBox); 

    // container
    contBox = Gtk::manage(new Gtk::HBox);
    cLabel = Gtk::manage(new Gtk::Label{"Containers"});
    contBox->pack_start(*cLabel);


    // flavor
    scoopBox = Gtk::manage(new Gtk::HBox);
    sLabel = Gtk::manage(new Gtk::Label{"Flavors"});
    scoopBox->pack_start(*sLabel);

    // topping
    toppBox = Gtk::manage(new Gtk::HBox);
    tLabel = Gtk::manage(new Gtk::Label{"Toppings"});    
    toppBox->pack_start(*tLabel);

    leftBox->pack_start(*contBox);
    leftBox->pack_start(*scoopBox);
    leftBox->pack_start(*toppBox);

    // middle
    midBox = Gtk::manage(new Gtk::VBox);
    servLabel = Gtk::manage(new Gtk::Label{"Serving"});
    midBox->pack_start(*servLabel);

    // right
    rightBox = Gtk::manage(new Gtk::VBox);
    orderLabel = Gtk::manage(new Gtk::Label{"Order"});
    rightBox->pack_start(*orderLabel);

    mainBox->pack_start(*leftBox);
    mainBox->pack_start(*midBox);
    mainBox->pack_start(*rightBox);
    mainBox->show_all();
}

void Main_window::refresh() {
    initMainscreen();
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

void Main_window::createOrder() {
    refresh();
}

void Main_window::createItem(){
    _controller.execute(Controller::CREATE_ITEM);
    initMainscreen();
}

void Main_window::loadInventory() {
    _controller.loadInventory();
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
