// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================
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
   // TODO 1: Constructor with member initializer list (double x, double y)
   Point(double x, double y) : x(x), y(y) {}  // stub — fix initializer
   // TODO 2: const getter for x
   double getX() const { return x; }   // stub — add const
   // TODO 3: const getter for y
   double getY() const { return y; }   // stub — add const
   // TODO 4: const display()
   void display() const { std::cout << "(" << x << "," << y << ")"; }
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
       : topLeft(x1, y1), bottomRight(x2, y2) {}  // stub — fix initializer
   // TODO 7: const getWidth()
   double getWidth() const { return std::abs(bottomRight.x - topLeft.x); }  // stub
   // TODO 8: const getHeight()
   double getHeight() const { return std::abs(bottomRight.y - topLeft.y); }  // stub
   // TODO 9: const getArea()
   double getArea() const { return getWidth() * getHeight(); } // stub
   // TODO 10: const display()
   void display() const {
       std::cout << "Rectangle[";
       topLeft.display();
       std::cout << " to ";
       bottomRight.display();
       std::cout << "]";
   }
   // TODO 11: declare isSameSize as friend function
   friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};

// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
   return r1.getWidth() == r2.getWidth() &&
          r1.getHeight() == r2.getHeight();
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
   void doubleValue() { value *= 2; }  // stub
   // TODO 16: const constGetDouble() — returns value * 2 without modifying
   int constGetDouble() const { return value * 2; }  // stub — add const + fix body
};

// ============================================================
// MAIN
// ============================================================
int main() {
   // TODO 17-21: demo code
   Rectangle r1(0, 10, 5, 0);
   Rectangle r2(2, 8, 7, -2);
   Rectangle r3(0, 4, 3, 0);
   std::cout << "Rectangle 1: ";
   r1.display();
   std::cout << std::endl;
   std::cout << "Width: " << r1.getWidth() << std::endl;
   std::cout << "Height: " << r1.getHeight() << std::endl;
   std::cout << "Area: " << r1.getArea() << std::endl;
   std::cout << "Rectangle 2: ";
   r2.display();
   std::cout << std::endl;
   std::cout << "Rectangle 3: ";
   r3.display();
   std::cout << std::endl;
   std::cout << "r1 and r2 same size? ";
   std::cout << (isSameSize(r1, r2) ? "Yes" : "No") << std::endl;
   std::cout << "r1 and r3 same size? ";
   std::cout << (isSameSize(r1, r3) ? "Yes" : "No") << std::endl;
   ConstDemo demo(10);
   std::cout << "Original value: " << demo.getValue() << std::endl;
   std::cout << "Double without changing: " << demo.constGetDouble() << std::endl;
   demo.doubleValue();
   std::cout << "After doubleValue(): " << demo.getValue() << std::endl;
   return 0;
}
