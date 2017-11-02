#include <gtkmm.h>
#include <iostream>

#include "controller.h"

Controller::Controller(Emporium& emp)
: _emp{emp}
{ }

void Controller::execute(int cmd) {
    switch (cmd) {
        case CREATE_ITEM: createItem(); break;
        case CREATE_SERVER: createServer(); break;
        case CREATE_CUSTOMER: createCustomer(); break;
        case CREATE_EMPORIUM: createEmporium(); break;
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
    box.pack_start(dropDown, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(box, Gtk::PACK_SHRINK);

    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    if (dialog->run()) {
        item = dropDown.get_active_row_number();
    }

    dialog->close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
    return item;
}

void Controller::createItem() {
    std::vector<std::string> textL{"Max Scoops", "Name", "Description",
                                   "Cost", "Price", "Stock"};
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

        dialog->get_vbox()->pack_start(*boxes[0], Gtk::PACK_SHRINK);

    } else if (item == 1) {
        dialog->set_title("Create Flavor");
    } else {
        dialog->set_title("Create Topping");
    }

    for (unsigned int i = 1; i < textL.size(); i++) {
        std::cout << textL[i] << std::endl;
        Gtk::HBox * box = Gtk::manage(new Gtk::HBox);
        boxes.push_back(box);

        Gtk::Label * label = Gtk::manage(new Gtk::Label{textL[i]});
        label->set_width_chars(15);
        box->pack_start(*label, Gtk::PACK_SHRINK);
        labels.push_back(label);

        Gtk::Entry * entry = Gtk::manage(new Gtk::Entry);
        entry->set_max_length(75);
        box->pack_start(*entry, Gtk::PACK_SHRINK);

        dialog->get_vbox()->pack_start(*boxes[i], Gtk::PACK_SHRINK);
    }

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    // int result = dialog->run();
    // if result = 1 add item to emporium
    // will most likely need some error checking here
    std::vector<std::string> output;
    if(dialog->run()) {
    }

    dialog->close();

    while (Gtk::Main::events_pending()) Gtk::Main::iteration();
}

void Controller::createServer() {
        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Create Server");
        // dialog->set_transient_for(*this);

        // Name
        Gtk::HBox b_name;

        Gtk::Label l_name{"Name:"};
        l_name.set_width_chars(15);
        b_name.pack_start(l_name, Gtk::PACK_SHRINK);

        Gtk::Entry e_name;
        e_name.set_max_length(50);
        b_name.pack_start(e_name, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

        // ID
        Gtk::HBox b_id;

        Gtk::Label l_id{"ID:"};
        l_id.set_width_chars(15);
        b_id.pack_start(l_id, Gtk::PACK_SHRINK);

        Gtk::Entry e_id;
        e_id.set_max_length(50);
        b_id.pack_start(e_id, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

        // Phone Number
        Gtk::HBox b_phone;

        Gtk::Label l_phone{"Phone Number:"};
        l_phone.set_width_chars(15);
        b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

        Gtk::Entry e_phone;
        e_phone.set_max_length(50);
        b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

        // Salary
        Gtk::HBox b_salary;

        Gtk::Label l_salary{"Salary:"};
        l_salary.set_width_chars(15);
        b_salary.pack_start(l_salary, Gtk::PACK_SHRINK);

        Gtk::Entry e_salary;
        e_salary.set_max_length(50);
        b_salary.pack_start(e_salary, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_salary, Gtk::PACK_SHRINK);

        // Show dialog
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        // int result = dialog->run();
        // if result = 1 add server to emporium
        dialog->run();

        dialog->close();

        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();
}

void Controller::createCustomer() {
        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Create Customer");
        // dialog->set_transient_for(*this);

        // Name
        Gtk::HBox b_name;

        Gtk::Label l_name{"Name:"};
        l_name.set_width_chars(15);
        b_name.pack_start(l_name, Gtk::PACK_SHRINK);

        Gtk::Entry e_name;
        e_name.set_max_length(50);
        b_name.pack_start(e_name, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

        // ID
        Gtk::HBox b_id;

        Gtk::Label l_id{"ID:"};
        l_id.set_width_chars(15);
        b_id.pack_start(l_id, Gtk::PACK_SHRINK);

        Gtk::Entry e_id;
        e_id.set_max_length(50);
        b_id.pack_start(e_id, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

        // Phone Number
        Gtk::HBox b_phone;

        Gtk::Label l_phone{"Phone Number:"};
        l_phone.set_width_chars(15);
        b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

        Gtk::Entry e_phone;
        e_phone.set_max_length(50);
        b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

        // Show dialog
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        // int result = dialog->run();
        // if result = 1 add customer to emporium
        dialog->run();

        dialog->close();

        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();
}

void Controller::createEmporium() {

}
