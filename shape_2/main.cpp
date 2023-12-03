#include <iostream>
#include <graphics.h>

class Point {
private:
    int x, y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    int getX() const { return x; }
    int getY() const { return y; }
};

class Shape {
protected:
    int color;

public:
    Shape() : color(YELLOW) {}

    virtual void draw(const Point& position) {
        std::cout << "Drawing shape." << std::endl;
    }

    void setColor(int c) {
        color = c;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int r) : radius(r) {}

    void draw(const Point& position) override {
        setcolor(color);
        circle(position.getX(), position.getY(), radius);
    }

    friend std::istream& operator>>(std::istream& in, Circle& circle) {
        std::cout << "Enter radius: ";
        in >> circle.radius;
        return in;
    }
};

class Rect : public Shape {
private:
    int width;
    int height;

public:
    Rect(int w, int h) : width(w), height(h) {}

    void draw(const Point& position) override {
        setcolor(color);
        rectangle(position.getX(), position.getY(), position.getX() + width, position.getY() + height);
    }

    friend std::istream& operator>>(std::istream& in, Rect& rectangle) {
        std::cout << "Enter width: ";
        in >> rectangle.width;
        std::cout << "Enter height: ";
        in >> rectangle.height;
        return in;
    }
};

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";

    initgraph(&gd, &gm, data);

    int numShapes;
    std::cout << "Enter Number of Shapes: ";
    std::cin >> numShapes;

    Shape* shapes[numShapes];

    // the starting pos
    int startX = getmaxx() / 4;
    int startY = getmaxy() / 2;

    for (int i = 0; i < numShapes; ++i) {
        int choice;
        std::cout << "Shape " << i + 1 << ": Circle(1), Rectangle(2)? ";
        std::cin >> choice;

        if (choice == 1) {
            Circle* circle = new Circle(0);
            std::cin >> *circle;
            circle->setColor(RED);
            shapes[i] = circle;
        } else if (choice == 2) {
            Rect* rectangle = new Rect(0, 0);
            std::cin >> *rectangle;
            rectangle->setColor(BLUE);
            shapes[i] = rectangle;
        }
    }


    for (int i = 0; i < numShapes; ++i) {
        Point position(startX + i * 200, startY);
        shapes[i]->draw(position);
        //delay(7000);
    }
    getch();

    //delay(10000);
    //getchar();
    // Clear
    //for (int i = 0; i < numShapes; ++i) {
    //    delete shapes[i];
    //}

    closegraph();
    return 0;
}
