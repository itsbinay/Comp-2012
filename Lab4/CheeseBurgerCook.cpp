#include "CheeseBurgerCook.h"

//TODO implement the constructor
CheeseBurgerCook::CheeseBurgerCook(std::string _name) : BurgerCook(_name){
}
void CheeseBurgerCook::cook_cheese_burger() const{
	//TODO print "{get_name} cooks cheese burger."
  std::cout<<this->get_name()<<" cooks cheese burger."<<std::endl;
}

void CheeseBurgerCook::self_intro() const{
	//TODO print "I am {get_name}. I am a cook for cheese burger."
std::cout<<"I am "<<this->get_name()<<". I am a cook for cheese burger."<<std::endl;
}
