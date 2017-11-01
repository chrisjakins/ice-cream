#include "controller.h"
#include <gtkmm.h>

Controller::Controller(Emporium& emp)
: _emp{emp}
{ }

void Controller::execute(int cmd) {
    if (cmd == CREATE_ITEM) {
        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Select Item Type");
        // dialog->set_transient_for(*this);

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

        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();

        int itemType = c_type.get_active_row_number();

        dialog = new Gtk::Dialog();
        
        // May be better to use an enum here for more clarity
        if (itemType == 0) {
            dialog->set_title("Create Container");
            // Max Scoops
            Gtk::HBox b_scoops;

            Gtk::Label l_scoops{"Max Scoops:"};
            l_scoops.set_width_chars(15);
            b_scoops.pack_start(l_scoops, Gtk::PACK_SHRINK);

            Gtk::Entry e_scoops;
            e_scoops.set_max_length(50);
            b_scoops.pack_start(e_scoops, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_scoops, Gtk::PACK_SHRINK);

        } else if (itemType == 1) {
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
        dialog->run();

        dialog->close();

        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();
    }
    else if (cmd == CREATE_SERVER)
    {
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
    } else if (cmd == CREATE_CUSTOMER)
    {
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
    } else {}
}
