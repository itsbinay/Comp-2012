#include "SteakCook.h"

//TODO implement the constructor
SteakCook::SteakCook(std::string _name):Cook(_name){
}
void SteakCook::cook_steak() const{
	//TODO print "{get_name} cooks a steak."
  std::cout<<get_name()<<" cooks a steak."<<std::endl;
}

void SteakCook::self_intro() const{
	//TODO print "I am {get_name}. I am a cook for steak."
std::cout<<"I am "<<get_name()<<". I am a cook for streak."<<std::endl;
}
