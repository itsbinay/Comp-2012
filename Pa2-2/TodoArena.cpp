/*
 * Arena.cpp
 *
 *  Created on: Feb 25, 2016
 *      Author: kevinw
 */

#include "Arena.h"

#include "Enemy.h"
#include "TodoCatapult.h"
#include "TodoDiagonalEnemy.h"
#include "TodoIceTower.h"
#include "TodoLaserTower.h"
#include "TodoRevivingEnemy.h"
#include "TodoSimpleTower.h"

const int ARENA_W = 45;
const int ARENA_H = 5;
const int TOWER_X = 35;
const int ENEMY_X = 0;




Arena::~Arena() {
//TODO
	for(int i=0;i<num_objects;++i){
		delete this->objects[i];
	}
	delete[]this->objects;
}

//Perform shallow copying and add this object to the array objects.
//The ownership of this object is transfered to Arena.
void Arena::addObject(Object* newobj) {
//TODO
	Object** temp=new Object*[num_objects+1];//Create thew new dynamic array
	for(int i=0;i<num_objects;++i){
		temp[i]=this->objects[i];
	}
	delete []objects;
	temp[num_objects]=newobj;	//Shallow copy of the object being trasnferred
	num_objects++;
	this->objects=temp;
}

//To return a dynamic const Object array. You might treat the memory
//pointed by obj is garbage.
void Arena::getConstObjects(const Object**& obj, int& count) const {
//TODO
	count=this->num_objects;
	obj = new const Object*[count];
	for (int i = 0; i < count; ++i){
		obj[i] = this->objects[i];
	}
}

//Return the object in the array objects with the coordinate aX and aY.
//If there are more than one object is in this coordinate, return any
//one of them. If there are no object is in this coordinate, return nullptr
Object* Arena::getObjectAt(int aX, int aY) const {
//TODO
	for(int i=0;i<num_objects;++i){
		int objX,objY;
		this->objects[i]->getXY(objX,objY);
		if(objX==aX && objY==aY){
			return objects[i];
		}
	}
	return nullptr;

}

//Return true if the game is over, false otherwise.
//The game is over when any not DEAD enemy reaches the end-zone - i.e., its
//x-coordinate >= the constant TOWER_X.
bool Arena::isGameOver() const {
//TODO
	for(int i=0;i<num_objects;++i){
		int objX,objY;
		this->objects[i]->getXY(objX,objY);
		//if any enemy
		if(objX>=TOWER_X && (this->objects[i]->getObjectType()==ObjectType::ENEMY
		&& this->objects[i]->getState()!=ObjectState::DEAD))return true;
	}
	return false;
}


//Remove the object pointed by the pointer r from the array objects if it is
//in the list. Do nothing if r is a nullptr or r is not in the array.
void Arena::removeObject(Object* r) {
//TODO
	int deletedIndex,index=0,CurIndex=0;
	bool deleted=false;
	if(r!=nullptr){
		for(int i=0;i<num_objects;++i){	//Check if r is in the array
			if(objects[i]==r){	//Only if r pointer exits
				delete this->objects[i];
				deleted=true;
				deletedIndex=i;
				break;
			}
		}
		if(deleted){
			Object** temp=new Object*[num_objects-1];
			while(CurIndex!=num_objects){	//Loop to shallow copy the obejct
				if(CurIndex==deletedIndex){
					CurIndex++;
					continue;
				}
				temp[index]=objects[CurIndex];	//Shallow copy
				++index;
				++CurIndex;
			}
			delete []objects;
			objects=temp;
			--num_objects;
		}
	}
}


//Depends on the value of the variable building, construct a tower at the coordinate x, y when money is larger than the building cost.
// if building is SIMPLE_TOWER - construct a TodoSimpleTower
// if building is CATAPUL_TOWER - construct a TodoCatapult
// if building is LASER_TOWER - construct a TodoLaserTower
// if building is ICE_TOWER - construct a TodoIceTower
// otherwise - do nothing.
// After building the tower, deduct the money by the building cost of the tower
void Arena::addBuilding(int building, int x, int y) {
//TODO
	if(getObjectAt(x,y)==nullptr){ //If there is no object
		switch(building){
			case 0:{
				TodoSimpleTower * temp=new TodoSimpleTower(x,y);
				if(this->money>temp->getCost()){
					addObject(temp);
					this->money-=temp->getCost();
				}else{
					delete temp;
				}
				break;
			}
			case 1:{
				TodoCatapult * temp= new TodoCatapult(x,y);
				if(this->money>temp->getCost()){
					addObject(temp);
					this->money-=temp->getCost();
				}else{
					delete temp;
				}
				break;
			}
			case 2:{
				TodoLaserTower * temp = new TodoLaserTower(x,y);
				if(this->money>temp->getCost()){
					addObject(temp);
					this->money-=temp->getCost();
				}else{
					delete temp;
				}
				break;
			}
			case 3:{
				TodoIceTower* temp= new TodoIceTower(x,y);
				if(this->money>temp->getCost()){
					addObject(temp);
					this->money-=temp->getCost();
				}else{
					delete temp;
				}
				break;
			}
		}
	}
}


//This function would first make all tower fires (if there is
//at least one enemy in its range). By default, the tower will select
//the nearest enemy to shoot. If there are more than one nearest enemies,
//pick anyone of them (we would not test this case during grading).
//
//Next all enemies are going to move. Remember that an enemy in the state
//FROZEN or DEAD cannot move.
//
//Next you need to generate one new Enemy by calling the function genereateEnemy().
// The function generateEnemy has been written for you already.
//
//Finally you need to clean up all DEAD enemy and tower that was destroyed by enemy in this turn.
//
//The amount of money will be increased by the enemies killed in this turn.
//(*noted: if a RevivingEnemy revive, money will not be added)
void Arena::nextRound() {
//TODO
	/*** The following code is to make the tower shoot - STEP1 ***/
	for(int i=0;i<this->num_objects;++i){//Make the tower shoot first
		//This is done to find the tower first
		if(this->objects[i]->getObjectType()==ObjectType::ENEMY)return;
		for(int j=0;j<this->num_objects;++j){
			if((i==j) || this->objects[j]->getObjectType()==ObjectType::TOWER || this->objects[j]==nullptr)continue;
			int objX,objY;
			this->objects[j]->getXY(objX,objY);
			if(dynamic_cast<Tower*>(this->objects[i])->isInRange(objX,objY)){
				dynamic_cast<Tower*>(this->objects[i])->fire(*dynamic_cast<Enemy*>(this->objects[j]));
				break;
			}
		}
	}

	/*** The following code is to make the enemy move - STEP2 ***/
	for(int i=0;i<this->num_objects;++i){
		if(this->objects[i]->getObjectType()==ObjectType::TOWER)continue;
		dynamic_cast<Enemy*>(this->objects[i])->move();
	}

	/*** Generate one new Enemy - STEP3 ***/
	generateEnemy();

	/*** Clean up all of the dead enemy and tower that was destroyed by the enemy ***/
	for(int i=0;i<this->num_objects;++i){ //Remove Enemy
		//If it isn't an enemy
		if(this->objects[i]==nullptr)continue;

		if(this->objects[i]->getObjectType()==ObjectType::ENEMY){
			if(this->objects[i]->getState()==ObjectState::DEAD)this->removeObject(this->objects[i]);
		}
		else if(this->objects[i]->getObjectType()==ObjectType::TOWER){
			int TowX,TowY;
			this->objects[i]->getXY(TowX,TowY);
			for(int j=0;j<this->num_objects;++j){
				if(this->objects[j]->getObjectType()!=ObjectType::ENEMY)continue;
				int objX,objY;
				this->objects[j]->getXY(objX,objY);
				if(objX==TowX && objY==TowY){
					removeObject(this->objects[i]);
					break;
				}
			}
		}
	}

}


//Completed
bool Arena::upgrade(Tower* t) {
	if (t == nullptr || money < t->getUpgradeCost())
		return false;
	money -= t->getUpgradeCost();
	t->upgrade();
	return true;
}

//Completed
void Arena::generateEnemy() {
	int i = rand() % ARENA_H;
	Enemy* e;
	switch (rand() % 3) {
	case 0: e = new Enemy(5, ENEMY_X, i); break;
	case 1: e = new TodoDiagonalEnemy(6, ENEMY_X, i); break;
	case 2: e = new TodoRevivingEnemy(10, ENEMY_X, i); break;
	}
	addObject(e);

}

//Completed
Arena::Arena() : objects(nullptr), num_objects(0), money(10), enemy_kill(0) {
	nextRound();
}
