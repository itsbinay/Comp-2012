#include <iostream>
#include <cstring>

#include "employee.h"

using namespace std;

Employee::Employee(const char* name)
{
	// 1. Allocate dynamic memory for private member "name"
	this->name=new char[strlen(name)+1];
	// Hint: strlen() function is useful here
	// 2. Copy the name using strcpy
	strcpy(this->name,name);
}

Employee::~Employee()
{
	cout << "Employee Dtor: " << name << endl;
    delete []name;
	// Free dynamically allocated memory
}

void Employee::print_description() const
{
	cout << "Employee: " << name;
}

