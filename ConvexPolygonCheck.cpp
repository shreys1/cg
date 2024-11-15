// Write a c++ program to draw a polygon and identify whether it is concave or convex

#include <graphics.h>
#include <conio.h>
#include <vector>

struct Point {
    int x, y;
};

// Function to draw the polygon
void drawPolygon(const std::vector<Point>& points) {
    int n = points.size();
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        line(points[i].x, points[i].y, points[next].x, points[next].y);
    }
}

// Function to determine if a polygon is convex or concave
bool isConvex(const std::vector<Point>& points) {
    int n = points.size();
    if (n < 3) return false;  // A polygon must have at least 3 points

    bool isPositive = false, isNegative = false;

    for (int i = 0; i < n; i++) {
        int dx1 = points[(i + 1) % n].x - points[i].x;
        int dy1 = points[(i + 1) % n].y - points[i].y;
        int dx2 = points[(i + 2) % n].x - points[(i + 1) % n].x;
        int dy2 = points[(i + 2) % n].y - points[(i + 1) % n].y;

        // Calculate the cross product of vectors (dx1, dy1) and (dx2, dy2)
        int crossProduct = dx1 * dy2 - dy1 * dx2;

        if (crossProduct > 0) {
            isPositive = true;
        } else if (crossProduct < 0) {
            isNegative = true;
        }

        // If both positive and negative cross products are found, the polygon is concave
        if (isPositive && isNegative) {
            return false;
        }
    }

    // If we only found either positive or negative cross products, the polygon is convex
    return true;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define a polygon (change points for testing different polygons)
    std::vector<Point> points = {
        {200, 200},
        {300, 100},
        {400, 200},
        {350, 300},
        {250, 300}
    };

    // Draw the polygon
    setcolor(WHITE);
    drawPolygon(points);

    // Determine if the polygon is convex or concave
    bool convex = isConvex(points);

    // Display the result
    setcolor(YELLOW);
    if (convex) {
        outtextxy(50, 50, "The polygon is convex.");
    } else {
        outtextxy(50, 50, "The polygon is concave.");
    }

    getch();
    closegraph();
    return 0;
}
