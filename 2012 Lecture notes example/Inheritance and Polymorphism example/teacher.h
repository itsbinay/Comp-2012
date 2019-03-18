#ifndef _TEACHER_H
#define _TEACHER_H
/*Teacher.h file*/
#include "uperson.h"
#include <string>

enum Rank{PROFESSOR,DEAN,PRESIDENT};

class Teacher:public Uperson{
private:
  Rank rank;
  string research_area;
public:
  Teacher(string n, Department d, Rank r, string a) : UPerson(n,d),rank(r),research_area(a) {}
  Rank get_rank() const{return rank;}
  string get_research_area()const{return research_area;}
};
#endif
