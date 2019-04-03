/*
 * Catapult.h
 *
 *  Created on: Mar 12, 2019
 *      Author: kevinw
 */

#ifndef TODOCATAPULT_H_
#define TODOCATAPULT_H_

#include "Tower.h"
class Catapult:public Tower{
public:
  Catapult();
  ~Catapult();
  bool isInRange(int x, int y) const;
private:
  int catapultRange;
};

#endif /* TODOCATAPULT_H_ */
