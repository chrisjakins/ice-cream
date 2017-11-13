#include <gtkmm.h>

#include "controller.h"
#include "serving.h"
#include "item.h"
#include "container.h"
#include "topping.h"
#include "scoop.h"

Controller::Controller(Emporium& emp)
: _emp{emp}
{ }

void Controller::execute(int cmd) {
    switch (cmd) {
        case CREATE_ITEM: createItem(); break;
        case CREATE_SERVER: createServer(); break;
        case CREATE_CUSTOMER: createCustomer(); break;
        case CREATE_EMPORIUM: createEmporium(); break;
        default: errorMessage("Invalid input!"); break;
    }
}

void Controller::createServing(std::string contString, std::vector<std::string> scoopStrings,
                               std::string toppingString) {

    mice::Container * container;
    std::vector<Scoop *> scoops;
    Topping * topping;

    for (unsigned int i = 0; i < _emp.containers().size(); i++) {
        if (contString == _emp.containers()[i]->name()) {
            container = _emp.containers()[i];
        }
    }

    for (unsigned int i = 0; i < _emp.toppings().size(); i++) {
        if (toppingString == _emp.toppings()[i]->name()) {
            topping = _emp.toppings()[i];
        }
    }

    for (unsigned int i = 0; i < scoopStrings.size(); i++) {
        for (unsigned int j = 0; j < _emp.scoops().size(); j++) {
            if (scoopStrings[i] == _emp.scoops()[j]->name()) {
                scoops.push_back(_emp.scoops()[j]);
            }
        }
    }

    _servings.push_back(Serving::create(container, scoops, topping));
}

bool Controller::showServing(int i) {
    Gtk::Dialog * dialog = new Gtk::Dialog();
    dialog->set_title("Serving");

    Gtk::Label contLabel{"Container "};
    dialog->get_vbox()->pack_start(contLabel, Gtk::PACK_SHRINK);
    Gtk::Label container{_servings[i]->container().name()};
    dialog->get_vbox()->pack_start(container, Gtk::PACK_SHRINK);


    Gtk::Label scoopLabel{"Scoops"};
    dialog->get_vbox()->pack_start(scoopLabel, Gtk::PACK_SHRINK);
    std::vector<Gtk::Label *> scoopsVec;
    for (unsigned int j = 0; j < _servings[i]->scoops().size(); j++) {
        Gtk::Label * temp = Gtk::manage(new Gtk::Label{_servings[i]->scoops()[j]->name()});
        scoopsVec.push_back(temp);
        dialog->get_vbox()->pack_start(*temp, Gtk::PACK_SHRINK);
    }

    Gtk::Label topLabel{"Toppings"};
    dialog->get_vbox()->pack_start(topLabel, Gtk::PACK_SHRINK);
    Gtk::Label topping{_servings[i]->toppings().name()};
    dialog->get_vbox()->pack_start(topping, Gtk::PACK_SHRINK);


    dialog->add_button("Delete Serving", 0);
    dialog->add_button("Close", 1);
    dialog->show_all();
    int result = dialog->run(); dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
    delete dialog;
    return result == 1;
}

void Controller::deleteServing(int index) {
    Serving * serv = _servings[index];
    _servings.erase(_servings.begin() + index);
    delete serv;
}

void Controller::updateServerSalary() {
    Gtk::Dialog * dialog = new Gtk::Dialog();

    Gtk::Label * label1 = Gtk::manage(new Gtk::Label("Server"));
    Gtk::ComboBoxText dropDown;
    dropDown.set_size_request(160);
    for (unsigned int i = 0; i < _emp.servers().size(); i++) {
        dropDown.append(_emp.servers()[i]->name());
    }
    dialog->get_vbox()->pack_start(*label1, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(dropDown, Gtk::PACK_SHRINK);

    Gtk::Label * label2 = Gtk::manage(new Gtk::Label("New Salary"));
    Gtk::Entry * entry = Gtk::manage(new Gtk::Entry());

    dialog->get_vbox()->pack_start(*label2, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*entry, Gtk::PACK_SHRINK);

    dialog->add_button("Cancel", 0);
    dialog->add_button("Ok", 1);

    dialog->show_all();
    if (dialog->run()) {
        _emp.changeServerSalary(dropDown.get_active_row_number(),
                                std::stod(entry->get_text()));
    }
    dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
    delete dialog;
}

void Controller::updateItemStock() {
    Gtk::Dialog * dialog = new Gtk::Dialog();

    Gtk::Label * label1 = Gtk::manage(new Gtk::Label("Item"));
    Gtk::ComboBoxText dropDown;
    dropDown.set_size_request(160);
    for (unsigned int i = 0; i < _emp.containers().size(); i++) {
        dropDown.append(_emp.containers()[i]->name());
    }
    for (unsigned int i = 0; i < _emp.scoops().size(); i++) {
        dropDown.append(_emp.scoops()[i]->name());
    }
    for (unsigned int i = 0; i < _emp.toppings().size(); i++) {
        dropDown.append(_emp.toppings()[i]->name());
    }
    dialog->get_vbox()->pack_start(*label1, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(dropDown, Gtk::PACK_SHRINK);

    Gtk::Label * label2 = Gtk::manage(new Gtk::Label("Stock Added"));
    Gtk::Entry * entry = Gtk::manage(new Gtk::Entry());

    dialog->get_vbox()->pack_start(*label2, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*entry, Gtk::PACK_SHRINK);

    dialog->add_button("Cancel", 0);
    dialog->add_button("Ok", 1);

    dialog->show_all();
    if (dialog->run()) {
        _emp.addItemStock(dropDown.get_active_text(), std::stoi(entry->get_text()));
    }
    dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
    delete dialog;
}

int Controller::itemType() {
    int item;
    Gtk::Dialog * dialog = new Gtk::Dialog();
    dialog->set_title("Select Item Type");

    Gtk::HBox box;
    Gtk::Label label{"Item Type"};
    label.set_width_chars(15);
    box.pack_start(label, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText dropDown;
    dropDown.set_size_request(160);
    dropDown.append("Container");
    dropDown.append("Flavor");
    dropDown.append("Topping");
    dropDown.set_active(0);
    box.pack_start(dropDown, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(box, Gtk::PACK_SHRINK);

    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    if (dialog->run()) {
        item = dropDown.get_active_row_number();
    } else {
        dialog->close();
        delete dialog;
        return -1;
    }

    dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
    delete dialog;
    return item;
} 

void Controller::createItem() {
    std::vector<std::string> textL{"Name", "Description", "Cost",
                                   "Price", "Stock", "Image"};
    std::vector<std::string> outputs;

    // dialog->set_transient_for(*this);

    int item = itemType();
    if (item < 0) return;

    Gtk::Dialog * dialog = new Gtk::Dialog();
    std::vector<Gtk::Label *> labels;
    std::vector<Gtk::Entry *> entries;
    std::vector<Gtk::HBox *> boxes;

    if (item == 0) {
        dialog->set_title("Create Container");

        Gtk::HBox * box = Gtk::manage(new Gtk::HBox);
        boxes.push_back(box);

        Gtk::Label * label = Gtk::manage(new Gtk::Label{"Max Scoops"});
        label->set_width_chars(15);
        box->pack_start(*label, Gtk::PACK_SHRINK);
        labels.push_back(label);

        Gtk::Entry * entry = Gtk::manage(new Gtk::Entry);
        entry->set_max_length(75);
        box->pack_start(*entry, Gtk::PACK_SHRINK);
        entries.push_back(entry);


    } else if (item == 1) {
        dialog->set_title("Create Flavor");
    } else if (item == 2) {
        dialog->set_title("Create Topping");
    }

    for (unsigned int i = 0; i < textL.size(); i++) {
        Gtk::HBox * box = Gtk::manage(new Gtk::HBox);
        boxes.push_back(box);

        Gtk::Label * label = Gtk::manage(new Gtk::Label{textL[i]});
        label->set_width_chars(15);
        box->pack_start(*label, Gtk::PACK_SHRINK);
        labels.push_back(label);

        Gtk::Entry * entry = Gtk::manage(new Gtk::Entry);
        entry->set_max_length(75);
        box->pack_start(*entry, Gtk::PACK_SHRINK);
        entries.push_back(entry);

        dialog->get_vbox()->pack_start(*boxes[i], Gtk::PACK_SHRINK);
    }
    if (!item)
        dialog->get_vbox()->pack_start(*boxes[5], Gtk::PACK_SHRINK);

    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    // will most likely need some error checking here
    /* If the user hit "OK", add item to emporium */
    std::vector<std::string> output;
    if(dialog->run()) {
        unsigned int size = item ? textL.size() : textL.size();
        for (unsigned int i = 0; i < size; i++) {
            output.push_back(entries[i]->get_text());
        }
        _emp.addItem(item, output);
    }

    dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();

    delete dialog;
}

void Controller::createServer() {
    std::vector<std::string> textL{"Name", "ID", "Phone Number", "Salary"};
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create Server");
    // dialog->set_transient_for(*this);

    std::vector<Gtk::HBox *> boxes;
    std::vector<Gtk::Label *> labels;
    std::vector<Gtk::Entry *> entries;
    
    for (unsigned int i = 0; i < textL.size(); i++) {
        Gtk::HBox * box = Gtk::manage(new Gtk::HBox);

        Gtk::Label * label = Gtk::manage(new Gtk::Label{textL[i]});
        label->set_width_chars(15);
        labels.push_back(label);

        Gtk::Entry * entry = Gtk::manage(new Gtk::Entry);
        entry->set_max_length(50);
        entries.push_back(entry);

        box->pack_start(*label, Gtk::PACK_SHRINK);
        box->pack_start(*entry, Gtk::PACK_SHRINK);
        boxes.push_back(box);
        dialog->get_vbox()->pack_start(*box, Gtk::PACK_SHRINK);
    }

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();

    std::vector<std::string> outputs;
    if(dialog->run()) {
        for (unsigned int i = 0; i < textL.size(); i++) {
            outputs.push_back(entries[i]->get_text());
        }
        _emp.addServer(outputs);
    }
    dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
}

void Controller::createCustomer() {
    std::vector<std::string> textL{"Name", "ID", "Phone Number"};
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create Customer");
    // dialog->set_transient_for(*this);

    std::vector<Gtk::HBox *> boxes;
    std::vector<Gtk::Label *> labels;
    std::vector<Gtk::Entry *> entries;
    
    for (unsigned int i = 0; i < textL.size(); i++) {
        Gtk::HBox * box = Gtk::manage(new Gtk::HBox);

        Gtk::Label * label = Gtk::manage(new Gtk::Label{textL[i]});
        label->set_width_chars(15);
        labels.push_back(label);

        Gtk::Entry * entry = Gtk::manage(new Gtk::Entry);
        entry->set_max_length(50);
        entries.push_back(entry);

        box->pack_start(*label, Gtk::PACK_SHRINK);
        box->pack_start(*entry, Gtk::PACK_SHRINK);
        boxes.push_back(box);
        dialog->get_vbox()->pack_start(*box, Gtk::PACK_SHRINK);
    }

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();

    std::vector<std::string> outputs;
    if(dialog->run()) {
        for (unsigned int i = 0; i < textL.size(); i++) {
            outputs.push_back(entries[i]->get_text());
        }
        _emp.addCustomer(outputs);
    }
    dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
}

void Controller::createEmporium() {

}

void Controller::errorMessage(std::string err) {
    Gtk::MessageDialog *dialog = new Gtk::MessageDialog("ERROR");
    dialog->set_secondary_text(err, true);
    dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete dialog;
}

void Controller::loadInventory() {
    std::vector<std::string> serv1 = {"Iron Man", "(817) 782-2734", "1", "32.50"};
    std::vector<std::string> serv2 = {"Captain America", "(313) 346-2828", "1", "32.00"};
    std::vector<std::string> serv3 = {"The Hulk", "(714) 685-3284", "1", "19.25"};
    
    _emp.addServer(serv1);
    _emp.addServer(serv2);
    _emp.addServer(serv3);

    std::vector<std::string> container1 = {"3", "Waffle Cone", "Cone made of waffle", "0.10", "1.99", "1200","cup.jpg"};
    std::vector<std::string> container2 = {"6", "Paper Cup", "Plain old paper", "0.25", "1.00", "1500","cup.jpg"};
    std::vector<std::string> container3 = {"15", "Tub", "For the bad break-ups", "2.99", "4.99", "100","cup.jpg"};

    _emp.addItem(0, container1);
    _emp.addItem(0, container2);
    _emp.addItem(0, container3);

    std::vector<std::string> flavor1 = {"Vanilla", "Classy yet delicious", "0.99", "1.99", "100","img/cup.jpg"};
    std::vector<std::string> flavor2 = {"Cookies and Cream", "Vanilla wasn't enough so we added cookies", "1.29", "2.79", "75","img/cup.jpg"};
    std::vector<std::string> flavor3 = {"Pistachio", "Pistachio flavored", "1.19", "1.29", "50","img/cup.jpg"};

    _emp.addItem(1, flavor1);
    _emp.addItem(1, flavor2);
    _emp.addItem(1, flavor3);

    std::vector<std::string> topping1 = {"Marshmallows", "Magically delicious", "0.05", "0.10", "300","cup.jpg"};
    std::vector<std::string> topping2 = {"Chocolate Syrup", "Desc", "0.07", "0.10", "300","cup.jpg"};
    std::vector<std::string> topping3 = {"Gummi Worms", "For the gummi fish", "0.02", "0.10", "200","cup.jpg"};

    _emp.addItem(2, topping1);
    _emp.addItem(2, topping2);
    _emp.addItem(2, topping3);
}

std::string Controller::getFilename() {
    return _filename;
}

void Controller::save(std::ostream& os) {
    os << _emp;
}

/*************************
      L I S T I N G
*************************/
std::vector<mice::Container *> Controller::containers() {
    return _emp.containers();
}

std::vector<Scoop *> Controller::scoops() {
    return _emp.scoops();
}

std::vector<Topping *> Controller::toppings() {
    return _emp.toppings();
}

/***************************
      R E P O R T I N G
****************************/

void Controller::reportInventory() {
    std::string inv = "";
    inv += "Containers:\n";
    inv += _emp.listContainers() + "\n";
    inv += "Scoops:\n";
    inv += _emp.listScoops() + "\n";
    inv += "Toppings:\n";
    inv += _emp.listToppings() + "\n";
    
    Gtk::MessageDialog *dialog = new Gtk::MessageDialog("Inventory Report");
    dialog->set_secondary_text(inv, true);
    dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();

    delete dialog;
}

void Controller::reportCustomers()
{
    std::string cust = "";
    cust += _emp.listCustomers();

    Gtk::MessageDialog *dialog = new Gtk::MessageDialog("Customer Report");
    dialog->set_secondary_text(cust, true);
    dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();

    delete dialog;
}
