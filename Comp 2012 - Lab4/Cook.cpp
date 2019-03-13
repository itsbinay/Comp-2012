#include "Cook.h"

//TODO implement the constructor.
Cook::Cook(std::string _name){
this->name=_name;
}
//TODO implement to get the name of the cook.
std::string Cook::get_name() const{
  return name;
}

void Cook::self_intro() const{
	//TODO print "I am {get_name}. I am a cook."
  std::cout<<"I am "<<get_name()<<". I am a cook."<<std::endl;
}
