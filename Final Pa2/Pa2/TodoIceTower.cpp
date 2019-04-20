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

TodoIceTower::TodoIceTower(int x, int y):Tower(TODO_ICE_TOWER_COST,TODO_ICE_TOWER_UPGRADE_COST,TODO_ICE_TOWER_POWER){
  this->setXY(x,y);
}
TodoIceTower::~TodoIceTower(){
}
bool TodoIceTower::isInRange(int x, int y) const{
  int objX=0,objY=0;
  this->getXY(objX,objY);
  if(x>=objX)
    return true;
  else
    return false;
}
void TodoIceTower::fire(Enemy& a){
  int objX,objY;
  a.getXY(objX,objY);
  bool isDeadYet = (a.getState()==ObjectState::DEAD);
  if(isDeadYet)return;  //If it is a dead enemy, return
  else{
    //If it is in range, freeze it
    if(isInRange(objX,objY))a.setState(ObjectState::FROZEN);
  }
}

string TodoIceTower::getName()const{
  return "Ice Tower";
}
char TodoIceTower::getSymbol() const{
  return 'I';
}

void TodoIceTower::upgrade(){
  return;
}
