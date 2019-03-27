#include "../include/boss.h"
#include "../include/cook.h"
#include "../include/manager.h"
int main()
{
    Cook cook("Tom");
    Boss boss("John");
    Manager manager("Kash");
    boss.meet(cook);
}
