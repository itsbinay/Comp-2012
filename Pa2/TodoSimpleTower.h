/*
 * LazyTower.h
 *
 *  Created on: Mar 11, 2019
 *      Author: kevinw
 */

#ifndef TODOSIMPLETOWER_H_
#define TODOSIMPLETOWER_H_

#include "Tower.h"
class SimpleTower:public Tower{
public:
  SimpleTower();
  ~SimpleTower();
  bool isInRange(int x, int y) const;
};
#endif /* TODOSIMPLETOWER_H_ */
