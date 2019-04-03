#ifndef CHIEF_COOK_H
#define CHIEF_COOK_H

#include "cook.h"

#include <iostream>

class ChiefCook : public Cook
{
public:
  ChiefCook(std::string name);
  virtual void meet(const Cook &cook) const;
};

#endif
