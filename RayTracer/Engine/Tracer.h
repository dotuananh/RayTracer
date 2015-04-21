/**
 * Description : Header file for Tracer class
 * Read chapter 3.7 about Tracer
 */

#ifndef __TRACER__
#define __TRACER__

#include "..\MathLib\Ray.h"
#include "..\Scene\RGBColor.h"

class World;

class Tracer {
  public:
    // Constructor
    Tracer();

    // Constructor with a world pointer
    Tracer(World* _worldPtr);

    // Destructor
    virtual ~Tracer();

    // Start ray tracing
    virtual RGBColor traceRay(const Ray& _ray) const;

    // Start ray tracing
    virtual RGBColor traceRay(const Ray ray, const int depth) const;

    // World pointer
    World* worldPtr;
};

#endif
