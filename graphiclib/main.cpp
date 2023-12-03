#include <graphics.h>
#include <iostream>
#include <sstream>
using namespace std;

int main ()
{
    //composition asocc
    //assoc dealing with instances of another class (using)
    //composition---->(part of)
    //circle point line point with graph

class Circle {
    // Circle class implementation
};

class Line {
    // Line class implementation
};

class GeometricStructure {
    Circle circle; // Association
    Line line;     // Association
    // Other members and methods of the GeometricStructure class
};

    return 0;
}
