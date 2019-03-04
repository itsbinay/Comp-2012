#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string name): name(name) {}

string Person::get_name() const {
    return name;
}
