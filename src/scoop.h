#ifndef _SCOOP_H
#define _SCOOP_H

#include <string>

#include "item.h"

class Scoop : public Item {
  public:
    // Scoop(std::string, std::string, double, double, int, Gtk::Image);
    
    /* for testing purposes before we are ready to work with images */
    Scoop(std::string, std::string, double, double, int);

    std::string type() override;
};
#endif
