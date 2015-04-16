

/**
 * Description : Ray Tracing program
 * This is based on the code in "Ray Tracing from ground up" book
 */

#include "MathLib\Point.h"
#include "MathLib\Vector.h"
#include "MathLib\Ray.h"
#include "MathLib\Normal.h"
#include "Scene\RGBColor.h"
#include "Objects\Sphere.h"
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
// Test the interaction between point and vector class
//------------------------------------------------------------------------------
void testPointAndVector() {
  Point p1(0, 0, 0);
  Point p2(0, 5, 0);
  Vector v = p2 - p1;
  v.print();
  v = p1 - p2;
  v.print();
  Point p3 = p1 + v;
  p3.print();
  p3 = p3 - v;
  p3.print();
}

//------------------------------------------------------------------------------
// Test the ray class
//------------------------------------------------------------------------------
void testRayClass() {
  Ray r1; // Default constructor
  Ray r2(Point(0, 0, 0), Vector(1, 0, 0)); // Constructor with o and d
  Ray r3(r2);// Copy constructor
  Ray r4 = r2; // Assignment operator
  r1.print();
  r2.print();
  r3.print();
  r4.print();
}

//------------------------------------------------------------------------------
// Test the Normal class
//------------------------------------------------------------------------------
void testNormalClass() {
  Normal n1; // Default constructor
  Normal n2(0, 0, 1); // Constructor with 3 parameters
  Normal n3 = n2; // Assignment operator
  n1.print();
  n2.print();
  n3.print();
}

//------------------------------------------------------------------------------
// Test the Color class
//------------------------------------------------------------------------------
void testColorClass() {
  RGBColor c1; // Default constructor
  RGBColor c2(0.8f); // Constructor with 1 value
  RGBColor c3(0.2f, 0.4f, 0.5f); // Constructor with 3 values
  RGBColor c4(c3); // Copy constructor
  RGBColor c5 = c4; // Assignment operator
  c1.print();
  c2.print();
  c3.print();
  c4.print();
  c5.print();
}

//------------------------------------------------------------------------------
// Test Sphere and ray intersection
// This is an important test
// The test scene includes
//  1. A sphere at (0, 0, -5) and radius is 3
//  2. A ray with origin at (0, 0, 1) and direction vector is (0, 0, -1)
// The ray is supposed to hit the sphere at (0, 0, -2) and (0, 0, -8)
//------------------------------------------------------------------------------
void testRaySphere() {
  Sphere sphere(Point(0, 0, -5), 3.0);
  Ray ray(Point(0, 0, 1), Vector(0, 0, -1));
  double t;
  ShadeRec shadeRec;
  sphere.isHit(ray, t, shadeRec);
  cout << "t = " << t << "\n";
  shadeRec.print();
}

//------------------------------------------------------------------------------
// Entry point of the program
//------------------------------------------------------------------------------
int main (int argc, char* argv[]) {
  // testPointClass();
  // testVectorClass();
  // testPointAndVector();
  // testRayClass();
  // testNormalClass();
  // testColorClass();
  testRaySphere();

  return 0;
}
