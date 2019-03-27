#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>

#include "cook.h"

class Manager : public Person
{
public:
  Manager(std::string name);
  virtual void meet(const Cook &cook) const;
};

#endif
