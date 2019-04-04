#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
class myvector {
private:
    T* data {nullptr};
    int size {0};
    int capacity {0};

    // TODO: double_cap
    void double_cap(void){
      if(this->capacity==0)return;
      this->capacity*=2;  //Double the maximum capacity
      T* new_arr=new T[this->capacity];
      //Deep copy all of the elements from the existing vector
      for(int i=0;i<this->size;++i){
        new_arr[i]=data[i];
      }
      delete []data;
      this->data=new_arr;
      new_arr=nullptr;
    }

    // TODO: halve_cap
    void halve_cap(void){
      if(this->capacity==0)return;
      this->capacity/=2;
      T* new_arr=new T[this->capacity];

      for(int i=0;i<this->size;++i){
        new_arr[i]=data[i];
      }
      delete []data;
      data=new_arr;
      new_arr=nullptr;
    }

    std::string str() const {
        std::ostringstream os;
        os << "[";
        if (size != 0) {
            os << data[0];
            for (int i=1; i<size; i++) {
                os << " " << data[i];
            }
        }
        os << "] size: " << size << " capacity: " << capacity;
        return os.str();
    }

public:
    myvector() = default;

    myvector(const myvector<T>& other) {
        *this = other;
    }

    ~myvector() {delete [] data;}

    int get_size() const {return size;}

    // TODO: pop_back
    T pop_back(void){
      //if(this->capacity==0 || this->size==0)return;
      size-=1;
      if(this->size<=this->capacity/4){
        halve_cap();
      }
      return data[this->size];
    }
    // TODO: push_back
    void push_back(const T& a){
      if(this->capacity==0 ){
        this->capacity=1;
        data=new T[1];
        *data=a;
      }
      if(this->size>=capacity){
        double_cap();
      }
      data[this->size]=a;
      this->size+=1;
    }

    // TODO: operator=
  const myvector<T>& operator=(const myvector<T>& other) {
    T* temp=new T[other.capacity];
    size=other.size;
    capacity=other.capacity;
    for(int i=0;i<size;i++){
      temp[i]=other.data[i];
    }
    delete [] data;
    data=temp;
    return *this;
  };
   // TODO: pre-increment operator++
  myvector& operator++() {
    for(int i=0;i<size;i++){
     data[i]++;
    }
    return *this;
  }
   // TODO: post-increment operator++
  myvector operator++(int){
    myvector temp(*this);
    ++(*this);
    return temp;
  }
   // TODO: member operator*
  myvector operator*(const T& n){
    myvector V=*this;
    for(int i=0;i<size;i++){
      V[i]=V[i]*n;
    }
    return V;
  }
    // TODO: RW operator[]
  T& operator[](int j){
    return data[j];
  }
    // TODO: operator==
  bool operator==(const myvector<T>& other){
    if(this->size!=other.size){
    	return false;
    }
    else{
    	for(int i=0;i<size;i++){
    	  if(this->data[i]!=other.data[i]){
    	    return false;
    	  }
    	}
    }
    return true;
  }
    // TODO: operator<<
  friend std::ostream& operator<<(std::ostream& os,const myvector& op){
    os<< op.str();
    return os;
  }
    // TODO: non-member operator*
  friend myvector operator*(const T& n, const myvector& op){
    myvector V=op;
  	for(int i=0;i<op.size;i++){
    	V[i]=V[i]*5;
    }
    return V;
  }
};


#endif //VECTOR_H
