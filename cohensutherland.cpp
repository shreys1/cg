//Siddhesh Gite
/*
Write a menu driven C++ program to implement Cohen Southerland line clipping
algorithm by accepting a window and a line to be clipped against it.
*/
#include <graphics.h>
#include <iostream>
using namespace std;
#define TOP    1 // 0001
#define BOTTOM 2 // 0010
#define RIGHT  4 // 0100
#define LEFT   8 // 1000

struct Rectangle {
    int x_min, y_min, x_max, y_max;
    
    friend istream& operator>>(istream& is,Rectangle &r){
    is >>r.x_min>> r.y_min>> r.x_max>> r.y_max;
    return is;
    }
    friend ostream& operator<<(ostream& os,const Rectangle &r){
    os<<"A :"<<r.x_min<<","<<r.y_max<<endl;
    os<<"B :"<<r.x_max<<","<<r.y_max<<endl;
    os<<"C :"<<r.x_max<<","<<r.y_min<<endl;
    os<<"D :"<<r.x_min<<","<<r.y_min<<endl;
    return os;
    }
    
};

struct line1{
	int x1;
	int x2;
	int y1;
	int y2;
	friend istream& operator>>(istream& is,line1 &r){
    		is >>r.x1>> r.y1>> r.x2>> r.y2;
    		return is;
    		
    	}
    	
};
void line(const line1 &l){
	line(l.x1,l.y1,l.x2,l.y2);
}
// Function to compute the region code for a point
int computeRegionCode(double x, double y, const Rectangle &rect) {
    int code = 0;
    if (x < rect.x_min)      // to the left of the rectangle
        code |= LEFT;
    else if (x > rect.x_max) // to the right of the rectangle
        code |= RIGHT;
    if (y < rect.y_min)      // below the rectangle
        code |= BOTTOM;
    else if (y > rect.y_max) // above the rectangle
        code |= TOP;
    return code;
}

// Cohen-Sutherland Line Clipping Algorithm
void cohenSutherlandClip(double x0, double y0, double x1, double y1, const Rectangle &rect) {
    int code0 = computeRegionCode(x0, y0, rect);
    int code1 = computeRegionCode(x1, y1, rect);
    bool accept = false;

    while (true) {
        if ((code0 | code1) == 0) {
            // Both points are inside the rectangle
            accept = true;
            break;
        } else if (code0 & code1) {
            // Both points are outside the rectangle
            break;
        } else {
            
            
            double x, y;
	    int code_out;// One point is inside, one point is outside
		if (code0 != 0) {
   		 code_out = code0; // If code0 is not zero, assign it to code_out
		} else {
    		code_out = code1; // Otherwise, assign code1 to code_out
		}

            // Find the intersection point using the code
            if (code_out & TOP) {
                x = x0 + (x1 - x0) * (rect.y_max - y0) / (y1 - y0);
                y = rect.y_max;
            } else if (code_out & BOTTOM) {
                x = x0 + (x1 - x0) * (rect.y_min - y0) / (y1 - y0);
                y = rect.y_min;
            } else if (code_out & RIGHT) {
                y = y0 + (y1 - y0) * (rect.x_max - x0) / (x1 - x0);
                x = rect.x_max;
            } else if (code_out & LEFT) {
                y = y0 + (y1 - y0) * (rect.x_min - x0) / (x1 - x0);
                x = rect.x_min;
            }

            // Replace the outside point with the intersection point
            if (code_out == code0) {
                x0 = x;
                y0 = y;
                code0 = computeRegionCode(x0, y0, rect);
            } else {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1, rect);
            }
        }
    }

    if (accept) {
        // Draw the clipped line segment
        setcolor(RED);
        line(x0, y0, x1, y1);
    } else {
        cout << "Line segment is completely outside the clipping rectangle.\n";
    }
   
}

int main() {
    Rectangle rect ;
    line1 l;
    int gd = DETECT, gm;
    char f;
    cout<<"Enter co-ordinates of rectangle :"<<endl;
    cin>>rect;
    cout<<"Given co.ordinates Are :"<<endl;
    cout<<rect;
    cout<<"Enter co-ordinate (x1,y1)&(x2,y2) :";
    cin>>l;
    cout<<"Do you want to see Clipped line(Y/N)?";
    cin>>f;
    initgraph(&gd, &gm,NULL);
    
    delay(2000); // Define a clipping rectangle

    // Draw the clipping rectangle
    setcolor(WHITE);
    rectangle(rect.x_min, rect.y_min, rect.x_max, rect.y_max);
    delay(1000);
    // Define the line segment
     // Ending point of the line
   	
    // Draw the original line segment in blue
    if(f == 'Y'){
    setcolor(BLUE);
   }else{
   setcolor(BLACK);
   }
    line(l);
    // Perform line clipping
    cohenSutherlandClip(l.x1, l.y1, l.x2, l.y2, rect);
    delay(2000);	

    closegraph(); // Close the graphics window
    return 0;
}

