// TODO: Class declaration of Cleaner
#ifndef _CLEANER_H
#define _CLEANER_H
#include <string>
#include "Employee.h"

using namespace std;

class Cleaner : public Employee{

public:
	Cleaner(string name, int salary);
	void clean();
};

#endif
