#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
	// Modify the function declarations below

	Employee(const char* name);

	~Employee();

	void print_description() const;

	void print_salary() const;

private:
	char* name;
};

#endif