#include "../include/cook.h"

int main()
{
    Cook cook("Tom");
    Cook cook2("Jack");
    cook2.meet(cook);
}