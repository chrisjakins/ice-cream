#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <string>
using namespace std;

class Container{
  public:
    Container(int type);
    static const int cup = 0;
    static const int bowl = 1;
    static const int waffle = 2;
    
    void set_max();
    int get_max();

  private:
    int maxScoop;
    int cType;
};
#endif
