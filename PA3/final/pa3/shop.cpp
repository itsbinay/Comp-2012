//submit this file

#include "shop.h"

Shop::Shop(string name,int m, int (*h)(string),int (*h2)(string),Mode mode, double loadLimit):
name(name),profit(0){
  inventory=new HashTable<string,Product>(m,h,h2,mode,loadLimit);
}

Shop::Shop(const Shop& another){
  this->inventory=nullptr;
  this->name=another.name;
  this->profit=another.profit;
  this->inventory=new HashTable<string,Product>(*another.inventory);
}

Shop::Shop(Shop&& another)
    : name(another.name), profit(another.profit), inventory(another.inventory)
{
    another.name = "moved";
    another.inventory = nullptr;
}
Shop::~Shop(){
  delete inventory;
}

Shop& Shop::operator=(const Shop& another){
  if(this!=&another){
    if(this->inventory){//if there is an existing inventory
      delete inventory;
    }
    this->name=another.name;
    this->profit=another.profit;
    this->inventory=new HashTable<string,Product>(*another.inventory);
  }

  return *this;
}

bool Shop::addProduct(string name, int quantity,int price){
  if(!inventory->get(name)){ //If can't find such a product in hashtable
    if(inventory->add(name,new Product(name,quantity,price))!=-1){
      return true;
    }else{
      return false;
    }
  }else{
    //Increase the product quantity regardless of the price
    inventory->get(name)->add(quantity);
    return true;
  }
}

bool Shop::sellProduct(string name, int quantity){
  if(!inventory->get(name))return false;
  else{
    if(inventory->get(name)->getQuantity()<=0)return false;
    else{
      profit+=(inventory->get(name)->getPrice()*quantity);
      inventory->get(name)->take(quantity);
      if(inventory->get(name)->getQuantity()==0){
        inventory->remove(name);
      }
      return true;
    }
  }
}
