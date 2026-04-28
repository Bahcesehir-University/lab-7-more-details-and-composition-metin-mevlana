// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================
// Topics Covered:
//   - const objects and const member functions
//   - Member initializer lists
//   - friend functions and friend classes
//   - Composition (object as class member)
// ============================================================
// TEACHER VERSION — COMPLETE SOLUTION
// ============================================================

#include <iostream>
#include <string>
#include <cmath>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

// ------------------------------------------------------------
// Part 1: Point — used in composition inside Rectangle
// ------------------------------------------------------------

class Point {
private:
    double x;
    double y;

public:
    // Member initializer list constructor
    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    // Rectangle needs direct access to x and y for the friend demo
    friend class Rectangle;
};


// ------------------------------------------------------------
// Part 2: Rectangle — composition + friend
// ------------------------------------------------------------

class Rectangle {
private:
    Point topLeft;
    Point bottomRight;

public:
    // Member initializer list — mandatory because Point has no default constructor
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    double getWidth() const {
        return std::abs(bottomRight.x - topLeft.x);
    }

    double getHeight() const {
        return std::abs(bottomRight.y - topLeft.y);
    }

    double getArea() const {
        return getWidth() * getHeight();
    }

    void display() const {
        std::cout << "TopLeft: ";
        topLeft.display();
        std::cout << "\nBottomRight: ";
        bottomRight.display();
        std::cout << "\nWidth: " << getWidth()
                  << ", Height: " << getHeight()
                  << ", Area: " << getArea() << "\n";
    }

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// ------------------------------------------------------------
// Part 3: friend function — access to Rectangle internals
// ------------------------------------------------------------

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return r1.getArea() == r2.getArea();
}


// ------------------------------------------------------------
// Part 4: ConstDemo — const objects and const member functions
// ------------------------------------------------------------

class ConstDemo {
private:
    int value;

public:
    ConstDemo(int v) : value(v) {}

    int getValue() const { return value; }

    void doubleValue() { value *= 2; }          // NON-const: modifies object

    int constGetDouble() const { return value * 2; }  // const: no modification
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
