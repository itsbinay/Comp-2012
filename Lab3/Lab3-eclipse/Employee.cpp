#include <iostream>
#include "Employee.h"
using namespace std;

// TODO: complete the constructor of Employee
Employee::Employee(string name, int salary): Person(name),salary(salary){
}

int Employee::get_salary() const {
    return salary;
}
