/**
 * Description : Implementation of Vector class
 * Author      : Anh Tuan Do
 */

#include "Vector.h"
#include <iostream>

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
Vector::Vector() : x(0), y(0), z(0) {

}

//------------------------------------------------------------------------------
// Constructor with 1 parameter
//------------------------------------------------------------------------------
Vector::Vector(const double value) : x(value), y(value), z(value) {

}

//------------------------------------------------------------------------------
// Constructor with 3 parameters
//------------------------------------------------------------------------------
Vector::Vector(const double xValue, const double yValue, const double zValue) {
  x = xValue;
  y = yValue;
  z = zValue;
}

//------------------------------------------------------------------------------
// Copy constructor
//------------------------------------------------------------------------------
Vector::Vector(const Vector& vector) {
  x = vector.x;
  y = vector.y;
  z = vector.z;
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
Vector::~Vector () {

}

//------------------------------------------------------------------------------
// Assignment operator
//------------------------------------------------------------------------------
Vector& Vector::operator= (const Vector& vector) {
  if (this == &vector) {
    return (*this);
  }
  x = vector.x;
  y = vector.y;
  z = vector.z;
  return (*this);
}

//------------------------------------------------------------------------------
// Unary operator
//------------------------------------------------------------------------------
Vector Vector::operator- (void) const {
  return (Vector(-x, -y, -z));
}

//------------------------------------------------------------------------------
// Calculate the length of the vector
//------------------------------------------------------------------------------
double Vector::length() {
  return (sqrt(x * x + y * y + z * z));
}

//------------------------------------------------------------------------------
// Calculate the squared length
//------------------------------------------------------------------------------
double Vector::squaredLength() {
  return (x * x + y * y + z * z);
}

//------------------------------------------------------------------------------
// Multiplication by a double
//------------------------------------------------------------------------------
Vector Vector::operator* (const double a) const {
  return (Vector(x * a, y * a, z * a));
}

//------------------------------------------------------------------------------
// Division by a double
//------------------------------------------------------------------------------
Vector Vector::operator/ (const double a) const {
  if (a != 0) {
    return (Vector(x / a, y / a, z / a));
  }
  else {
    std::cerr << "Vector operation: Cannot divide by 0\n";
    return Vector(0, 0, 0);
  }
}

//------------------------------------------------------------------------------
// Addition
//------------------------------------------------------------------------------
Vector Vector::operator+ (const Vector& vector) const {
  return (Vector(x + vector.x, y + vector.y, z + vector.z));
}

//------------------------------------------------------------------------------
// Compound addition
//------------------------------------------------------------------------------
Vector& Vector::operator+= (const Vector& vector) {
  x += vector.x;
  y += vector.y;
  z += vector.z;
  return (*this);
}

//------------------------------------------------------------------------------
// Substraction
//------------------------------------------------------------------------------
Vector Vector::operator- (const Vector& vector) const {
  return (Vector(x - vector.x, y - vector.y, z - vector.z));
}

//------------------------------------------------------------------------------
// Dot product
//------------------------------------------------------------------------------
double Vector::operator* (const Vector& vector) const {
  return (x * vector.x + y * vector.y + z * vector.z);
}

//------------------------------------------------------------------------------
// Cross product
//------------------------------------------------------------------------------
Vector Vector::operator^ (const Vector& vector) const {
  return (Vector(
    y * vector.z - z * vector.y,
    z * vector.x - x * vector.z,
    x * vector.y - y * vector.x
  ));
}

//------------------------------------------------------------------------------
// Normalize
//------------------------------------------------------------------------------
void Vector::normalize() {
  double length = this->length();
  x /= length;
  y /= length;
  z /= length;
}

//------------------------------------------------------------------------------
// Convert to a unit vector
//------------------------------------------------------------------------------
Vector& Vector::hat() {
  double length = this->length();
  x /= length;
  y /= length;
  z /= length;
  return (*this);
}

//------------------------------------------------------------------------------
// Print out debug information
//------------------------------------------------------------------------------
void Vector::print() {
  std::cout << "Vector x = " << x << ", y = " << y << ", z = " << z << "\n";
}
