/*
 * Catapult.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: kevinw
 */

#include "TodoCatapult.h"

const int TODO_CATAPULT_COST = 2;
const int TODO_CATAPULT_UPGRADE_COST = 2;
const int TODO_CATAPULT_POWER = 5;
const int TODO_CATAPULT_RANGE = 5;

Catapult::Catapult():Tower(TODO_CATAPULT_COST,TODO_CATAPULT_UPGRADE_COST,TODO_CATAPULT_POWER){
}
Catapult::~Catapult(){
}
bool Catapult::isInRange(int x, int y) const{
  int objX=0,objY=0;
  this->getXY(objX,objY);
  int difference=objX-x;
  difference+=(objY-y);

  if(difference>=TODO_CATAPULT_RANGE)
    return true;
  else
    return false;
}
