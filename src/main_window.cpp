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

// File Menu
void Main_window::on_quit_click() {
    hide();
}

// Create Menu
void Main_window::createServer() {}
void Main_window::createCustomer() {}
void Main_window::createOrder() {}
void Main_window::createItem(){
    // TEMPORARY will refactor and add to controller
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Select Item Type");
    dialog->set_transient_for(*this);

    // Item Type
    Gtk::HBox b_type;
    
    Gtk::Label l_type{"Item Type:"};
    l_type.set_width_chars(15);
    b_type.pack_start(l_type, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_type;
    c_type.set_size_request(160);
    c_type.append("Container");
    c_type.append("Flavor");
    c_type.append("Topping");
    b_type.pack_start(c_type, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    // int result = dialog->run();
    dialog->run();

    dialog->close();
}

Main_window::~Main_window() { }
