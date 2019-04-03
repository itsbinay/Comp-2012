#include <iostream>

#include "BurgerCook.h"
#include "Cook.h"
#include "SteakCook.h"
#include "CheeseBurgerCook.h"
#include "Store.h"
using namespace std;

int main(){
	cout << "Create a new cook!" <<endl;
	Cook cook("Clare");
	cook.self_intro();
	cout<<endl;

	cout<<"Create a new burger cook!" <<endl;
	BurgerCook burger_cook("Bob");
	burger_cook.self_intro();
	burger_cook.cook_burger();
	cout<<endl;

	cout<<"Create a new steak cook!" <<endl;
	SteakCook steak_cook("Sam");
	steak_cook.self_intro();
	steak_cook.cook_steak();
	cout<<endl;

	cout<<"Create a new cheese burger!" <<endl;
	CheeseBurgerCook cheese_burger_cook("Cherry");
	cheese_burger_cook.self_intro();
	cheese_burger_cook.cook_burger();
	cheese_burger_cook.cook_cheese_burger();
	cout<<endl;

	cout<<"The junk food store is hiring cooks!"<<endl;
	Store store;
	store.hire(cook);
	store.hire(burger_cook);
	store.hire(steak_cook);
	store.hire(cheese_burger_cook);

	return 0;
}
