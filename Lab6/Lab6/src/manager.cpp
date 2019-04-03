#include "../include/manager.h"

using namespace std;

Manager::Manager(string name) : Person(name)
{
}

void Manager::meet(const Cook &cook) const
{
    says_to(cook, "Would you like to go to cinema with me tonight?");
}
