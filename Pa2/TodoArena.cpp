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
}

//Perform shadow copying and add this object to the array objects.
//The ownership of this object is transfered to Arena.
void Arena::addObject(Object* newobj) {
//TODO
}

//To return a dynamic const Object array. You might treat the memory
//pointed by obj is garbage.
void Arena::getConstObjects(const Object**& obj, int& count) const {
//TODO
}

//Return the object in the array objects with the coordinate aX and aY.
//If there are more than one object is in this coordinate, return any
//one of them. If there are no object is in this coordinate, return nullptr 
Object* Arena::getObjectAt(int aX, int aY) const {
//TODO
	return nullptr;

}

//Return true if the game is over, false otherwise.
//The game is over when any not DEAD enemy reaches the end-zone - i.e., its
//x-coordinate >= the constant TOWER_X.
bool Arena::isGameOver() const {
//TODO
	return false;
}


//Remove the object pointed by the pointer r from the array objects if it is 
//in the list. Do nothing if r is a nullptr or r is not in the array.
void Arena::removeObject(Object* r) {
//TODO
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
}


//This function would first make all tower fires (if there is 
//at least one enemy in its range). By default, the tower will select 
//the nearest enemy to shoot. If there are more than one nearest enemies,
//pick anyone of them (we would not test this case during grading).
//
//Next all enemies are going to move. Remember that an enemy in the state
//FROZEN or DEAD cannot move.  
//
//Next you need to generate one new Enemy by calling the function genereateEnemy(). The function generateEnemy has been written for you already.
//
//Finally you need to clean up all DEAD enemy and tower that was destroyed by enemy in this turn.
//
//The amount of money will be increased by the enemies killed in this turn.
//(*noted: if a RevivingEnemy revive, money will not be added) 
void Arena::nextRound() {
//TODO

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
