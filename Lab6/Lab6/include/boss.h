#ifndef BOSS_H
#define BOSS_H

#include "person.h"
#include "cook.h"

class Boss : public Person
{
public:
  Boss(std::string name);
  virtual void meet(const Cook &cook) const;
};

#endif
