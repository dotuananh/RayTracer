/**
 * Description: Header file for the Point class
 * This class represents both 2D and 3D points
 * Read chapter 2.7 for information about Points.
 */

#ifndef __POINT__
#define __POINT__

#include "Vector.h"

class Point {
  public:
    // Default constructor, all values are set to 0
    Point();

    // Constructor for a 2D point
    // Use const so that we won't accidently
    // change the values that passed to us.
    Point(const double xValue, const double yValue);

    // Constructor for a 3D point, same as 2D
    Point(const double xValue, const double yValue, const double zValue);

    // Copy constructor
    // Use const means we won't change the data
    // in point object (the paparameter)
    // Use reference & means we just pass the reference of p,
    // not a new copy of p to save space and also avoid memory leaks.
    Point(const Point& point);

    // Destructor
    ~Point();

    // Assignment Operator
    // Note that for assignment operator, we return Point& instead of Point
    // The reason based on the book is because this will prevent memory leak
    // Need to read more about this.
    Point& operator= (const Point& point);

    // Scala multiplication (scale the point)
    // Something like a * P = (a * Px, a * Py, a * Pz)
    Point operator* (const double a);

    // Unary minus
    // - (x, y, z) = (-x, -y, -z)
    Point operator- (void) const;

    // Double distance between 2 points
    // We have const at the end of the function to say that
    // we won't make any changes to the member variables
    // of this class (x, y, and z)
    double squaredDistance(const Point& point) const;

    // Distance between 2 points
    // This uses square root, which is a big hit in speed
    // Use with caution
    double distance(const Point& point) const;

    // Debug
    void print();

    // Create a vector from 2 points
    // Point - Point = new Vector
    Vector operator- (const Point& point) const;

    // Move a point along a vector
    // Point + Vector = new Point
    Point operator+ (const Vector& vector) const;

    // Point - Vector = new Point
    Point operator- (const Vector& vector) const;

    // Use double so that we have more precise calculation
    double x, y, z;
};

#endif
