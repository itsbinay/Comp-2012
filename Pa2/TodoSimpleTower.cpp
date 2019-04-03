/*
 * LazyTower.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: kevinw
 */

#include "TodoSimpleTower.h"

const int SIMPLE_TOWER_COST = 1;
const int SIMPLE_TOWER_UPGRADE_COST = 1;
const int SIMPLE_TOWER_POWER = 3;

SimpleTower::SimpleTower():Tower(SIMPLE_TOWER_COST,SIMPLE_TOWER_UPGRADE_COST,SIMPLE_TOWER_UPGRADE_COST){}
SimpleTower::~SimpleTower(){}

bool SimpleTower::isInRange(int x, int y) const{
  int objX=0,objY=0;

  //This will get the X,Y coordinate of the object calling this function
  this->getXY(objX,objY);

  if((objX-x)==1 || (objX-x)==2)  //If the enemy is 1 or 2 step away from the obj coord
    return true;
  else
    return false;
}
