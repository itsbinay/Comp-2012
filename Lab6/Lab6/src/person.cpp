// Finish your person.cpp here
#include "../include/person.h"

#include <iostream>
using namespace std;

Person::Person(std::string name):name(name){}

string Person::name_card() const{
	return this->name+"("+title()+")";
}

void Person::says_to(const Person &person, std::string msg) const{
	cout<<this->name_card()<< " says to "<< person.name_card()<<":"<<msg<<endl;
}

string Person::title() const{
	string a=typeid(*this).name();
	int length=a.length();
	return a.substr(1,length-1);
}
