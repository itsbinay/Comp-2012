/*
 * RevivingEnemy.h
 *
 *  Created on: Mar 15, 2019
 *      Author: kevinw
 */

#ifndef TODOREVIVINGENEMY_H_
#define TODOREVIVINGENEMY_H_
#include "Enemy.h"

class TodoRevivingEnemy:public Enemy{
public:
  TodoRevivingEnemy(int,int,int);
  ~TodoRevivingEnemy();
  char getSymbol() const override;
  void fired(int) override;
  string getName() const override;
  //The move function is the same as the enemy class
private:
  bool dead_before=false;
};

#endif /* TODOREVIVINGENEMY_H_ */
