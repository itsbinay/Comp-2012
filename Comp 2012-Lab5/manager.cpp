#include "manager.h"
#include <iostream>
#include <cstring>

using namespace std;
Manager::Manager(const char* name, int base_salary, int comission) :Employee(name),base_salary(base_salary), comission(comission){
}

Manager::~Manager(){
    
    for(int i=0;i<num_staff;i++){
        delete staff[i];
    }
   cout << "Manager Dtor: "<<endl;
}

void Manager::print_salary() const{
  cout<<"Salary: "<<this->base_salary+this->comission<<endl;
}
void Manager::print_description() const{
  Employee::print_description();
  cout<<" Duty: Manager"<<endl;
}
void Manager::hire(Employee* new_staff){
  if(num_staff<MAX_NUM_STAFF){
    staff[num_staff]=new_staff; //Address of new staff copied to the array element
    num_staff++;
  }
  else{
    cout<<"Cannot hire any more staff"<< endl;
  }
}
void Manager::pay_salary() const{
  for(int i=0;i<num_staff;i++){
    staff[i]->print_description();
    (*staff[i]).print_salary();
  }
  //Manager's turn to print out
  this->print_description();
  this->print_salary();
}
