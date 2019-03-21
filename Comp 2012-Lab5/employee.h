#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
	// Modify the function declarations below

	Employee(const char* name);

	virtual ~Employee();

	virtual void print_description() const;

	virtual void print_salary() const=0;

private:
	char* name;
	int salary;
};

#endif
