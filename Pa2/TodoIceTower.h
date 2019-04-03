/*
 * IceTower.h
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#ifndef TODOICETOWER_H_
#define TODOICETOWER_H_

class IceTower:public Tower{
public:
  IceTower();
  ~IceTower();
  bool isInRange(int x, int y) const;
};

#endif /* TODOICETOWER_H_ */
