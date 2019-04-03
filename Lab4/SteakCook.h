#ifndef STEAKCOOK_H_
#define STEAKCOOK_H_

#include "Cook.h"

class SteakCook : public Cook{
public:
	SteakCook(std::string _name);
	void cook_steak() const;
	void self_intro() const;
};

#endif /* STEAKCOOK_H_ */
