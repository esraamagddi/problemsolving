#include <iostream>
#include <graphics.h>

using namespace std;

class Shape {
protected:
    char color[20];

public:
    Shape() {
        strcpy(color, "yellow");
    }

   virtual void draw() {
        cout << "Drawing shape." << endl;
    }

    void setColor(const char c[]) {
        strcpy(color, c);
    }

    ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() {
        setcolor(RED);
        circle(400, 300, static_cast<int>(radius)); // Draw circle
        outtextxy(400, 300, "Circle");
    }

    friend istream& operator>>(istream& in, Circle& circle) {
        cout << "Enter radius: ";
        in >> circle.radius;
        return in;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    void draw()  {
        setcolor(BLUE);
        line(400, 100, 200, 400);
        line(400, 100, 200, 400);
        line(200, 400, 600, 400);
        line(600, 400, 400, 100);
        outtextxy(400, 300, "Triangle");
    }

    friend istream& operator>>(istream& in, Triangle& triangle) {
        cout << "Enter base: ";
        in >> triangle.base;
        cout << "Enter height: ";
        in >> triangle.height;
        return in;
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int numShapes;
    cout << "Enter Number of Shapes: ";
    cin >> numShapes;

    Shape* shapes[numShapes];

    for (int i = 0; i < numShapes; ++i) {
        int choice;
        cout << "Shape " << i + 1 << ": Circle(1), Triangle(2)? ";
        cin >> choice;

        if (choice == 1) {
            Circle* circle = new Circle(0);
            cin >> *circle;
            circle->setColor("Red");
            shapes[i] = circle;
        } else if (choice == 2) {
            Triangle* triangle = new Triangle(0, 0);
            cin >> *triangle;
            triangle->setColor("Blue");
            shapes[i] = triangle;
        }
    }

    for (int i = 0; i < numShapes; ++i) {
        shapes[i]->draw();
    }

    // Clear
    for (int i = 0; i < numShapes; ++i) {
        delete shapes[i];
    }

    getch();
    closegraph();
    return 0;
}
