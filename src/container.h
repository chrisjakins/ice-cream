#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <string>
using namespace std;

class Container{
  public:
    Container(string type) : type{type} {}
    void set_max(type);
    void get_max();
  private:
    int maxScoop;
    string type;
};
#endif
