#include <iostream>
#include <cstring>

#include "employee.h"

using namespace std;

Employee::Employee(const char* name)
{
	// 1. Allocate dynamic memory for private member "name"
	// Hint: strlen() function is useful here
	// 2. Copy the name using strcpy
}

Employee::~Employee()
{
	cout << "Employee Dtor: " << name << endl;

	// Free dynamically allocated memory
}

void Employee::print_description() const
{
	cout << "Employee: " << name;
}