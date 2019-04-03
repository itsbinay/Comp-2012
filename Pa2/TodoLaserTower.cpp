/*
 * Laser.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#include "TodoLaserTower.h"

const int LASER_COST = 3;
const int LASER_UPGRADE_COST = 2;
const int LASER_POWER = 10;

LaserTower::LaserTower():Tower(LASER_COST,LASER_UPGRADE_COST,LASER_POWER){
}
LaserTower::~LaserTower(){
}
bool LaserTower::isInRange(int x, int y)const{
  int objX=0,objY=0;
  this->getXY(objX,objY);
  if(objX==x || objY==y)
    return true;
  else
    return false;
}
