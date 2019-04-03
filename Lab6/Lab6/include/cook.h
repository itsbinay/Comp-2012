#ifndef COOK_H
#define COOK_H

#include <iostream>

#include "person.h"


class Cook : protected Person	//Change from protected to public inheritance for Task 1
{
public:
  Cook(std::string name);
  virtual void meet(const Cook &cook) const;
  friend class Manager;	//Comment this for Task 3
};

#endif
