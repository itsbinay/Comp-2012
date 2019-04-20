/*
 * DiagonalEnemy.h
 *
 *  Created on: Mar 13, 2019
 *      Author: kevinw
 */

#ifndef TODODIAGONALENEMY_H_
#define TODODIAGONALENEMY_H_
#include "Enemy.h"
#include "Arena.h"
class TodoDiagonalEnemy: public Enemy{
public:
  TodoDiagonalEnemy(int,int,int);
  ~TodoDiagonalEnemy();
  char getSymbol() const override;
  void move() override;
private:
  bool changeDIR;
};

#endif /* TODODIAGONALENEMY_H_ */
