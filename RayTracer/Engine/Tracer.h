/**
 * Description : Header file for Tracer class
 * Read chapter 3.7 about Tracer
 */

#ifndef __TRACER__
#define __TRACER__

#include "..\MathLib\Ray.h"
#include "..\Scene\RGBColor.h"

class Tracer {
  public:
    // Constructor
    Tracer();

    // Destructor
    virtual ~Tracer();

    // Start ray tracing
    RGBColor traceRay(const Ray& _ray) const;

    // Start ray tracing
    RGBColor traceRay(const Ray ray, const int depth) const;
};

#endif
