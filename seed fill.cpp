//Siddhesh Gite
/*
Write C++ program to draw a concave polygon and fill it with desired color
using Seed Fill /Scan LineFill algorithm.
*/
#include<iostream>
#include<graphics.h>
using namespace std;
class polygon1{
	private:
		int i,x,y,b1,c1;
	public:
	int b[10],c[10];
	int a;
	polygon1():a(0){}
		void setValue(int newValue) {
       			 a = newValue; // Assign newValue to member variable value
   		 }
	
		void input(){
			int a,i;
			cout<<"Enter no. of point(0 to 10) :";
			cin>>a;
			if(a>10){
				cout<<"Maxmium 10 Points is allowed ."<<endl;
			}
			setValue(a);
			cout<<"Enter pixels(x,y) :";
			for(i=0;i<a;i++){
				cin>>b[i]>>c[i];
			b1=b[a];
			c1=c[a];
				
			}
		}
		void draw()const{
			for(int i=0;i<a-1;i++){
				line(b[i],c[i],b[i+1],c[i+1]);	
			}
			line(b[a-1],c[a-1],b[0],c[0]);
		}
		
		 

    // Function to calculate the centroid
   		 void calculateCentroid(int& x, int& y) const {
   		  int sum=0;
   		  for(int i=0;i<a;i++){
   		  	sum+=b[i];
   		  }
   		  x =sum/a;// Average of array b
   		   sum=0;
   		  for(int i=0;i<a;i++){
   		  	sum+=c[i];
   		  }
      		  y = sum/a; // Average of array c
  		  }
		
};

class fill1:public polygon1{
private:
int a,b,fill,old,bound;
public:
void flood(int a,int b,int fill, int old){
	if(getpixel(a,b)==old){
		putpixel(a,b,fill);
		//delay(2);
		flood(a+1,b,fill,old);
		flood(a,b+1,fill,old);
		flood(a-1,b,fill,old);
		flood(a,b-1,fill,old);
	}
}
void boundary4(int a,int b,int fill,int bound){
	
		if(getpixel(a,b)!= bound && getpixel(a,b)!=fill){
		putpixel(a,b,fill);
		//delay(2);
		boundary4(a+1,b,fill,bound);
		boundary4(a,b+1,fill,bound);
		boundary4(a-1,b,fill,bound);
		boundary4(a,b-1,fill,bound);
		}
		}
};	

	
int main(){
	int gd=DETECT,gm,x,y,a,z;
	//polygon1 p;
	fill1 p;
	p.input();
	cout<<"Enter choice (1: Boundary fill and 2:Flood fill):";
	cin>>a;
    cout << "Black = 0" << endl;
    cout << "Blue = 1" << endl;
    cout << "Green = 2" << endl;
    cout << "Cyan = 3" << endl;
    cout << "Red = 4" << endl;
    cout << "Magenta = 5" << endl;
    cout << "Brown = 6" << endl;
    cout << "Light Gray = 7" << endl;
    cout << "Dark Gray = 8" << endl;
    cout << "Light Blue = 9" << endl;
    cout << "Light Green = 10" << endl;
    cout << "Light Cyan = 11" << endl;
    cout << "Light Red = 12" << endl;
    cout << "Light Magenta = 13" << endl;
    cout << "Yellow = 14" << endl;
    cout << "White = 15" << endl;
    cout<<"Enter color-code to be filled :";
    cin>>z;
	p.calculateCentroid(x,y);
	initgraph(&gd,&gm,NULL);
	p.draw();
	delay(200);
	switch(a){
	case 1: p.boundary4(x,y,z,WHITE);
	delay(2000);
	break;
	case 2: p.flood(x,y,z,BLACK);
	delay(2000);
	break;
	default:cout<<"Enter valid choice"<<endl;
	break;
	};
	delay(2000);
	closegraph();
	return 0;
}
