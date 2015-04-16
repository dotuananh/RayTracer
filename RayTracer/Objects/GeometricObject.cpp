/**
 * Description : Implementation of the Geometric Object
 */

#include <iostream>
#include "GeometricObject.h"

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
GeometricObject::GeometricObject() {
  color = RGBColor(0, 0, 0);
}

//------------------------------------------------------------------------------
// Copy constructor
//------------------------------------------------------------------------------
GeometricObject::GeometricObject(const GeometricObject& object) {
  color = object.color;
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
GeometricObject::~GeometricObject() {

}

//------------------------------------------------------------------------------
// Assignment operator
//------------------------------------------------------------------------------
GeometricObject& GeometricObject::operator=(const GeometricObject& object) {
  if (this == &object) {
    return (*this);
  }

  color = object.color;

  return (*this);
}

//------------------------------------------------------------------------------
// Set color
//------------------------------------------------------------------------------
void GeometricObject::setColor(const RGBColor& _color) {
  color = _color;
}

//------------------------------------------------------------------------------
// Set color
//------------------------------------------------------------------------------
void GeometricObject::setColor(
  const float _red, const float _green, const float _blue) {
  color.r = _red;
  color.g = _green;
  color.b = _blue;
}

//------------------------------------------------------------------------------
// Get color
//------------------------------------------------------------------------------
RGBColor GeometricObject::getColor() {
  return color;
}

//------------------------------------------------------------------------------
// Debug
//------------------------------------------------------------------------------
void GeometricObject::print() {
  std::cout << "Object color r = " << color.r << ", g = " << color.g
    << ", b = " << color.b << "\n";
}
