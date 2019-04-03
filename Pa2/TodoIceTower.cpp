/*
 * IceTower.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#include "TodoIceTower.h"

const int TODO_ICE_TOWER_COST = 3;
const int TODO_ICE_TOWER_UPGRADE_COST = 0;
const int TODO_ICE_TOWER_POWER = 0;

IceTower::IceTower():Tower(TODO_ICE_TOWER_COST,TODO_ICE_TOWER_UPGRADE_COST,TODO_ICE_TOWER_POWER){
}
~IceTower(){
}
bool isInRange(int x, int y) const{
  int objX=0,objY=0;
  this->getXY(objX,objY);
  if(x>=objX)
    return true;
  else
    return false;
}
