//submit this file
//you do NOT need to include any header in this file
//just write your HashTable implementation here right away

template<typename K,typename T>
HashTable<K,T>::HashTable(int m, int (*h)(K), int (*h2)(K), Mode mode, double loadLimit)
:m(m),mode(mode),h(h),h2(h2),count(0),loadLimit(loadLimit){
  this->table= new Cell[this->m];
  for(int i=0;i<m;++i){
    table[i].status=CellStatus::EMPTY;
  }
}

template<typename K,typename T>
HashTable<K,T>::HashTable(const HashTable& another){
  this->table=nullptr;
  this->m=0;
  *this=another;
}

template<typename K,typename T>
HashTable<K,T>::~HashTable(){
  for(int i=0;i<m;++i){
    if(table[i].status!=CellStatus::ACTIVE)continue;
    delete table[i].data;
    table[i].data=nullptr;  //Avoid dangling pointer
  }
  delete []table;
}
template<typename K,typename T>
HashTable<K,T>& HashTable<K,T>::operator=(const HashTable& another){
  if(this!=&another){
    if(another.table){//Make sure there is an existing another table
      if((this->table)){
        for(int i=0;i<this->m;++i){
          if(table[i].status!=CellStatus::ACTIVE)continue;
          delete table[i].data;
        }
        delete []table;
      }
      this->m=another.m;
      this->mode=another.mode;
      this->table=new Cell[m];
      for(int i=0;i<m;++i){//Copy the table
        table[i].key=another.table[i].key;
        if(another.table[i].status==CellStatus::ACTIVE){
          table[i].data=new T(*another.table[i].data); //Copy its content
        }
        table[i].status=another.table[i].status;
      }
      h=another.h;
      h2=another.h2;
      this->count=another.count;
      this->loadLimit=another.loadLimit;
    }
  }
  return *this;
}

template<typename K, typename T>
int HashTable<K,T>::add(K key,T* data){
  int cellcount=0;
  for(int i=0;i<m;++i){
    if(table[i].status!=CellStatus::EMPTY){//Count the number of active+deleted cells
      cellcount++;
    }
  }
  if(cellcount+1>m*loadLimit){//Needs rehashing
    this->m*=2;
    Cell* temptable=new Cell[m];//Double the size of the HashTable
    for(int i=0;i<m;i++){
      temptable[i].status=CellStatus::EMPTY;
    }
    switch(mode){
      case Mode::LINEAR:{
        for(int i=0;i<m/2;++i){//Go through the previous shit
          if(table[i].status!=CellStatus::ACTIVE)continue;
          //std::cout<<"for loop reached\n";
          int index=h(table[i].key);//Return index for the new table
          if(index>=m)index%=m;
          while(temptable[index].status!=CellStatus::EMPTY){
            index++;
            if(index>=m)index%=m;
          }
          //Shallow copy of table struct including owner ship of dynamic "data"
          temptable[index].data=new T(*table[i].data);
          temptable[index].key=table[i].key;
          temptable[index].status=table[i].status;
          delete table[i].data;
          //No more deleted index in the rehashed shit
        }
        delete []table;
        table=temptable;
        break;
      }
      case Mode::QUADRATIC:{
        for(int i=0;i<m/2;++i){
          if(table[i].status!=CellStatus::ACTIVE)continue;
          int orgindex=h(table[i].key),index=h(table[i].key);
          int tempcollision=0;
          if(index>=m)index%=m;
          if(orgindex>=m)orgindex%=m;
          while(temptable[index].status!=CellStatus::EMPTY){
            tempcollision++;
            index=orgindex+tempcollision*tempcollision;
            index%=m;
          }
          temptable[index].data=new T(*(this->table[i].data));
          temptable[index].key=table[i].key;
          temptable[index].status=table[i].status;
          // delete table[i].data;
        }
        for(int i = 0; i < m/2; i++){
          if(table[i].status == CellStatus::ACTIVE){
            delete table[i].data;}

        }
        delete []table;
        table=temptable;
        break;
      }
      case Mode::DOUBLE:{
        for(int i=0;i<m/2;++i){
          if(table[i].status!=CellStatus::ACTIVE)continue;
          int index=(h(table[i].key)%m),tempcollision=0;;
          while(temptable[index].status!=CellStatus::EMPTY){
            tempcollision++;
            index+=(tempcollision*(h2(table[i].key)));
            if(index>=m)index%=m;
          }
          temptable[index].data=new T(*(this->table[i].data));
          temptable[index].key=table[i].key;
          temptable[index].status=table[i].status;
          delete table[i].data;
        }
        delete []table;
        table=temptable;
        break;
      }
    }
  }
  //After rehashing or without rehashing
  switch(mode){
    case Mode::LINEAR:{
      int index=h(key); //Will return index
      if(index>=m)
        index%=m;
      int collision=0;
      //std::cout<<"index:"<<index<<"\n";
      while(table[index].status!=CellStatus::EMPTY){
        //If the current index's status is empty, wont enter this while loop
        index++;
        collision++;
        if(index==m)index-=m; //starts back to zero
        if(collision>=m)return -1;
      }
      count++;
      table[index].key=key;
      table[index].data=data;
      table[index].status=CellStatus::ACTIVE;
      return collision;
      break;
    }
    case Mode::QUADRATIC:{
      int orgindex=h(key),index=h(key);
      int collision=0;
      if(index>=m)index%=m;
      while(table[index].status!=CellStatus::EMPTY){
        collision++;
        index=orgindex+collision*collision;
        if(index>=m)index%=m;
        if(collision>=m)return -1;
      }
      count++;
      table[index].key=key;
      table[index].data=data;
      table[index].status=CellStatus::ACTIVE;
      return collision;
      break;
    }
    case Mode::DOUBLE:{
      int index=h(key),collision=0;
      if(index>=m)index%=m;
      while(table[index].status!=CellStatus::EMPTY){
        collision++;
        index+=(collision*(h2(key)%m));
        if(index>=m)index%=m;
        if(collision>=m)return -1;
      }
      count++;
      table[index].key=key;
      table[index].data=data;
      table[index].status=CellStatus::ACTIVE;
      return collision;
      break;
    }
  }
}

template<typename K,typename T>
T* HashTable<K,T>::get(K key)const{
  switch(this->mode){
    case Mode::LINEAR:
    {
      int index=h(key);
      //index is empty
      if(index>=m)index%=m;
      if(table[index].status==CellStatus::EMPTY)return nullptr;
      while(table[index].key!=key){
        index++;
        if(index>=m)index%=m;
        //Cannot find until the index is empty
        if(table[index].status==CellStatus::EMPTY)return nullptr;
      }
      //Return the corresponding index's data
      return table[index].data;
      break;
    }
    case Mode::QUADRATIC:
    {
      int orgindex=h(key)%m,index=h(key)%m,collision=0;
      if(table[index].status==CellStatus::EMPTY)return nullptr;
      while(table[index].key!=key){
        collision++;
        index=orgindex+(collision*collision);
        index%=m;
        if(table[index].status==CellStatus::EMPTY)return nullptr;
      }
      return table[index].data;
      break;
    }
    case Mode::DOUBLE:
    {
      int index=h(key),collision=0;
      index%=m;
      if(table[index].status==CellStatus::EMPTY)return nullptr;
      while(table[index].key!=key){
        collision++;
        index+=(collision*(h2(key)%m));
        index%=m;
        if(table[index].status==CellStatus::EMPTY)return nullptr;
      }
      return table[index].data;
      break;
    }
  }
}

template<typename K, typename T>
bool HashTable<K,T>::remove(K key){
  switch(this->mode){
    case Mode::LINEAR:{
      int index=h(key);
      if(index>=m)index%=m;
      if(table[index].status==CellStatus::EMPTY)return false; //index is empty
      while(table[index].key!=key){
        index++;
        if(index>=m)index%=m;
        //Cannot find until the index is empty
        if(table[index].status==CellStatus::EMPTY)return false;
      }
      delete table[index].data;
      table[index].status=CellStatus::DELETED;
      this->count--;
      return true;
      break;
    }
    case Mode::QUADRATIC:{
      int orgindex=h(key)%m,index=h(key)%m,collision=0;
      if(table[index].status==CellStatus::EMPTY)return false;
      while(table[index].key!=key){
        collision++;
        index=orgindex+(collision*collision);
        index%=m;
        if(table[index].status==CellStatus::EMPTY)return false;
      }
      delete table[index].data;
      table[index].status=CellStatus::DELETED;
      this->count--;
      return true;
      break;
    }
    case Mode::DOUBLE:{
      int index=h(key),collision=0;
      index%=m;
      if(table[index].status==CellStatus::EMPTY)return false;
      while(table[index].key!=key){
        collision++;
        index+=(collision*(h2(key)%m));
        index%=m;
        if(table[index].status==CellStatus::EMPTY)return false;
      }
      delete table[index].data;
      table[index].status=CellStatus::DELETED;
      this->count--;
      return true;
      break;
    }
  }
}
