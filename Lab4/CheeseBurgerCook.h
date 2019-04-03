#ifndef CHEESEBURGERCOOK_H_
#define CHEESEBURGERCOOK_H_

#include "BurgerCook.h"

class CheeseBurgerCook : public BurgerCook{
public:
	CheeseBurgerCook(std::string _name);
	void cook_cheese_burger() const;
	void self_intro() const;
};

#endif /* CHEESEBURGERCOOK_H_ */
