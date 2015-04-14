/**
 * Description : Header file for Ray class
 * A ray basically has a point and a direction vector
 * Author      : Anh Tuan Do
 * Read chapter 3.3 for information about Ray
 */

#ifndef __RAY__
#define __RAY__

#include "Point.h"
#include "Vector.h"

class Ray {
  public:
    // Default constructor
    Ray();

    // Constructor with the original point and the direction vector
    Ray(const Point& origin, const Vector& direction);

    // Copy constructor
    Ray(const Ray& ray);

    // Destructor
    ~Ray();

    // Asignment operator
    Ray& operator=(const Ray& ray);

    // Debug
    void print();

    Point o; // Origin
    Vector d; // Direction
};

#endif
