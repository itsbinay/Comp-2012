#ifndef PERSON_H
#define PERSON_H

#include <string>

const int NUM_MAX_EMPLOYEE = 10;

class Person {
private:
    std::string name;  // use std::string if you don't have "use namespace std"
public:
    Person(std::string name);
    std::string get_name() const;
};

#endif //PERSON_H
