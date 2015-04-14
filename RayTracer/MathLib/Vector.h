/**
 * Description : Header file for Vector class
 * Author      : Anh Tuan Do
 * Read chapter 2.6 for information about Vectors
 */

#
#ifndef __VECTOR__
#define __VECTOR__

class Vector {
  public:
    // Default constructor, all the values are 0
    Vector();

    // Constructor with 1 parameter
    // All the xyz values are the same
    Vector(const double value);

    // Constructor with 3 parameters
    // Use const so that we won't change the value passed to the constructor
    Vector(const double xValue, const double yValue, const double zValue);

    // Copy constructor
    Vector(const Vector& v);

    // Destructor
    ~Vector();

    // Assignment operator
    // Note that this function returns Vector&, not just Vector
    Vector& operator= (const Vector& vector);

    // Unary minus
    Vector operator- (void) const;

    // Calculate the length of the vector
    double length();

    // Calculate the squared length of the vector
    double squaredLength();

    // Multiplication by a double
    Vector operator* (const double a) const;

    // Division by a double
    Vector operator/ (const double a) const;

    // Addition and Compound addition
    // Vector + Vector = new Vector
    Vector operator+ (const Vector& vector) const;
    Vector& operator+= (const Vector& vector);

    // Substraction
    // Vector - Vector = new Vector
    Vector operator- (const Vector& vector) const;

    // Dot product
    // Vector . Vector = double
    // a.b = |a||b|cosA = Ax.Bx + Ay.By + Az.Bz
    double operator* (const Vector& vector) const;

    // Cross product
    // Vector x Vector = new Vector
    // a x b = c (vuong goc voi a va b)
    // A x B = (AyBz - AzBy, AzBx - AxBz, AxBy - AyBx)
    Vector operator^ (const Vector& vector) const;

    // Normalize
    // Normalize = reduce/stretch the vector so that it has the length of 1
    // For example (0, 3, 0) has a length = 3
    // Now we'll take (0/3, 3/3, 0/3) (x, y, z / length)
    // we'll have (0, 1, 0) with length is now 1
    // The vector is now normalized.
    void normalize();

    // Convert a vector to a unit vector
    // Same as normalize above but this time we return the vector instead of
    // void like above
    Vector& hat();

    // Debug
    void print();

    // Use double instead of float to have a better accuracy.
    double x, y, z;
};

#endif
