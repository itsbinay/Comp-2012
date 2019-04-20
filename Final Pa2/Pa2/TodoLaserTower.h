/*
 * Laser.h
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#ifndef TODOLASERTOWER_H_
#define TODOLASERTOWER_H_

#include "Tower.h"

class TodoLaserTower:public Tower{
public:
  TodoLaserTower(int,int);
  ~TodoLaserTower();
  bool isInRange(int x, int y) const override;
  string getName() const override;
  char getSymbol() const override;
};

#endif /* TODOLASERTOWER_H_ */
