#include "../include/boss.h"

using namespace std;

Boss::Boss(string name) : Person(name)
{
}

void Boss::meet(const Cook &cook) const
{
	cout<<"Function body has been entered"<<endl;
    says_to(cook, "Work harder or you will get fired!");
}
