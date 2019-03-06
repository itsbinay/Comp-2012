#include <iostream>
#include "Employer.h"
using namespace std;

// TODO: complete the constructor of Employer
Employer::Employer(string name):Person(name){
	this->num_of_employee=0;
}

// TODO: complete Employer::pay_salary
void Employer::pay_salary() {
    // for all the employees
    // print "{name of employer} pays ${salary of employee} to {name of employee}."
	for(int i=0;i<num_of_employee;i++)
	{
		cout<<this->get_name()<<" pays $"<<employee[i]->get_salary()<<" to "<<employee[i]->get_name()<<"."<<endl;
	}
}

// TODO: complete Employer::hire
void Employer::hire(Employee *employee) {
    if (num_of_employee >= NUM_MAX_EMPLOYEE)
        cout << "Cannot have new employee anymore." << endl;
    // append the new employee to the end of the list
    // increment the number of employees
    // print "{name of employer} hires {name of employee}."
    this->employee[num_of_employee]=employee;
    cout<<this->get_name()<<" hires "<<employee->get_name()<<endl;
    this->num_of_employee++;
}
