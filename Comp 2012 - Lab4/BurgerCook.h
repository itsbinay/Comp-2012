#ifndef BURGERCOOK_H_
#define BURGERCOOK_H_

#include "Cook.h"

class BurgerCook : public Cook{
public:
	BurgerCook(std::string _name);
	void cook_burger() const;
	void self_intro() const;
};

#endif /* BURGERCOOK_H_ */
