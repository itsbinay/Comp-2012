#include <iostream>
#include "Employer.h"
using namespace std;

// TODO: complete the constructor of Employer
Employer::Employer(string name):Person(name) {}

// TODO: complete Employer::pay_salary
void Employer::pay_salary() {
    // for all the employees
    // print "{name of employer} pays ${salary of employee} to {name of employee}."
}

// TODO: complete Employer::hire
void Employer::hire(Employee *employee) {
    if (num_of_employee >= NUM_MAX_EMPLOYEE)
        cout << "Cannot have new employee anymore." << endl;
    // append the new employee to the end of the list
    // increment the number of employees
    // print "{name of employer} hires {name of employee}."
}
