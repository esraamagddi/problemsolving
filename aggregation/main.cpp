#include <graphics.h>
#include <iostream>

class Point {
private:
    int x, y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    int getX() const { return x; }
    int getY() const { return y; }
};

// Line with aggregation
class Line {
public:
    // Member function accepting Point objects
    // two point object
    void draw(const Point& start, const Point& end) const {
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

// Circle (center point-radius)
class Circle {
private:
    Point center;
    int radius;

public:
    Circle(const Point& _center, int _radius) : center(_center), radius(_radius) {}

    void draw() const {
        circle(center.getX(), center.getY(), radius);
    }
};

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    setcolor(5);

    Point p1(100, 100);
    Point p2(300, 300);
    Point p3(100, 200);
    Point p4(300, 300);

    Line line;
    Circle circle(p1, 50); // Composition

    // Draw objects by passing arguments to member functions
    line.draw(p1, p2);         // Drawing line assoc
    line.draw(p3, p4);         // Drawing aggregated line// independant
    circle.draw();             // Drawing circle composition //depandant
    getch();
    closegraph();

    return 0;
}
