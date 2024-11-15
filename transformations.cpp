#include <iostream>
#include <graphics.h>
#define PI atan(1)*4
using namespace std;

struct point {
    int x;
    int y;
};

class TwoD {
public:
    void translate(point* p, point t, int a = 4) const { //translation method
        point p2[a];
        for (int i = 0; i < a; i++) {
            p2[i].x = t.x + p[i].x; // Apply translation
            p2[i].y = t.y + p[i].y; 
        }

    setcolor(RED);
    for (int i = 0; i < a; i++) {
        line(p2[i].x, p2[i].y, p2[(i + 1) % a].x, p2[(i + 1) % a].y);
    }
    delay(2000);
    }
    
    
    void scaling(point* p1,point t,int s=4) const{ //scaling method
    	point p2[s];
    	for(int i=0 ; i<s; i++){
    		p2[i].x=p1[i].x*t.x;  // Apply scaling
    		p2[i].y=p1[i].y*t.y;
    		
    	}
    	setcolor(RED);
    	for (int i = 0; i < s; i++) {
        line(p2[i].x, p2[i].y, p2[(i + 1) % s].x, p2[(i + 1) % s].y);   // Print scaling points
    }
    delay(2000);
    }
    
    
     void rotation(point* p1,int t,int s=4) const{
  	double t1=t * (PI/180);
  	double sinx=sin(t1);
  	double cosx=cos(t1);
  	point p2[s];
  	for(int i=0;i<s;i++){
  		p2[i].x=(p1[i].x*cosx)-(p1[i].y*sinx);
  		p2[i].y=(p1[i].y*cosx)+(p1[i].x*sinx);
  	}
  	setcolor(RED);
    	for (int i = 0; i < s; i++) {
        line(p2[i].x, p2[i].y, p2[(i + 1) % s].x, p2[(i + 1) % s].y);   // Print scaling points
    }
    delay(2000);
  }
};

int main() {
    int gm, gd = DETECT,r,f,n;
    point p1[n], t;
    TwoD a;
    cout<<"1.Translation\n2.Scaling\n3.Rotation\n";
    cout<<"Enter choice :";
    cin>>r;
	cout<<"Enter number of coordinates :";
	cin>>n;
    switch(r){
    case 1:
    cout << "Enter "<<n<<" coordinates :" << endl;
    for (int i = 0; i < n; i++) {
        cin >> p1[i].x >> p1[i].y;
    }

    cout << "Enter translation coordinate:" << endl;
    cin >> t.x >> t.y;

    initgraph(&gd, &gm, NULL);

    // Draw the original square
    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        line(p1[i].x, p1[i].y, p1[(i + 1) % n].x, p1[(i + 1) % n].y);
    }
    delay(1000);
    a.translate(p1, t, n); // Translate the points
   break;
    case 2:
    cout << "Enter "<<n<<" coordinates :" << endl;
    for(int i=0;i<n;i++){
    	cin>>p1[i].x>>p1[i].y;
     }
    cout<<"Enter coordinates of scaling :";
    cin>>t.x>>t.y;
    cout<<"Coordinates Are :"<<endl;
    for(int i=0;i<n;i++){
	 cout<<p1[i].x<<","<<p1[i].y<<endl;
    }
    initgraph(&gm,&gd,NULL);
    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        line(p1[i].x, p1[i].y, p1[(i + 1) % n].x, p1[(i + 1) % n].y);
    }
    delay(2000);
    a.scaling(p1,t,n); 
    break;
    case 3:
    cout << "Enter "<<n<<" coordinates :" << endl;
    for(int i=0;i<n;i++){
    cin>>p1[i].x>>p1[i].y;
    }
    cout<<"Enter angle of rotation :";
    cin>>f;
  
    cout<<"Coordinates Are :"<<endl;
   for(int i=0;i<n;i++){
   cout<<p1[i].x<<","<<p1[i].y<<endl;
   }
   initgraph(&gm,&gd,NULL);
   setcolor(WHITE);
   for (int i = 0; i < n; i++) {
   	line(p1[i].x, p1[i].y, p1[(i + 1) % n].x, p1[(i + 1) % n].y);
    }
    delay(2000);
    a.rotation(p1,f,n);
    break;
    default:
    cout<<"Invalid";
    }
    closegraph(); // Close graphics
    return 0;
}

