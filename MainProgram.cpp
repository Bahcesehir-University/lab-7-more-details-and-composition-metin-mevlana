// ============================================================

// Lab: More Details about Classes

// Course: Object-Oriented Programming (C++)

// Level: 2nd Year Engineering

// Duration: 60 minutes

// ============================================================
 
#include <iostream>

#include <string>

#include <cmath>
 
// ============================================================

// CLASS DEFINITIONS

// ============================================================
 
class Point {

private:

    double x;

    double y;

public:

    // TODO 1: Constructor with member initializer list (double x, double y)

    Point(double x, double y) : x(x), y(y) {}  // stub — fix initializer
 
    // TODO 2: const getter for x

    double getX() const{ return x; }   // stub — add const
 
    // TODO 3: const getter for y

    double getY() const { return y; }   // stub — add const
 
    // TODO 4: const display()

    void display() const { std::cout << "("<<x<<", "<<y<<")"; }
 
    // TODO 5: declare Rectangle as friend class

    friend class Rectangle;

};
 
 
class Rectangle {

private:

    Point topLeft;

    Point bottomRight;

public:

    // TODO 6: constructor with member initializer list

    Rectangle(double x1, double y1, double x2, double y2)

        : topLeft(x1,y1), bottomRight(x2,y2) {}  // stub — fix initializer
 
    // TODO 7: const getWidth()

    double getWidth() const { return std::abs(bottomRight.x - topLeft.x); }  // stub
 
    // TODO 8: const getHeight()

    double getHeight() const { return std::abs(bottomRight.y - topLeft.y); }  // stub
 
    // TODO 9: const getArea()

    double getArea() const { return getWidth() * getHeight();}  // stub
 
    // TODO 10: const display()

    void display() const {

        std::cout << "TopLeft: ";

        topLeft.display();

        std::cout << "\nBottomRight: ";

        bottomRight.display();

        std::cout << "\nWidth: " << getWidth()
<< ", Height: " << getHeight()
<< ", Area: " << getArea() << "\n";

    }
 
    // TODO 11: declare isSameSize as friend function

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);

};
 
 
// TODO 12: implement isSameSize

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {

    return r1.getArea() == r2.getArea();  // stub

}
 
 
class ConstDemo {

private:

    int value;

public:

    // TODO 13: constructor with member initializer list

    ConstDemo(int v) : value(v) {}  // stub — fix initializer
 
    // TODO 14: const getValue()

    int getValue() const { return value; }  // stub — add const
 
    // TODO 15: NON-const doubleValue() — multiplies value by 2

    void doubleValue() { value *= 2;}  // stub
 
    // TODO 16: const constGetDouble() — returns value * 2 without modifying

    int constGetDouble() const { return value * 2 ; }  // stub — add const + fix body

};
 
 
// ============================================================

// MAIN

// ============================================================

int main() {

    std::cout << "=== Part 1 & 2: Rectangle with Composition ===" << std::endl;
 
    Rectangle rect1(0, 0, 4, 3);   // width=4, height=3, area=12

    Rectangle rect2(1, 1, 4, 4);   // width=3, height=3, area=9
 
    std::cout << "\nRect1:\n"; rect1.display();

    std::cout << "\nRect2:\n"; rect2.display();
 
    std::cout << "\nSame size? "
<< (isSameSize(rect1, rect2) ? "Yes" : "No") << "\n";
 
    std::cout << "\n=== Part 3: const Object Demo ===" << std::endl;
 
    const ConstDemo cd1(7);

    std::cout << "const object value: " << cd1.getValue() << "\n";

    std::cout << "const object doubled (no mutation): " << cd1.constGetDouble() << "\n";
 
    ConstDemo cd2(5);

    cd2.doubleValue();

    std::cout << "non-const object after doubleValue(): " << cd2.getValue() << "\n";
 
    return 0;

}
 
