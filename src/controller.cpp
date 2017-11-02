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
        case CREATE_SERVING: createServing(); break;
        default: /* what to do here */;
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
        /* what to do if cancelled */
    }

    dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
    return item;
}

void Controller::createItem() {
    std::vector<std::string> textL{"Name", "Description", "Cost",
                                   "Price", "Stock", "Max Scoops"};
    std::vector<std::string> outputs;

    // dialog->set_transient_for(*this);

    int item = itemType();

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

void Controller::createServing() {

}

void Controller::createEmporium() {

}
