/**
 * Description : Implementation of Single Sphere Tracer class
 */

#include "SingleSphereTracer.h"
#include "ShadeRec.h"
#include "..\Scene\World.h"

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
SingleSphereTracer::SingleSphereTracer() : Tracer() {

}

//------------------------------------------------------------------------------
// Constructor with a world pointer
//------------------------------------------------------------------------------
SingleSphereTracer::SingleSphereTracer(World* _worldPtr) : Tracer(_worldPtr) {

}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
SingleSphereTracer::~SingleSphereTracer() {

}

//------------------------------------------------------------------------------
// Start ray tracing
//------------------------------------------------------------------------------
RGBColor SingleSphereTracer::traceRay(const Ray& _ray) const {
  ShadeRec shadeRec;
  double t;

  //If ray hit the sphere, return red color, otherwise retur black color
  if (worldPtr->sphere.isHit(_ray, t, shadeRec)) {
    return RGBColor(1, 0, 0);
  }
  return RGBColor(0, 0, 0);
}
