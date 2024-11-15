#include <graphics.h>
#include <cmath>
#include <iostream>

using namespace std;

// DDA function to draw line from (x1, y1) to (x2, y2)
void DDA_Line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    
    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE); // Draw pixel at rounded coordinates
        x += Xinc;
        y += Yinc;
    }
}

void drawPattern() {
    // Define coordinates for the main outer rectangle
    int left = 100, top = 100, right = 300, bottom = 300;
    // Draw the outer rectangle
    DDA_Line(left, top, right, top);
    DDA_Line(right, top, right, bottom);
    DDA_Line(right, bottom, left, bottom);
    DDA_Line(left, bottom, left, top);

    // Define coordinates for the diamond inside the rectangle
    int midX = (left + right) / 2;
    int midY = (top + bottom) / 2;
    int diamondTopY = top + 50, diamondBottomY = bottom - 50;
    
    // Draw the diamond
    DDA_Line(midX, top, right, midY);
    DDA_Line(right, midY, midX, bottom);
    DDA_Line(midX, bottom, left, midY);
    DDA_Line(left, midY, midX, top);

    // Define coordinates for the inner rectangle within the diamond
    int innerLeft = left + 50, innerRight = right - 50;
    int innerTop = midY - 50, innerBottom = midY + 50;

    // Draw the inner rectangle
    DDA_Line(innerLeft, innerTop, innerRight, innerTop);
    DDA_Line(innerRight, innerTop, innerRight, innerBottom);
    DDA_Line(innerRight, innerBottom, innerLeft, innerBottom);
    DDA_Line(innerLeft, innerBottom, innerLeft, innerTop);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawPattern();

    getch();
    closegraph();
    return 0;
}