/**
 * Description : Implementation file for Plane class
 */

#include "Plane.h"

const double Plane::kEpsilon = 0.001;

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
Plane::Plane(): GeometricObject(),
  a(0, 0, 0), n(0, 1, 0) {

}

//------------------------------------------------------------------------------
// Constructor with a point and a normal
//------------------------------------------------------------------------------
Plane::Plane(const Point& _point, const Normal& _normal): GeometricObject(),
  a(_point), n(_normal) {
  n.normalize();
}

//------------------------------------------------------------------------------
// Copy constructor
//------------------------------------------------------------------------------
Plane::Plane(const Plane& _plane): GeometricObject(_plane),
  a(_plane.a), n(_plane.n) {
}

//------------------------------------------------------------------------------
// Clone function
//------------------------------------------------------------------------------
Plane* Plane::clone() const {
  return (new Plane(*this));
}

//------------------------------------------------------------------------------
// Assignment operator
//------------------------------------------------------------------------------
Plane& Plane::operator=(const Plane& _plane) {
  if (this == &_plane)
    return (*this);

  GeometricObject::operator= (_plane);

  a = _plane.a;
  n = _plane.n;

  return (*this);
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
Plane::~Plane() {

}

//------------------------------------------------------------------------------
// Check if a ray hits this plane
//
//------------------------------------------------------------------------------
bool Plane::isHit(const Ray& _ray, double& _tmin, ShadeRec& _shadeRec) const {
  double t = (a - _ray.o) * n / (_ray.d * n);

  if (t > kEpsilon) {
    _tmin = t;
    _shadeRec.hitNormal = n;
    _shadeRec.hitLocation = _ray.o + t * _ray.d;
    return true;
  }

  return false;
}
