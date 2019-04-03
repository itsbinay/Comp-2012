#include "../include/cook.h"

using namespace std;

Cook::Cook(string name) : Person(name)
{
}

void Cook::meet(const Cook &cook) const
{
    says_to(cook, "Have you eaten yet?");
}
