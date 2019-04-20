/*
 * IceTower.h
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#ifndef TODOICETOWER_H_
#define TODOICETOWER_H_

#include "Tower.h"
#include "Enemy.h"
class TodoIceTower: public Tower{
public:
  TodoIceTower(int,int);
  ~TodoIceTower();
  bool isInRange(int x, int y) const override;
  void fire(Enemy&) override;
  string getName() const override;
  char getSymbol() const override;
  void upgrade() override;
};

#endif /* TODOICETOWER_H_ */
