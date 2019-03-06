#include <iostream>
#include "Cleaner.h"
using namespace std;

// TODO: complete the constructor of Cleaner

Cleaner::Cleaner(string name, int salary):Employee(name,salary){

}

//TODO: complete Cleaner::clean
void Cleaner::clean() {
    // print "{name of employee} cleans the restaurant."
	cout<<this->get_name()<<" cleans the restaurant."<<endl;
}
