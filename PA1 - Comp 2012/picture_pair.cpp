#include "picture.h"
#include "picture_pair.h"

Picture_Pair::Picture_Pair(const Picture_Pair& pp){
	cout<<"This function body can be entered"<<endl;
	this->pp[0]=pp.get_picture(0);
	this->pp[1]=pp.get_picture(1);
};

Picture_Pair::Picture_Pair(Picture* p1, Picture* p2){
	this->pp[0]=p1;
	this->pp[1]=p2;
};

Picture_Pair::~Picture_Pair(){
};

Picture* Picture_Pair::get_picture(int n) const{

	if(n!=0 && n!=1){
		return nullptr;
	}
	else{
		return pp[n];
	}

};
void Picture_Pair::draw() const{
	if(pp[0]!=nullptr){	//If it isn't nullptr then print out
		pp[0]->draw();
	}
	if(pp[1]!=nullptr){	//If it isn't nullptr then print out
		pp[1]->draw();
	}
};
