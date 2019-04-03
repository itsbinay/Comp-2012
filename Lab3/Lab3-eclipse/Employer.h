// TODO: Class declaration of Employer
#ifndef _EMPLOYER_H
#define _EMPLOYER_H

#include "Person.h"
#include "Employee.h"
#include <string>

using namespace std;

class Employer : public Person
{
private:
    Employee* employee[NUM_MAX_EMPLOYEE];
    int num_of_employee;
public:
    Employer(string name);
    
    void pay_salary();
    void hire(Employee *employee);
    
};
#endif
