//submit this file

#include "mall.h"
#include <string>

Mall::Mall(string name):name(name){
}
int alphabhetreturn(char x){
  if(x>=65 && x<=90){//Uppercase letters
    return int(x)-64;
  }else if(x>=97 && x<=122){
    return int(x)-96;
  }else{
    return -1;
  }
}

bool Mall::demolishShop(string name){
  shops.remove(name);
}

Shop* Mall::getShop(string name){
  return shops.get(name);
}

void Mall::mergeMall(Mall& another, string newName){
  shops.merge(another.shops);
  this->name=newName;
}

int (*method3)(string)=[](string a){
  int length=a.length();
  int key=0;
  for(int i=0;i<length;++i){
    key+=((37^(length-1-i))*alphabhetreturn(a.at(i)));
  }
  return key;
}
bool Mall::buildShop(string name){
  if(getShop(name)){return false;}
  else{ //Shop with "name" doesn't exist

    Shop newshop=Shop(name,7,method3,method3,Mode::LINEAR,0.5);
    shops.add(name,newshop);//New shop added
    return true;
  }
}
