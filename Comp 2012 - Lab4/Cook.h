#ifndef COOK_H_
#define COOK_H_
#include <iostream>

class Cook{
private:
    std::string name;
public:
	Cook(std::string _name);
	std::string get_name() const;
	void self_intro() const;
};

#endif /* COOK_H_ */
