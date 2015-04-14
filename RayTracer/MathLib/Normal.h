/**
 * Description : Header file for Normal class
 * Author      : Anh Tuan Do
 * A normal is basically a vector with some special features.
 * Something like
 *  - No dot product or cross product between normals
 *  - No substract between normals
 *  - No add a point with a normal
 * Read chapter 2.8 for information about Normals
 */

#ifndef __NORMAL__
#define __NORMAL__

#include "Vector.h"

class Normal {
  public:
    // Default constructor
    Normal();

    // Constructor with 1 parameter
    Normal(double value);

    // Constructor with 3 parameters
    Normal(double xValue, double yValue, double zValue);

    // Copy constructor
    Normal(const Normal& normal);

    // Constructor with a Vector
    Normal(const Vector& vector);

    // Destructor
    ~Normal();

    // Assignment operator
    Normal& operator=(const Normal& normal);

    // Unary minus
    Normal operator-() const;

    // Addition
    // Normal + Normal = new Normal
    Normal operator+(const Normal& normal) const;

    // Compound addition
    Normal& operator+=(const Normal& normal);

    // Dot product with a vector
    // Note that we can't do dot product between normals
    // Normal . Vector = double
    double operator*(const Vector& vector) const;

    // Multiplication by a double
    // Normal * double = new Normal
    Normal operator*(const double value) const;

    // Normalize
    void normalize();

    // Use double to be more accurate than float
    double x, y, z;
};

#endif
