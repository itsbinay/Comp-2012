#include <iostream>
#include "Employer.h"
#include "Cook.h"
#include "Cleaner.h"
using namespace std;

int main() {

    Employer employer{"John"};

    Cook cook{"Ann", 500, "burgers"};
    Cleaner cleaner{"Bob", 400};

    employer.hire(&cook);
    employer.hire(&cleaner);

    cook.cook_meal();
    cleaner.clean();

    employer.pay_salary();

    return 0;
}