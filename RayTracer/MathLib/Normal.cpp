/**
 * Description : Implementation for the Normal class
 * Author      : Anh Tuan Do
 */

#include <iostream>
#include "Normal.h"

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
Normal::Normal() : x(0), y(0), z(0) {

}

//------------------------------------------------------------------------------
// Constructor with 1 parameter
//------------------------------------------------------------------------------
Normal::Normal(double value) : x (value), y(value), z(value) {

}

//------------------------------------------------------------------------------
// Constructor with 3 parameters
//------------------------------------------------------------------------------
Normal::Normal(double xValue, double yValue, double zValue) {
  x = xValue;
  y = yValue;
  z = zValue;
}

//------------------------------------------------------------------------------
// Copy constructor
//------------------------------------------------------------------------------
Normal::Normal(const Normal& normal) {
  x = normal.x;
  y = normal.y;
  z = normal.z;
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
Normal::~Normal() {

}

//------------------------------------------------------------------------------
// Assignment operator
//------------------------------------------------------------------------------
Normal& Normal::operator=(const Normal& normal) {
  if (this == &normal)
    return (*this);

  x = normal.x;
  y = normal.y;
  z = normal.z;

  return (*this);
}

//------------------------------------------------------------------------------
// Unary minus
//------------------------------------------------------------------------------
Normal Normal::operator-() const {
  return (Normal(-x, -y, -z));
}

//------------------------------------------------------------------------------
// Addition of two normals
//------------------------------------------------------------------------------
Normal Normal::operator+(const Normal& normal) const {
  return (Normal(
    x + normal.x,
    y + normal.y,
    z + normal.z
  ));
}

//------------------------------------------------------------------------------
// Compound addition
//------------------------------------------------------------------------------
Normal& Normal::operator+=(const Normal& normal) {
  x += normal.x,
  y += normal.y,
  z += normal.z;
  return (*this);
}

//------------------------------------------------------------------------------
// Dot product with a vector
//------------------------------------------------------------------------------
double Normal::operator*(const Vector& vector) const {
  return (x * vector.x + y * vector.y + z * vector.z);
}

//------------------------------------------------------------------------------
// Multiple by a double
//------------------------------------------------------------------------------
Normal Normal::operator*(const double value) const {
  return (Normal(x * value, y * value, z * value));
}

//------------------------------------------------------------------------------
// Normalize a normal
//------------------------------------------------------------------------------
void Normal::normalize() {
  double length = sqrt(x * x + y * y + z * z);
  x /= length;
  y /= length;
  z /= length;
}

//------------------------------------------------------------------------------
// Print debug information
//------------------------------------------------------------------------------
void Normal::print() {
  std::cout << "Normal x = " << x << ", y = " << y << ", z = " << z << std::endl;
}
