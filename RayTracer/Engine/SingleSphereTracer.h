/**
 * Description : Header file for SingleSphereTracer class
 * Read chapter 3.7
 */

#ifndef __SINGLESPHERETRACER__
#define __SINGLESPHERETRACER__

#include "Tracer.h"

class SingleSphereTracer: public Tracer {
  public:
    // Default constructor
    SingleSphereTracer();

    // Constructor with a world pointer
    SingleSphereTracer(World* _worldPtr);

    // Destructor
    virtual ~SingleSphereTracer();

    // Do the ray tracing
    virtual RGBColor traceRay(const Ray& ray) const;
};

#endif
