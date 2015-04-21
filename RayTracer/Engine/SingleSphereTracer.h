/**
 * Description : Header file for SingleSphereTracer class
 * Read chapter 3.7
 */

#ifndef __SINGLESPHERETRACER__
#define __SINGLESPHERETRACER__

#include "Tracer.h"

class SingleSphereTracer: public Tracer {
  public:
    SingleSphereTracer();
    virtual ~SingleSphereTracer();
    virtual RGBColor traceRay(const Ray& ray) const;
};

#endif
