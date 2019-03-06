// TODO: Class declaration of Cook
#include "Employee.h"
#include <string>
using namespace std;

class Cook : public Employee{
private:
	string type_of_meal;
public:
	Cook(string name,int salary,string type_of_meal);
	void cook_meal();
};
