/**
 * Description : Header file for Plane class
 */

#ifndef __PLANE__
#define __PLANE__

#include "GeometricObject.h"

class Plane: public GeometricObject {
  public:
    // Default constructor
    Plane();

    // Constructor with a point and a normal
    Plane(const Point& _point, const Normal& normal);

    // Copy constructor
    Plane(const Plane& _plane);

    // Clone function
    virtual Plane* clone() const;

    // Assignment operator
    Plane& operator=(const Plane& _plane);

    // Destructor
    virtual ~Plane();

    // Hit function
    virtual bool isHit(
      const Ray& _ray, double& tmin, ShadeRec& _shadeRec) const;

    // A plane is consisted of a point and a normal
    Point a;
    Normal n;

    static const double kEpsilon;
};

#endif
