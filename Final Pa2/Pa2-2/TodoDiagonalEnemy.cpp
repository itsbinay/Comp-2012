/*
 * DiagonalEnemy.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: kevinw
 */

#include "TodoDiagonalEnemy.h"

TodoDiagonalEnemy::TodoDiagonalEnemy(int hp,int x,int y):Enemy(hp,x,y){
  if(y<0) //If the initial y_coord is less than 0
    changeDIR=false;
  else
    changeDIR=true;
}

TodoDiagonalEnemy::~TodoDiagonalEnemy(){
}

void TodoDiagonalEnemy::move(){
  int objX,objY;
  if(getState() == ObjectState::DEAD){
    return;
  }
  if(getState() == ObjectState::FROZEN){
    setState(ObjectState::NORMAL);
    return;
  }
  getXY(objX,objY);
  if(objY<0 && !changeDIR){ //And hasn't changed direction
    setXY(objX+1,objY-1);
    if(objY+1==0)changeDIR=true;  //Change direction
  }else{
    setXY(objX+1,objY+1);
    if(objY-1==ARENA_H)changeDIR=false;
  }
}

char TodoDiagonalEnemy::getSymbol() const{
  return 'D';
}
