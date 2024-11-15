#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

// Function to draw a polygon from a list of points
void drawPolygon(const Point points[], int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        line(points[i].x, points[i].y, points[(i + 1) % n].x, points[(i + 1) % n].y);
    }
}

// Function to apply X shear transformation
void shearX(Point points[], int n, float shearFactorX) {
    for (int i = 0; i < n; i++) {
        points[i].x = points[i].x + shearFactorX * points[i].y;
    }
}

// Function to apply Y shear transformation
void shearY(Point points[], int n, float shearFactorY) {
    for (int i = 0; i < n; i++) {
        points[i].y = points[i].y + shearFactorY * points[i].x;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define original shape (a rectangle in this example)
    Point rect[4] = {
        {100, 100},
        {200, 100},
        {200, 200},
        {100, 200}
    };

    int n = 4; // Number of vertices
    float shearFactorX = 1.0; // Shear factor for X-direction
    float shearFactorY = 0.5; // Shear factor for Y-direction

    // Draw the original shape in white
    drawPolygon(rect, n, WHITE);

    // Apply X-shear transformation and draw in red
    shearX(rect, n, shearFactorX);
    drawPolygon(rect, n, RED);

    // Reset to the original shape
    rect[0] = {100, 100};
    rect[1] = {200, 100};
    rect[2] = {200, 200};
    rect[3] = {100, 200};

    // Apply Y-shear transformation and draw in blue
    shearY(rect, n, shearFactorY);
    drawPolygon(rect, n, BLUE);

    getch();
    closegraph();
    return 0;
}
