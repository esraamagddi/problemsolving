#include <graphics.h>

class Point {
private:
    int x, y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    int getx() { return x; }
    int gety() { return y; }

    void setxy(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

class Line {
private:
    Point pl, pr;
    Point* ptr;
    Point* ptr2;

public:
    // Composition
    Line(int xl = 0, int yl = 0, int xr = 0, int yr = 0) {
        pl.setxy(xl, yl);
        pr.setxy(xr, yr);
        ptr = nullptr;
        ptr2 = nullptr;
    }

    void draw() {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, (char*)"");
        setcolor(2);
        line(pr.getx(), pr.gety(), pl.getx(), pl.gety());
        getch();
        closegraph();
    }

    // Association
    void draw(Point pl, Point pr) {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, (char*)"");
        setcolor(2);
        line(pr.getx(), pr.gety(), pl.getx(), pl.gety());
        getch();
        closegraph();
    }

    // Aggregation
    void setPoint(Point* p, Point* p2) {
        ptr = p;
        ptr2 = p2;
    }

    void draw(Point* ptr, Point* ptr2) {
        if (ptr == nullptr || ptr2 == nullptr) {
            return;
        } else {
            int gd = DETECT, gm;
            initgraph(&gd, &gm, (char*)"");
            setcolor(2);
            line(ptr->getx(), ptr->gety(), ptr2->getx(), ptr2->gety());
            getch();
            closegraph();
        }
    }

    //void unpoint() {
       // ptr = nullptr;
      //  ptr2 = nullptr;
    //}
};

int main() {
    Point p1(100, 100);
    Point p2(300, 300);
    Point p3(100, 200);
    Point p4(300, 300);

    Line lineComp(50, 50, 200, 200); // Composition
    Line lineAssoc;
    Line lineAgg;

    lineAssoc.draw(p1, p2);   // Association
    lineAgg.setPoint(&p3, &p4); // Aggregation
    lineAgg.draw(&p3, &p4);

    getch();
    return 0;
}
