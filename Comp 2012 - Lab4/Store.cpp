#include <iostream>
#include "Store.h"
using namespace std;

Store::Store(){}

void Store::hire(Cook& cook) const{
    cout << "The junk food store hires " << cook.get_name() << "." << endl;
    cook.self_intro();
}
