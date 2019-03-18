#ifndef _UPERSON_H
#define _UPERSON_H
#include <string>
enum Department{CBME, CIVIL,CSE , ECE, IELM, MAE};
class UPerson{
private:
  string name;
  Department dept;

public:
  Uperson(string n, Department d): name(n), dept(d){}
  string get_name() const {return name;}
  Department get_department() const {return dept;}
};
#endif
