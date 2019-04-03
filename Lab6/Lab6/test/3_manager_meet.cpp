#include "../include/manager.h"
#include "../include/cook.h"

int main()
{
    Cook cook("Tom");
    Manager manager("Marry");
    manager.meet(cook);
}