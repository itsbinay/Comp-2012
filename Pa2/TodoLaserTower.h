/*
 * Laser.h
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#ifndef TODOLASERTOWER_H_
#define TODOLASERTOWER_H_

class LaserTower:public Tower(){
public:
  LaserTower();
  ~LaserTower();
  bool isInRange(int x, int y)const;
};

#endif /* TODOLASERTOWER_H_ */
