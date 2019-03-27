#include "../include/chief_cook.h"

int main()
{
    Cook cook("Tom");
    ChiefCook chiefCook("Lucy");
    chiefCook.meet(cook);
}