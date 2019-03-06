// TODO: Class declaration of Employee
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include "Person.h"
#include <string>
class Employee: public Person
{
private:
    int salary;
public:
    Employee(string name, int salary);
};

#endif
