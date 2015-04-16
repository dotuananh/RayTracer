/**
 * Description : Implementation of the Sphere class
 */

#include <iostream>
#include "Sphere.h"
#include "..\Engine\Common.h"

const double Sphere::kEpsilon = 0.001;

//------------------------------------------------------------------------------
// Default constructor
// Note that we also call the default constructor of Geometric object (parent)
// This is to make sure the properties we inherit from the parent class are
// also initialized.
//------------------------------------------------------------------------------
Sphere::Sphere() : GeometricObject() {
  center = Point(0, 0, 0);
  radius = 1;
}

//------------------------------------------------------------------------------
// Constructor with the center point and radius r
//------------------------------------------------------------------------------
Sphere::Sphere(Point _center, double _radius) : GeometricObject () {
  center = _center;
  radius = _radius;
}

//------------------------------------------------------------------------------
// Copy constructor
// This also pass the _sphere parameter to the parent class to assign
// other properties as well (like color)
//------------------------------------------------------------------------------
Sphere::Sphere(const Sphere& _sphere) : GeometricObject(_sphere) {
  center = _sphere.center;
  radius = _sphere.radius;
}

//------------------------------------------------------------------------------
// Clone
//------------------------------------------------------------------------------
Sphere* Sphere::clone() const {
  return (new Sphere(*this));
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
Sphere::~Sphere() {

}

//------------------------------------------------------------------------------
// Assignment operator
//------------------------------------------------------------------------------
Sphere& Sphere::operator=(const Sphere& _sphere) {
  if (this == &_sphere) {
    return (*this);
  }

  // Assign for the parent class as well
  GeometricObject::operator=(_sphere);

  center = _sphere.center;
  radius = _sphere.radius;

  return (*this);
}

//------------------------------------------------------------------------------
// Set the center with a point
//------------------------------------------------------------------------------
void Sphere::setCenter(const Point& _center) {
  center = _center;
}

//------------------------------------------------------------------------------
// Set the center with coordinates
//------------------------------------------------------------------------------
void Sphere::setCenter(const double _x, const double _y, const double _z) {
  center.x = _x;
  center.y = _y;
  center.z = _z;
}

//------------------------------------------------------------------------------
// Set the radius
//------------------------------------------------------------------------------
void Sphere::setRadius(const double _radius) {
  radius = _radius;
}

//------------------------------------------------------------------------------
// Check if a ray hits the sphere
// !!! This is the most important function in this class !!!
// Read chapter 3.4.5 carefully
//
// SUMMARY
// A sphere has a center point c, a radius r and a point p on the surface
// We'll have (p - c).(p - c) - r^2 = 0 (1)
// A ray is defined by an origin o and a direction vector d
// A point p belongs to the ray can be defined by
// p = o + td (with t is a parameter) (2)
// If the ray hits the sphere, there will be a point p that satisfied both
// (1) and (2)
// Therefore we'll have
// (o + td - c).(o + td -c) - r^2 = 0
// (d.d)t^2 + [2(o - c).d]t + (o -c).(o - c) - r2 = 0;
// This becomes a quadraticequation of t with
// a = d.d
// b = 2(o - c).d
// c =(o - c).(o - c) - r^2
// All we need is to find t
// t not found --> ray doesn't hit the sphere
// t is found --> ray hits the sphere
//------------------------------------------------------------------------------
bool Sphere::isHit(const Ray& _ray, double& _tmin, ShadeRec& _shadeRec) const {
  // temp = o - c
  // vector - vector = new vector
  Vector temp = _ray.o - center;

  // dot product of ray.d with itself
  // vector * vector = number
  // a = d.d
  double a = _ray.d * _ray.d;

  // vector * vector = number and then
  // number * number = number
  // b = 2(o - c).d
  // b = 2.temp.d
  double b = 2.0 * (temp * _ray.d);

  // vector * vector = number (1)
  // number * number = number (2)
  // number(1) - number (2) = number
  // (o - c)(o - c) - r^2
  double c = (temp * temp) - radius * radius;

  // delta = b^2 - 4ac
  double delta = (b * b) - (4.0 * a * c);

  if (delta < 0) { // Phuong trinh vo nghiem
    return false; // no hit
  }

  // else we have at least one hit point
  double squaredDelta = sqrt(delta);
  double denom = 2.0 * a;

  // t1 = (-b - squaredDelta) / 2a
  double t1 = (-b - squaredDelta) / denom;

  if (t1 > kEpsilon) { // we have a hit with x1!
    _tmin = t1;
    // calculate the hit point information
    // normal
    // We have 3 vectors here
    // CO = vector from the center of the sphere to the origin of the ray
    // OP = vector from the center of the ray origin to the intersection point
    // CP = vector from the center of the sphere to to intersection point
    // Also
    // CO = o - c = temp
    // OP = td
    // CP = CO + OP
    // CP = temp + td
    // CP is the vector pointing from the center of the sphere to the
    // intersection point and it's the normal vector we want
    // Now we need to make its length to be 1 so that it's normalized
    _shadeRec.hitNormal = (temp + t1 * _ray.d) / radius;

    // The location p = o + t1d
    _shadeRec.hitLocation = _ray.o + t1 * _ray.d;

    return true;
  }

  // if t1 isn't a hit, we check t2
  // ray starts inside the sphere

  double t2 = ( -b + squaredDelta) / denom;
  if (t2 > kEpsilon) {
    _tmin = t2;
    _shadeRec.hitNormal = (temp + t2 * _ray.d) / radius;
    _shadeRec.hitLocation = _ray.o + t2 * _ray.d;
    return true;
  }

  // Both intersection points are behind the rays
  return false;
}
