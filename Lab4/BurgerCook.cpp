#include "BurgerCook.h"

//TODO implement the constructor
BurgerCook::BurgerCook(std::string _name): Cook(_name){
}
void BurgerCook::cook_burger() const{
	//TODO print "{get_name} cooks burger."
  std::cout<<this->get_name()<<" cooks burger."<<std::endl;
}

void BurgerCook::self_intro() const{
	//TODO "I am {get_name}. I am a cook for burger."
  std::cout<<"I am "<<get_name()<<". I am a cook for burger."<<std::endl;
}
