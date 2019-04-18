/*
 * Catapult.h
 *
 *  Created on: Mar 12, 2019
 *      Author: kevinw
 */

#ifndef TODOCATAPULT_H_
#define TODOCATAPULT_H_

#include "Tower.h"
class TodoCatapult:public Tower{
  friend class Object;
public:
  TodoCatapult(int,int);
  ~TodoCatapult();
  bool isInRange(int x, int y) const override;
  string getName() const override;
  char getSymbol() const override;
private:
  int catapultRange;
};

#endif /* TODOCATAPULT_H_ */
