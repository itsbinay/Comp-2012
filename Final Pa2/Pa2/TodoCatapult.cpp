/*
 * Catapult.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: kevinw
 */

#include "TodoCatapult.h"
#include <math.h>
const int TODO_CATAPULT_COST = 2;
const int TODO_CATAPULT_UPGRADE_COST = 2;
const int TODO_CATAPULT_POWER = 5;
const int TODO_CATAPULT_RANGE = 5;

TodoCatapult::TodoCatapult(int x,int y):Tower(TODO_CATAPULT_COST,TODO_CATAPULT_UPGRADE_COST,TODO_CATAPULT_POWER),
catapultRange(TODO_CATAPULT_RANGE){
  this->setXY(x,y);
}
TodoCatapult::~TodoCatapult(){
}
bool TodoCatapult::isInRange(int x, int y) const{
  int objX=0,objY=0;
  this->getXY(objX,objY);
  int difference=abs(objX-x)+abs(objY-y);

  if(difference==catapultRange)
    return true;
  else
    return false;
}
string TodoCatapult::getName() const{
  return "Catapult";
}
char TodoCatapult::getSymbol() const{
  return 'C';
}
