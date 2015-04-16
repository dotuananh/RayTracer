/**
 * Description : Header file for a sphere
 * Read chapter 3.4.5
 */

#ifndef __SPHERE__
#define __SPHERE__

#include "GeometricObject.h"

class Sphere: public GeometricObject {
  public:
    // Default constructor
    Sphere();

    // Constructor with the center point and radius r
    Sphere(Point center, double r);

    // Copy constructor
    Sphere(const Sphere& _sphere);

    // Virtual clone function (pure virtual)
    virtual Sphere* clone() const;

    // Destructor
    virtual ~Sphere();

    // Assignment operator
    Sphere& operator=(const Sphere& sphere);

    // Set the center with a point
    void setCenter(const Point& centerPoint);

    // Set the center with coordinates
    void setCenter(const double _x, const double _y, const double _z);

    // Set the radius
    void setRadius(const double _radius);

    // Check if a ray hits the sphere
    virtual bool isHit(const Ray& ray, double& t, ShadeRec& _shadeRec) const;

  private:
    // The center of the sphere
    Point center;

    // The radius of the sphere
    double radius;

    // For shadows and secondary rays
    static const double kEpsilon;
};

#endif
