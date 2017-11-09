#include <gtkmm.h>

#include "controller.h"
#include "item.h"

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
        return -1;
    }

    dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
    delete dialog;
    return item;
} 

void Controller::createItem() {
    std::vector<std::string> textL{"Name", "Description", "Cost",
                                   "Price", "Stock", "Max Scoops"};
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

    for (unsigned int i = 0; i < textL.size() - 1; i++) {
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
        unsigned int size = item ? textL.size() - 1 : textL.size();
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
    /* std::vector<std::string> serv1 = {"Iron Man", "(817) 782-2734", "1", "32.50"}; */
    /* std::vector<std::string> serv2 = {"Captain America", "(313) 346-2828", "1", "32.00"}; */
    /* std::vector<std::string> serv3 = {"The Hulk", "(714) 685-3284", "1", "19.25"}; */
    
    /* _emp.addServer(serv1); */
    /* _emp.addServer(serv2); */
    /* _emp.addServer(serv3); */

    std::vector<std::string> container1 = {"3", "Waffle Cone", "Cone made of waffle", "0.10", "1.99", "1200"};
    std::vector<std::string> container2 = {"6", "Paper Cup", "Plain old paper", "0.25", "1.00", "1500"};
    std::vector<std::string> container3 = {"15", "Tub", "For the bad break-ups", "2.99", "4.99", "100"};

    _emp.addItem(0, container1);
    _emp.addItem(0, container2);
    _emp.addItem(0, container3);

    std::vector<std::string> flavor1 = {"Vanilla", "Classy yet delicious", "0.99", "1.99", "100"};
    std::vector<std::string> flavor2 = {"Cookies and Cream", "Vanilla wasn't enough so we added cookies", "1.29", "2.79", "75"};
    std::vector<std::string> flavor3 = {"Pistachio", "Pistachio flavored", "1.19", "1.29", "50"};

    _emp.addItem(1, flavor1);
    _emp.addItem(1, flavor2);
    _emp.addItem(1, flavor3);

    std::vector<std::string> topping1 = {"Marshmallows", "Magically delicious", "0.05", "0.10", "300"};
    std::vector<std::string> topping2 = {"Chocolate Syrup", "Desc", "0.07", "0.10", "300"};
    std::vector<std::string> topping3 = {"Gummi Worms", "For the gummi fish", "0.02", "0.10", "200"};

    _emp.addItem(2, topping1);
    _emp.addItem(2, topping2);
    _emp.addItem(2, topping3);
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
