#include "cook.h"
#include <iostream>
#include <cstring>
using namespace std;

Cook::Cook(const char* name, int hourlywage, int hoursworked): Employee(name),
hourly_wage(hourlywage),hours_worked(hoursworked){}

Cook::~Cook(){
  cout << "Cook Dtor" << endl;
}

void Cook::print_description() const{
  Employee::print_description();
    cout<<" Duty: Cook"<<endl;
}

void Cook::print_salary() const{
  cout<<"Salary: "<<hourly_wage*hours_worked<<endl;
}
