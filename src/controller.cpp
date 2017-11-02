#include <gtkmm.h>

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
    std::vector<std::string> _textLabels{"", "", "", ""};
    // dialog->set_transient_for(*this);

    int item = itemType();
    Gtk::Dialog * dialog = new Gtk::Dialog();
    
    // May be better to use an enum here for more clarity
        // Max Scoops
        Gtk::HBox b_scoops;

        Gtk::Label l_scoops{"Max Scoops:"};
        l_scoops.set_width_chars(15);
        b_scoops.pack_start(l_scoops, Gtk::PACK_SHRINK);

        Gtk::Entry e_scoops;
        e_scoops.set_max_length(50);
        b_scoops.pack_start(e_scoops, Gtk::PACK_SHRINK);
    if (item == 0) {
        dialog->get_vbox()->pack_start(b_scoops, Gtk::PACK_SHRINK);

        dialog->set_title("Create Container");
    } else if (item == 1) {
        dialog->set_title("Create Flavor");
    } else {
        dialog->set_title("Create Topping");
    }

    // Name
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    // Description
    Gtk::HBox b_desc;

    Gtk::Label l_desc{"Description:"};
    l_desc.set_width_chars(15);
    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

    Gtk::Entry e_desc;
    e_desc.set_max_length(50);
    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);

    // Cost
    Gtk::HBox b_cost;

    Gtk::Label l_cost{"Cost:"};
    l_cost.set_width_chars(15);
    b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

    Gtk::Entry e_cost;
    e_cost.set_max_length(50);
    b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

    // Price
    Gtk::HBox b_price;

    Gtk::Label l_price{"Price:"};
    l_price.set_width_chars(15);
    b_price.pack_start(l_price, Gtk::PACK_SHRINK);

    Gtk::Entry e_price;
    e_price.set_max_length(50);
    b_price.pack_start(e_price, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

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
