#ifndef _SCOOP_H
#define _SCOOP_H
#include <string>
using namespace std;

class Scoop {
  public:
    Scoop(int flav) : flavor(flav) { }

    static const int vanilla = 0;
    static const int chocolate = 1;
    static const int strawberry = 2;

    string to_string() {
      switch(flavor) {
        case(vanilla):return "vanilla";
        case(chocolate):return "chocolate";
        case(strawberry):return "strawberry";
        default: return "UNKNOWN";
      }
    }
  private:
    int flavor;
};
#endif