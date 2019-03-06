#include <iostream>
#include "Cook.h"
using namespace std;

// TODO: complete the constructor of Cook
Cook::Cook(string name, int salary, string type_of_meal): Employee(name,salary),
		type_of_meal(type_of_meal) {}

// TODO: complete Cook::cook_meal
void Cook::cook_meal() {
    // print "{name of employee} cooks {type_of_meal}."
	cout<<this->get_name()<<" cooks "<<type_of_meal<<"."<<endl;
}
