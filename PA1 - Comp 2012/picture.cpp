#include "picture.h"

const char SPACE = ' ';


// Reads a char from ifstream
// Includes space but excludes newline
// Useful for reading character pictures
char get_ch(ifstream &in)
{
	char c = '\0';
	while (in >> noskipws >> c && c == '\n')
		;

	return c;
}
//------------------------------------------------------------------------------
Picture::Picture(const Picture& p){ //Copy Constructor
    //Copy the data members first
    this->width=p.width;
    this->height=p.height;
    
    pix=new char*[this->height];
    
    for(int i=0;i<this->height;i++){
       this-> pix[i]=new char[this->width];
    }
    
    for(int row=0;row<this->height;row++){
        for(int col=0;col<this->width;col++){
            this->pix[row][col]=p.pix[row][col];    //Copy the content into the new 2 dimensional array
        }
    }
}
//------------------------------------------------------------------------------
Picture::Picture(const char* filename){
    ifstream ifs(filename); // open the file of name filename(string)
    if(!ifs){cerr<<"Error: Can't open \""<<filename<<"\"\n";exit(1);}

    int tempwidth,tempheight;
    ifs>>tempheight>>tempwidth;
    //Initialising the datamember of the class object using data member asignment
    this->width=tempwidth;
    this->height=tempheight;

    //Initilaise the 2D pointer Array
    pix = new char*[this->height];//Create n(height) rows of char pointers
    
    for(int i=0;i<this->height;i++){//For each row, create m(width) column of char
    	pix[i]=new char[this->width];
    }
    
    for(int row=0;row<this->height;row++){
    	for(int col=0;col<this->width;col++){
    		pix[row][col]=get_ch(ifs);
    	}
    }

}
//------------------------------------------------------------------------------
Picture::Picture(const Picture_Pair& pp){
    if(pp.get_picture(0)==nullptr && pp.get_picture(1)==nullptr){	//Create a blank picture using default values
    	return;
    }
    else if(pp.get_picture(0)==nullptr){
    	this->height=(pp.get_picture(1))->height;
    	this->width=(pp.get_picture(1))->width;

    	pix=new char*[height];
    	for(int i=0;i<height;i++){
    		pix[i]=new char[width];
    	}

    	for(int row=0;row<height;row++){
    		for(int col=0;col<width;col++){
    			this->pix[row][col]=(pp.get_picture(1))->pix[row][col];
    		}
    	}
    }
    else if(pp.get_picture(1)==nullptr){
    	this->height=(pp.get_picture(0))->height;
    	this->width=(pp.get_picture(0))->width;

    	pix=new char*[height];
    	for(int i=0;i<height;i++){
    	    pix[i]=new char[width];
    	}

    	for(int row=0;row<height;row++){
    	   for(int col=0;col<width;col++){
    		   this->pix[row][col]=(pp.get_picture(0))->pix[row][col];
    	   }
    	}
    }
    else{
    	//Get the maximum height
    	for(int i=0;i<2;i++){
    		if(this->height<=(pp.get_picture(i))->height){
    			this->height=pp.get_picture(i)->height;
    		}
    	}
    	//Maximum width= combination of the width of the two pictures
    	this->width=(pp.get_picture(0)->width)+(pp.get_picture(1)->width);

    	pix=new char*[height];
    	for(int i=0;i<height;i++){
    		pix[i]=new char[width];
    	}

    	//Updating the first picture into the new pix
    	for(int row=0;row<height;row++){
    		if(row<pp.get_picture(0)->height){
    			for(int col=0;col<pp.get_picture(0)->width;col++){
    				pix[row][col]=pp.get_picture(0)->pix[row][col];
    			}
    		}
    		else{
    			for(int col=0;col<pp.get_picture(0)->width;col++){
    				pix[row][col]=SPACE;
    			}
    		}
    	}

    	for(int row=0;row<height;row++){
    		if(row<pp.get_picture(1)->height){
    			for(int col=pp.get_picture(0)->width;col<width;col++){
    				pix[row][col]=pp.get_picture(1)->pix[row][col-pp.get_picture(0)->width];

    			}
    		}
    		else{
    			for(int col=pp.get_picture(0)->width;col<width;col++){
    				pix[row][col]=SPACE;
    			}
    		}
    	}


    }

}
//------------------------------------------------------------------------------
void Picture::draw()const{
	for(int row=0;row<this->height;row++){
		for(int col=0;col<this->width;col++){
			cout<<pix[row][col];
		}
		cout<<endl;	//Newline after every row of output
	}
}
//------------------------------------------------------------------------------
void Picture::frame(char symbol,int frame_width){
	if(frame_width<=0){	//Exit the function if the frame width is too small
		return;
	}
	else{

		char ** temp{nullptr};
		temp=new char*[height+frame_width*2];
		for(int i=0;i<(height+frame_width*2);i++){
			temp[i]=new char[width+frame_width*2];
		}

		//Deep copy of the element
		for(int row=0;row<(height+frame_width*2);row++){
			for(int col=0;col<(width+frame_width*2);col++){
				if(row<frame_width || row>=(height+frame_width)){//For the first(n-frame width) rows and the last rows
					temp[row][col]=symbol;
				}
				else if(col<frame_width || col>=(width+frame_width)){
					temp[row][col]=symbol;
				}
				else{
					temp[row][col]=pix[row-frame_width][col-frame_width];
				}
			}
		}

		//Deallocate the old memory
		for(int row=0;row<this->height;row++){
		    delete []pix[row];
		    pix[row]=nullptr;
		}

		delete []pix;

		//Allocate the frame memory to pix
		pix=temp;
		temp=nullptr;

		//Update the class's height and width
		height=height+frame_width*2;
		width=width+frame_width*2;
	}
}
//------------------------------------------------------------------------------
Picture::~Picture(){    //Destructor
	//Ensure all of objects the pointers are pointing to is deleted first
    for(int row=0;row<this->height;row++){
    	delete []pix[row];
    	pix[row]=nullptr;
    }

    delete []pix;	//Delete the entire 2D array
}
