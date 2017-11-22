#include "main_window.h"

#include "controller.h"
#include "container.h"
#include "topping.h"
#include "scoop.h"

#include <iostream>
#include <fstream>

Main_window::Main_window(Controller& con) 
: _controller{con}
{
    // G U I   S E T U P
    set_default_size(1200, 800);
    
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
    Gtk::MenuItem * mi_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*mi_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    mi_file->set_submenu(*filemenu);

    //         lOAD SAMPLES
    // Append Load Samples to the File menu
    mi_loadSample = Gtk::manage(new Gtk::MenuItem("_Load Inventory", true));
    mi_loadSample->signal_activate().connect(sigc::mem_fun(*this, &Main_window::loadInventory));
    filemenu->append(*mi_loadSample);
    
    //         SAVE
    // Append SAVE to the File menu
    mi_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    mi_save->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onSaveClicked));
    filemenu->append(*mi_save);

    //         LOAD
    // Append LOAD to the File menu
    mi_load = Gtk::manage(new Gtk::MenuItem("_Load", true));
    mi_load->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onLoadClicked));
    filemenu->append(*mi_load);

    //         Q U I T
    // Append Quit to the File menu
    mi_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    mi_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*mi_quit);

    //         V I E W
    // Menu Item for all reporting functionality
    Gtk::MenuItem *mi_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*mi_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    mi_view->set_submenu(*viewmenu);

    //        REPORT INVENTORY
    // Provides Inventory Report for Manager
    mi_report_inventory = Gtk::manage(new Gtk::MenuItem("_Create Inventory Report", true));
    mi_report_inventory->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onReportInventoryClicked));
    viewmenu->append(*mi_report_inventory);

    //        REPORT CUSTOMER
    // Provides Inventory Report for Manager
    mi_report_customers = Gtk::manage(new Gtk::MenuItem("_Create Customer Report", true));
    mi_report_customers->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onReportCustomersClicked));
    viewmenu->append(*mi_report_customers);

    //        REPORT SERVER
    // Provides Inventory Report for Manager
    mi_report_servers = Gtk::manage(new Gtk::MenuItem("_Create Server Report", true));
    mi_report_servers->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onReportServersClicked));
    viewmenu->append(*mi_report_servers);

    //          C R E A T E
    // Allow user to create one of many things
    Gtk::MenuItem *mi_create = Gtk::manage(new Gtk::MenuItem("Create", true));
    menubar->append(*mi_create);
    Gtk::Menu * createMenu = Gtk::manage(new Gtk::Menu());
    mi_create->set_submenu(*createMenu);

    //  Server
    mi_createServer = Gtk::manage(new Gtk::MenuItem("Server", true));
    mi_createServer->signal_activate().connect(sigc::mem_fun(*this,&Main_window::createServer));
    createMenu->append(*mi_createServer);

    //  Manager
    mi_createManager = Gtk::manage(new Gtk::MenuItem("Manager", true));
    mi_createManager->signal_activate().connect(sigc::mem_fun(*this,&Main_window::createManager));
    createMenu->append(*mi_createManager);

    // Emporium
    mi_createEmp = Gtk::manage(new Gtk::MenuItem("Emporium", true));
    mi_createEmp->signal_activate().connect(sigc::mem_fun(*this, &Main_window::createEmp));
    createMenu->append(*mi_createEmp);

    //      U P D A T E
    // Allow user to update anything in emporium
    Gtk::MenuItem * mi_update = Gtk::manage(new Gtk::MenuItem("Update", true));
    menubar->append(*mi_update);
    Gtk::Menu * updateMenu = Gtk::manage(new Gtk::Menu());
    mi_update->set_submenu(*updateMenu);

    //      Server Salary
    up_salary = Gtk::manage(new Gtk::MenuItem("Server Salary", true));
    up_salary->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onSalaryClick));
    updateMenu->append(*up_salary);

    //      Item
    up_itemProps = Gtk::manage(new Gtk::MenuItem("Item Property", true));
    up_itemProps->signal_activate().connect(sigc::mem_fun(*this,&Main_window::onItemPropClick));
    updateMenu->append(*up_itemProps);

    //      Item Stock
    up_itemStock = Gtk::manage(new Gtk::MenuItem("Item Stock", true));
    up_itemStock->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onStockClick));
    updateMenu->append(*up_itemStock);

    //         R O L E S
    // Allow user to change permissions
    Gtk::MenuItem * mi_role = Gtk::manage(new Gtk::MenuItem("_Roles", true));
    menubar->append(*mi_role);
    Gtk::Menu * roleMenu = Gtk::manage(new Gtk::Menu());
    mi_role->set_submenu(*roleMenu);

    //         OWNER
    Gtk::MenuItem * mi_owner = Gtk::manage(new Gtk::MenuItem("Owner", true));
    mi_owner->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onOwnerClick));
    roleMenu->append(*mi_owner);

    //        MANAGER
    Gtk::MenuItem * mi_mngr = Gtk::manage(new Gtk::MenuItem("Manager", true));
    mi_mngr->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onMngrClick));
    roleMenu->append(*mi_mngr);

    //        SERVER
    Gtk::MenuItem * mi_server = Gtk::manage(new Gtk::MenuItem("Server", true));
    mi_server->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onServerClick));
    roleMenu->append(*mi_server);

    //       CUSTOMER
    Gtk::MenuItem * mi_customer = Gtk::manage(new Gtk::MenuItem("Customer", true));
    mi_customer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::onCustomerClick));
    roleMenu->append(*mi_customer);


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
    cr_item = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    cr_item->set_tooltip_markup("Create Item");
    cr_item->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createItem));
    toolbar->append(*cr_item);

    //create server
    Gtk::Image *server_img = Gtk::manage(new Gtk::Image("img/server.png"));
    cr_server = Gtk::manage(new Gtk::ToolButton(*server_img));
    cr_server->set_tooltip_markup("Create Server");
    cr_server->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createServer));
    toolbar->append(*cr_server);

    //create customer
    Gtk::Image *customer_img = Gtk::manage(new Gtk::Image("img/customer.png"));
    cr_customer = Gtk::manage(new Gtk::ToolButton(*customer_img));
    cr_customer->set_tooltip_markup("Create Customer");
    cr_customer->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::createCustomer));
    toolbar->append(*cr_customer);

    //help icon
/*    Gtk::ToolButton *help_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::HELP));
    help_button->set_tooltip_markup("Help");
    help_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_help_click));
    toolbar->append(*help_button);*/

    //exit button
    exit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    exit_button->set_tooltip_markup("Exit");
    exit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    toolbar->append(*exit_button);
}

void Main_window::initMainscreen() {
    screenBox = Gtk::manage(new Gtk::HBox);
    // left
    leftBox = Gtk::manage(new Gtk::VBox); 

    // container
    contBox = Gtk::manage(new Gtk::VBox);
    cLabel = Gtk::manage(new Gtk::Label{"Containers"});
    contList = Gtk::manage(new Gtk::HBox);
    contBox->pack_start(*cLabel, Gtk::PACK_SHRINK);
    contBox->pack_start(*contList);
    Gtk::RadioButtonGroup group();

    // flavor
    scoopBox = Gtk::manage(new Gtk::VBox);
    sLabel = Gtk::manage(new Gtk::Label{"Flavors"});
    scoopList = Gtk::manage(new Gtk::HBox);
    scoopBox->pack_start(*sLabel);
    scoopBox->pack_start(*scoopList);

    // topping
    toppBox = Gtk::manage(new Gtk::VBox);
    tLabel = Gtk::manage(new Gtk::Label{"Toppings"});    
    toppList = Gtk::manage(new Gtk::HBox);
    toppBox->pack_start(*tLabel);
    toppBox->pack_start(*toppList);

    Gtk::SeparatorToolItem *hSep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    Gtk::SeparatorToolItem *hSep2 = Gtk::manage(new Gtk::SeparatorToolItem());

    leftBox->pack_start(*contBox); //, Gtk::PACK_SHRINK);
    leftBox->pack_start(*hSep1, Gtk::PACK_SHRINK, 5);    
    leftBox->pack_start(*scoopBox);
    leftBox->pack_start(*hSep2, Gtk::PACK_SHRINK, 5);
    leftBox->pack_start(*toppBox);

    // middle
    midBox = Gtk::manage(new Gtk::VBox);
    servLabel = Gtk::manage(new Gtk::Label{"Serving"});
    contServLabel = Gtk::manage(new Gtk::Label);
    toppServLabel = Gtk::manage(new Gtk::Label);
    servConfirm = Gtk::manage(new Gtk::Button{"Confirm"});
    servConfirm->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::onConfirmClicked));

    midBox->pack_start(*servLabel, Gtk::PACK_SHRINK);
    midBox->pack_start(*contServLabel, Gtk::PACK_SHRINK);
    midBox->pack_end(*servConfirm, Gtk::PACK_SHRINK);
    midBox->pack_end(*toppServLabel);

    // right
    rightBox = Gtk::manage(new Gtk::VBox);
    orderLabel = Gtk::manage(new Gtk::Label{"Order"});
    buttonBox = Gtk::manage(new Gtk::HBox);
    cancel = Gtk::manage(new Gtk::Button{"Cancel"});
    cancel->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::onCancelClicked));
    pay = Gtk::manage(new Gtk::Button{"Finish"});
    pay->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::onPayClicked));

    rightBox->pack_start(*orderLabel, Gtk::PACK_SHRINK);

    Gtk::SeparatorToolItem *bSep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    buttonBox->pack_start(*cancel);
    buttonBox->pack_start(*pay);
    rightBox->pack_end(*bSep1, Gtk::PACK_SHRINK);
    rightBox->pack_end(*buttonBox, Gtk::PACK_SHRINK);

    Gtk::SeparatorToolItem *vSep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    Gtk::SeparatorToolItem *vSep2 = Gtk::manage(new Gtk::SeparatorToolItem());
    
    screenBox->pack_start(*leftBox);
    screenBox->pack_start(*vSep1, Gtk::PACK_SHRINK, 5);
    screenBox->pack_start(*midBox);
    screenBox->pack_start(*vSep2, Gtk::PACK_SHRINK, 5);
    screenBox->pack_start(*rightBox);
    mainBox->pack_start(*screenBox);
}

void Main_window::refresh() {
    unsigned int i;
    std::vector<mice::Container *> conts = _controller.containers();
    if (!conts.empty() && conts.size() != contRbs.size()) {
        if (contRbs.empty()) {
            for (i = 0; i < conts.size(); i++) {
                contRbs.push_back(Gtk::manage(new Gtk::RadioButton{conts[i]->name()}));
                contRbs[i]->set_image(*conts[i]->img());
                contRbs[i]->set_always_show_image(true);
                contRbs[i]->signal_clicked().connect(sigc::mem_fun(
                    *this, &Main_window::onContainerClicked));
                contList->pack_start(*contRbs[i]);
                contRbs[i]->set_group(group);
            }
        } else {
            i = conts.size() - 1;
            contRbs.push_back(Gtk::manage(new Gtk::RadioButton{conts[i]->name()}));
            contRbs[i]->set_image(*conts[i]->img());
            contRbs[i]->set_always_show_image(true);
            contRbs[i]->signal_clicked().connect(sigc::mem_fun(
                *this, &Main_window::onContainerClicked));
            contList->pack_start(*contRbs[i]);
            contRbs[i]->set_group(group);
        }
    }

    std::vector<Scoop *> scoops = _controller.scoops();
   
    if (!scoops.empty() && scoops.size() != scoopBs.size()) {
        if (scoopBs.empty()) {
            for (i = 0; i < scoops.size(); i++) {
                scoopBs.push_back(Gtk::manage(new Gtk::Button{scoops[i]->name()}));
                scoopBs[i]->set_image(*scoops[i]->img());
                scoopBs[i]->set_always_show_image(true);
                scoopBs[i]->signal_clicked().connect(sigc::bind<int>(
                    sigc::mem_fun(*this, &Main_window::onScoopClicked), i));
                scoopList->pack_start(*scoopBs[i]);
            }
        } else {
            i = scoops.size() - 1;
            scoopBs.push_back(Gtk::manage(new Gtk::Button{scoops[i]->name()}));
            scoopBs[i]->set_image(*scoops[i]->img());
            scoopBs[i]->set_always_show_image(true);
            scoopBs[i]->signal_clicked().connect(sigc::bind<int>(
                sigc::mem_fun(*this, &Main_window::onScoopClicked), i));
            scoopList->pack_start(*scoopBs[i]);
        }
    }

    std::vector<Topping *> topps = _controller.toppings();
    if (!topps.empty() && topps.size() != topBs.size()) {
        if (topBs.empty()) {
            for (i = 0; i < topps.size(); i++) {
                topBs.push_back(Gtk::manage(new Gtk::Button{topps[i]->name()}));
                topBs[i]->set_image(*topps[i]->img());
                topBs[i]->set_always_show_image(true);
                topBs[i]->signal_clicked().connect(sigc::bind<int>(
                    sigc::mem_fun(*this, &Main_window::onToppingClicked), i));
                toppList->pack_start(*topBs[i]);
            }
        } else {
            i = topps.size() - 1;
            topBs.push_back(Gtk::manage(new Gtk::Button{topps[i]->name()}));
            topBs[i]->set_image(*topps[i]->img());
            topBs[i]->set_always_show_image(true);
            topBs[i]->signal_clicked().connect(sigc::bind<int>(
                sigc::mem_fun(*this, &Main_window::onToppingClicked), i));
            toppList->pack_start(*topBs[i]);
        }
    }

    mainBox->show_all();
}

void Main_window::clearServPanel() {
    for (unsigned int i = 0; i < contRbs.size(); i++) {
        if (contRbs[i]->get_active()) {
            contServLabel->set_label(contRbs[i]->get_label());
        }
    }

    for (unsigned int i = 0; i < scoopServLabels.size(); i++) {
        delete scoopServLabels[i];
    }

    scoopServLabels.clear();
    toppServLabel->set_label("");
} 

// /////////////////
// C A L L B A C K S
// /////////////////

// File Menu
void Main_window::on_quit_click() {
    close();
}

// Create Menu
// Should figure out how to make numbers match the static variables in 
// controller.h
void Main_window::createServer() {
    _controller.execute(Controller::CREATE_SERVER);
}

void Main_window::createManager() {
    _controller.createManager();
}

void Main_window::createEmp() {
    _controller.execute(Controller::CREATE_EMPORIUM);
}

void Main_window::createCustomer() {
    _controller.execute(Controller::CREATE_CUSTOMER);
}

void Main_window::createOrder() {
    refresh();
}

void Main_window::createItem(){
    _controller.execute(Controller::CREATE_ITEM);
    refresh();
}

void Main_window::loadInventory() {
    _controller.loadInventory();
    refresh();
}

void Main_window::onSalaryClick() {
    _controller.updateServerSalary();
}

void Main_window::onStockClick() {
    _controller.updateItemStock();
}

void Main_window::onItemPropClick() {
    _controller.updateItem();
    for (unsigned int i = 0; i < contRbs.size(); i++) {
        if (contRbs[i]->get_label() != _controller.containers()[i]->name()) {
            contRbs[i]->set_label(_controller.containers()[i]->name());
        }
    }

    for (unsigned int i = 0; i < scoopBs.size(); i++) {
        if (scoopBs[i]->get_label() != _controller.scoops()[i]->name()) {
            scoopBs[i]->set_label(_controller.scoops()[i]->name());
        }
    }

    for (unsigned int i = 0; i < topBs.size(); i++) {
        if (topBs[i]->get_label() != _controller.toppings()[i]->name()) {
            topBs[i]->set_label(_controller.toppings()[i]->name());
        }
    }
}

void Main_window::onContainerClicked() {
    int active;
    for (unsigned int i = 0; i < contRbs.size(); i++) {
        if (contRbs[i]->get_active()) active = i;
    }
    contServLabel->set_label(contRbs[active]->get_label());
}

void Main_window::onScoopClicked(int index) {
    scoopServLabels.push_back(Gtk::manage(new Gtk::Label{scoopBs[index]->get_label()}));
    midBox->pack_start(*scoopServLabels[scoopServLabels.size() - 1], Gtk::PACK_SHRINK);
    mainBox->show_all();
}

void Main_window::onToppingClicked(int index) {
    toppServLabel->set_label(topBs[index]->get_label());
    mainBox->show_all();
}

void Main_window::onConfirmClicked() {

    std::vector<std::string> scoopStrings;
    for (unsigned int i = 0; i < scoopServLabels.size(); i++) {
        scoopStrings.push_back(scoopServLabels[i]->get_label());
    }

    _controller.createServing(contServLabel->get_label(),
                              scoopStrings, toppServLabel->get_label());

    servingButtons.push_back(Gtk::manage(new Gtk::Button{std::to_string(servingsInOrder)}));

    servingButtons[servingsInOrder]->signal_clicked().connect(sigc::bind<int>(
        sigc::mem_fun(*this, &Main_window::onServingClicked),
        std::stoi(servingButtons[servingsInOrder]->get_label())));

    clearServPanel();

    rightBox->pack_start(*servingButtons[servingsInOrder]);
    servingsInOrder++;
    mainBox->show_all();
}

void Main_window::onServingClicked(int servingNumber) {
    if(!_controller.showServing(servingNumber)) {
        // if serving was deleted in pop-up
        servingsInOrder--;
        Gtk::Button * butt = servingButtons[servingNumber];
        servingButtons.erase(servingButtons.begin() + servingNumber);
        
        _controller.deleteServing(servingNumber);
        delete butt;
        
        // reset other servings in list
        std::vector<Gtk::Button *> newServings;
        if (servingsInOrder >= 0) {
            for (unsigned int i = 0; i < servingButtons.size(); i++) {
                delete servingButtons[i];

                newServings.push_back(Gtk::manage(new Gtk::Button));
                newServings[i]->set_label(std::to_string(i));
                newServings[i]->signal_clicked().connect(sigc::bind<int>(
                    sigc::mem_fun(*this, &Main_window::onServingClicked), i));

                rightBox->pack_start(*newServings[i]);
            }
            servingButtons.clear();
            servingButtons = std::move(newServings);
        }
        mainBox->show_all();
    }
}

void Main_window::onCancelClicked() {
    _controller.eraseServings();
    servingsInOrder = 0;
    for (int i = servingButtons.size() - 1; i >= 0; i--) {
        delete servingButtons[i];
    }
    servingButtons.clear();
    mainBox->show_all();
}

void Main_window::onPayClicked() {
    _controller.completeOrder();
    onCancelClicked();
}

void Main_window::onSaveClicked() {
    _controller.save();
}

void Main_window::onLoadClicked() {
    //std::ifstream is(_controller.getFilename());
    _controller.load();
    refresh();
}

void Main_window::onReportInventoryClicked() {
    _controller.reportInventory();
}

void Main_window::onReportCustomersClicked() {
    _controller.reportCustomers();
}

void Main_window::onReportServersClicked() {
    _controller.reportServers();
}

void Main_window::onOwnerClick() {
    mi_loadSample->set_sensitive(true); 
    mi_save->set_sensitive(true);
    mi_quit->set_sensitive(true);
    mi_report_inventory->set_sensitive(true);
    mi_report_customers->set_sensitive(true);
    mi_report_servers->set_sensitive(true);
    mi_createServer->set_sensitive(true);
    mi_createManager->set_sensitive(true);
    cr_item->set_sensitive(true);
    cr_server->set_sensitive(true);
    cr_customer->set_sensitive(true);
    up_salary->set_sensitive(true);
    up_itemStock->set_sensitive(true);
    up_itemProps->set_sensitive(true);
    exit_button->set_sensitive(true);
}

void Main_window::onMngrClick() {
    mi_loadSample->set_sensitive(true); 
    mi_save->set_sensitive(true);
    mi_quit->set_sensitive(true);
    mi_report_inventory->set_sensitive(true);
    mi_report_customers->set_sensitive(true);
    mi_report_servers->set_sensitive(true);
    mi_createServer->set_sensitive(true);
    mi_createManager->set_sensitive(false);
    cr_item->set_sensitive(true);
    cr_server->set_sensitive(true);
    cr_customer->set_sensitive(true);
    up_salary->set_sensitive(true);
    up_itemStock->set_sensitive(true);
    up_itemProps->set_sensitive(true);
    exit_button->set_sensitive(true);
}

void Main_window::onServerClick() {
    mi_loadSample->set_sensitive(false); 
    mi_save->set_sensitive(true);
    mi_quit->set_sensitive(true);
    mi_report_inventory->set_sensitive(false);
    mi_report_customers->set_sensitive(false);
    mi_report_servers->set_sensitive(false);
    mi_createServer->set_sensitive(false);
    mi_createManager->set_sensitive(false);
    cr_item->set_sensitive(false);
    cr_server->set_sensitive(false);
    cr_customer->set_sensitive(true);
    up_salary->set_sensitive(false);
    up_itemStock->set_sensitive(true);
    up_itemProps->set_sensitive(false);
    exit_button->set_sensitive(true);
}

void Main_window::onCustomerClick() {
    mi_loadSample->set_sensitive(false); 
    mi_save->set_sensitive(false);
    mi_quit->set_sensitive(false);
    mi_report_inventory->set_sensitive(false);
    mi_report_customers->set_sensitive(false);
    mi_report_servers->set_sensitive(false);
    mi_createServer->set_sensitive(false);
    mi_createManager->set_sensitive(false);
    cr_item->set_sensitive(false);
    cr_server->set_sensitive(false);
    cr_customer->set_sensitive(false);
    up_salary->set_sensitive(false);
    up_itemStock->set_sensitive(false);
    up_itemProps->set_sensitive(false);
    exit_button->set_sensitive(false);
}

void Main_window::on_help_click(){
    
}

void Main_window::on_about_click(){
    Glib::ustring s = "<span size='24000' weight='bold'>Credits</span>\n<span size='large'>Server icon made by <b>Vectors Market</b> from www.flaticon.com\nCustomer icon,list icon made by <b>Freepik</b> from www.flaticon.com  </span>";
    Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.run();
}

Main_window::~Main_window() { }
