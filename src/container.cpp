#include "container.h"

Container::Container(int type) : cType{type} {}
void Container::set_max(){
  //switch(cType){
  //  case(cup): maxScoop = 2;
  //  case(bowl): maxScoop =5;
  //  case(waffle): maxScoop = 3;
  //  default: maxScoop = 0;
  //}
  if(cType == bowl){
    maxScoop = 2;
  }
};

int Container::get_max(){
	return maxScoop;
}
