#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
  Person(std::string name);

public:
  std::string name_card() const;
  virtual std::string title() const;
  void says_to(const Person &person, std::string msg) const;

private:
  std::string name;
};

#endif
