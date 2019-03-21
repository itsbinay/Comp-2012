#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

const int MAX_NUM_STAFF=5;
class Manager: public Employee{
private:
  Employee *staff[MAX_NUM_STAFF];
  int num_staff=0;
  int base_salary;
  int comission;

public:
  Manager(const char* name, int base_salary, int comission);
  ~Manager();
  void print_salary() const;
  void print_description() const;
  void hire(Employee* new_staff);
  void pay_salary() const;
};
#endif
