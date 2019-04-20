/*
 * LazyTower.h
 *
 *  Created on: Mar 11, 2019
 *      Author: kevinw
 */

#ifndef TODOSIMPLETOWER_H_
#define TODOSIMPLETOWER_H_

#include "Tower.h"
class TodoSimpleTower:public Tower{
  friend class Object;
public:
  TodoSimpleTower(int x, int y);
  ~TodoSimpleTower();
  bool isInRange(int x, int y) const override;
  string getName() const override;
  char getSymbol() const override;
};
#endif /* TODOSIMPLETOWER_H_ */
