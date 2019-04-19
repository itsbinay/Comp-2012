/*
 * RevivingEnemy.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: kevinw
 */

#include "TodoRevivingEnemy.h"
TodoRevivingEnemy::TodoRevivingEnemy(int hp, int x, int y):Enemy(hp,x,y){
}
TodoRevivingEnemy::~TodoRevivingEnemy(){
}
void TodoRevivingEnemy::fired(int power){
  this->hp-=power;
  if(hp<=0  && dead_before==false){
    this->hp=1;
    dead_before=true;
    return;
  }
  if(hp<=0 && dead_before==true)
    setState(ObjectState::DEAD);
}
char TodoRevivingEnemy::getSymbol() const{
  return 'R';
}
string TodoRevivingEnemy::getName() const{
  return "Reviving Enemy";
}
