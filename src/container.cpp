#include "container.h"

void set_max(type){
  switch(type){
    case(cup): maxScoop = 2;
    case(bowl): maxScoop =5;
    case(waffle):maxScoop = 3;
    default: maxScoop = 0;
  }
}

void get_max(){
	return maxScoop;
}
