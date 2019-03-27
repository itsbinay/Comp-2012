#include "../include/chief_cook.h"

using namespace std;

ChiefCook::ChiefCook(string name) : Cook(name)
{
}

void ChiefCook::meet(const Cook &cook) const
{
    says_to(cook, "Hey man, how's going?");
}
