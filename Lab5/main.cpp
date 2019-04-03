#include <iostream>

#include "cook.h"
#include "manager.h"

using namespace std;

int main(int argc, char **argv)
{
	Manager manager{"Bob", 20000, 3000};

	manager.hire(new Cook("Alice", 100, 80));
	manager.hire(new Cook("Chris", 90, 150));
	manager.pay_salary();

	return 0;
}
/*
 D:B
 B* ptr = new D();
 
 delete ptr; <------
 
 */
