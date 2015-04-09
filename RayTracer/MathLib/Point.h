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
    Point(double xValue, double yValue, double zValue);

    // Copy constructor
    // Use const means we won't change the data
    // in point object (the paparameter)
    // Use reference & means we just pass the reference of p,
    // not a new copy of p to save space and also avoid memory leaks.
    Point(const Point& point);

    // Destructor
    ~Point();

    // Assignment Operator
    Point& operator= (const Point& point);

  private:
    // Use double so that we have more precise calculation
    double x, y, z;
};
#endif
