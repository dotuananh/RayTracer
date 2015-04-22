/**
 * Description : Header file for Multiple Objects Tracer class
 */

#ifndef __MULTIPLEOBJECTSTRACER__
#define __MULTIPLEOBJECTSTRACER__

#include "Tracer.h"

class MultipleObjectsTracer: public Tracer {
  public:
    // Default constructor
    MultipleObjectsTracer();

    // Constructor with a world pointer
    MultipleObjectsTracer(World* worldPtr);

    // Destructor
    virtual ~MultipleObjectsTracer();

    // Trace the ray
    virtual RGBColor traceRay(const Ray& _ray) const;
};

#endif
