/**
 * Description : Implementation of the Point class
 * Author      : Anh Tuan Do
 */

#include "Point.h"
#include <iostream>

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
Point::Point() : x(0), y(0), z(0) {

}

//------------------------------------------------------------------------------
// Constructor for a 2D point
//------------------------------------------------------------------------------
Point::Point(const double xValue, const double yValue) {
  x = xValue;
  y = yValue;
  z = 0;
}

//------------------------------------------------------------------------------
// Constructor for a 3D point
//------------------------------------------------------------------------------
Point::Point(const double xValue, const double yValue, const double zValue) {
  x = xValue;
  y = yValue;
  z = zValue;
}

//------------------------------------------------------------------------------
// Copy constructor
//------------------------------------------------------------------------------
Point::Point(const Point& point) {
  x = point.x;
  y = point.y;
  z = point.z;
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
Point::~Point() {

}

//------------------------------------------------------------------------------
// Assignment Operator
//------------------------------------------------------------------------------
Point& Point::operator= (const Point& point) {
  if (this == &point)
    return (*this);

  x = point.x;
  y = point.y;
  z = point.z;

  return (*this);
}

//------------------------------------------------------------------------------
// Scala multiplication
//------------------------------------------------------------------------------
Point Point::operator* (const double a) {
  return (Point(a * x, a * y, a * z));
}

//------------------------------------------------------------------------------
// Unary minus
//------------------------------------------------------------------------------
Point Point::operator- (void) const {
  return (Point(-x, -y, -z));
}

//------------------------------------------------------------------------------
// Square distance between 2 points
//------------------------------------------------------------------------------
double Point::squaredDistance(const Point& point) const {
  return (
    (x - point.x) * (x - point.x) +
    (y - point.y) * (y - point.y) +
    (z - point.z) * (z - point.z)
  );
}

//------------------------------------------------------------------------------
// Distance between 2 points
//------------------------------------------------------------------------------
double Point::distance(const Point& point) const {
  return (sqrt(
    (x - point.x) * (x - point.x) +
    (y - point.y) * (y - point.y) +
    (z - point.z) * (z - point.z)
  ));
}

//------------------------------------------------------------------------------
// Debug
//------------------------------------------------------------------------------
void Point::print() {
  std::cout << "Point x = " << x << ", y = " << y << ", z = " << z << "\n";
}

//------------------------------------------------------------------------------
// Create a vector from 2 points
//------------------------------------------------------------------------------
Vector Point::operator-(const Point& point) const {
  return (Vector(x - point.x, y - point.y, z - point.z));
}

//------------------------------------------------------------------------------
// Addition a vector to a point to create a new point
//------------------------------------------------------------------------------
Point Point::operator+(const Vector& vector) const {
  return (Point(x + vector.x, y + vector.y, z + vector.z));
}

//------------------------------------------------------------------------------
// Substraction a vector to a point to create a new point
//------------------------------------------------------------------------------
Point Point::operator-(const Vector& vector) const {
  return (Point(x - vector.x, y - vector.y, z - vector.z));
}
