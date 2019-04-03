#ifndef COOK_H
#define COOK_H
#include "employee.h"
class Cook: public Employee{
private:
int hourly_wage;
int hours_worked;

public:
  Cook(const char* name, int hourlywage, int hoursworked);
  ~Cook();
  void print_description() const;
  void print_salary() const;
};
#endif
