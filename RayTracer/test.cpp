

/**
 * Description : Ray Tracing program
 * This is based on the code in "Ray Tracing from ground up" book
 */

#include "MathLib\Point.h"
#include "MathLib\Vector.h"
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
// Test Point class
//------------------------------------------------------------------------------
void testPointClass() {
  Point p1; // Using default constructor
  Point p2 (1, 2); // 2D point constructor
  Point p3 (2, 3, 2); // 3D point constructor
  Point p4 (p3); // Copy constructor
  p1.print();
  p2.print();
  p3.print();
  p4.print();
  Point p5 = p4; // Assignment operator
  p5.print();
  p5 = p5 * 3; // Multiplication operator
  p5.print();
  Point p6 = -p5; // Unary minus operator
  p6.print();
  Point p7(0, 0, 0);
  Point p8(0, 3, 0);
  cout << p7.squaredDistance(p8) << endl; // squared distance
  cout << p7.distance(p8) << endl; // distance
}

//------------------------------------------------------------------------------
// Test Vector class
//------------------------------------------------------------------------------
void testVectorClass() {
  Vector v1; // Default constructor
  Vector v2(1); // Constructor with 1 parameter
  Vector v3(1, 2, 3); // Constructor with 3 parameters
  Vector v4(v3); // Copy constructor
  v1.print();
  v2.print();
  v3.print();
  v4.print();
  Vector v5 = v4; // Assignment operator
  v5.print();
  v5 = -v5; // Unary minus operator
  v5.print();
  cout << v5.squaredLength() << endl; // squared length
  cout << v5.length() << endl; // length
  v5 = v5 * 3; // multiplication by a number
  v5.print();
  v5 = v5 / 3; // division by a number
  v5.print();

  Vector vx(2, 0, 0);
  Vector vy(0, 2, 0);
  Vector vz(0, 0, 2);

  Vector v6 = vx + vy; // Addition operator
  v6.print();

  Vector v7(vx);
  v7 += vy; // Compound operator
  v7.print();

  v6 = vx - vy;
  v6.print(); // Substraction operator

  cout << v2 * v3 << "\n"; // Dot product

  v7 = vx ^ vy;
  v7.print(); // Cross product

  v6 = v7;
  v6.normalize();
  v6.print();

  v3.hat().print();
}

//------------------------------------------------------------------------------
// Entry point of the program
//------------------------------------------------------------------------------
int main (int argc, char* argv[]) {
  // testPointClass();
  testVectorClass();

  return 0;
}
