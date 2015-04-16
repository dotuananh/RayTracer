/**
 * Description : Header file for geometric objects
 * Read chapter 3.4.3
 */

#ifndef __GEOMETRIC_OBJECT__
#define __GEOMETRIC_OBJECT__

#include "..\MathLib\Point.h"
#include "..\MathLib\Normal.h"
#include "..\MathLib\Ray.h"
#include "..\Scene\RGBColor.h"
#include "..\Engine\ShadeRec.h"

class GeometricObject {
  public:
    // Default constructor
    GeometricObject();

    // Copy constructor
    GeometricObject(const GeometricObject& object);

    // Virtual copy constructor
    // Pure virtual function, each derived class must implement this function
    virtual GeometricObject* clone() const = 0;

    // Destructor
    virtual ~GeometricObject();

    // Check if the object is hit by a ray
    // This is also a pure virtual function
    // All the derived classes have to implement this function
    // f(o + td) = 0
    virtual bool isHit(const Ray& ray, double& t, ShadeRec& s) const = 0;

    // Assignment operator
    GeometricObject& operator=(const GeometricObject& object);

    // Set the color for the object
    void setColor(const RGBColor& color);

    // Set the color for the object with 3 parameters
    void setColor(const float red, const float green, const float blue);

    // Get the color of the object
    RGBColor getColor();

    // The color of the object
    RGBColor color;

    // Debug
    virtual void print();
};

#endif
