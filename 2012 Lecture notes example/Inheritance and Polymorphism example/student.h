#ifndef _STUDENT_H
#define _STUDENT_H

#include "uperson.h"
#include <string>

class Student : Public UPerson{
private:
  float GPA;
  Course* enrolled;
  int num_courses;

private:
  Student(string n, Department d, float x):UPerson(n,d)
};
#endif
