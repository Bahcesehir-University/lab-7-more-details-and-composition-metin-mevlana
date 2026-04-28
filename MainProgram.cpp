#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
    double x;
    double y;
public:
    // TODO 1
    Point(double x, double y) : x(x), y(y) {}

    // TODO 2
    double getX() const { return x; }

    // TODO 3
    double getY() const { return y; }

    // TODO 4 (FIXED SYNTAX)
    void display() const { std::cout << "(" << x << "," << y << ")"; }

    // TODO 5
    friend class Rectangle;
};


class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    // TODO 6
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // TODO 7 (FIX WIDTH LOGIC)
    double getWidth() const {
        return std::abs(bottomRight.x - topLeft.x);
    }

    // TODO 8
    double getHeight() const {
        return std::abs(bottomRight.y - topLeft.y);
    }

    // TODO 9 (FIX TYPO)
    double getArea() const {
        return getWidth() * getHeight();
    }

    // TODO 10
    void display() const {
        std::cout << "Rectangle[";
        topLeft.display();
        std::cout << " to ";
        bottomRight.display();
        std::cout << "]";
    }

    // TODO 11
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// TODO 12
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getWidth() == r2.getWidth()) &&
           (r1.getHeight() == r2.getHeight());
}


class ConstDemo {
private:
    int value;
public:
    // TODO 13
    ConstDemo(int v) : value(v) {}

    // TODO 14
    int getValue() const { return value; }

    // TODO 15 (FIX MISSING SEMICOLON)
    void doubleValue() { value *= 2; }

    // TODO 16
    int constGetDouble() const { return value * 2; }
};


// ============================================================
// MAIN
// ============================================================
int main() {
    // TODO 17-21: demo code

    Rectangle r1(0, 10, 5, 0);
    Rectangle r2(2, 8, 7, 0);

    r1.display();
    std::cout << "\nArea: " << r1.getArea() << std::endl;

    r2.display();
    std::cout << "\nArea: " << r2.getArea() << std::endl;

    if (isSameSize(r1, r2))
        std::cout << "Rectangles are the same size.\n";
    else
        std::cout << "Rectangles are NOT the same size.\n";

    ConstDemo obj(10);
    std::cout << "Value: " << obj.getValue() << std::endl;

    obj.doubleValue();
    std::cout << "After doubling: " << obj.getValue() << std::endl;

    std::cout << "Const double (no change): " << obj.constGetDouble() << std::endl;

    return 0;
}
