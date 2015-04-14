/**
 * Description: Header file for the Point class
 * This class represents both 2D and 3D points
 */

#ifndef __POINT__
#define __POINT__

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
    double squareDistance(const Point& point) const;

    // Distance between 2 points
    // This uses square root, which is a big hit in speed
    // Use with caution
    double distance(const Point& point) const;

    // DEBUG
    void print();

    // TODO: Implement minus 2 points to create a vector
    // TODO: Implement a point + vector = point
    // TODO: Implement a point - vector = point

  private:
    // Use double so that we have more precise calculation
    double x, y, z;
};

#endif
