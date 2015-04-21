/**
 * Description : Implementation of Single Sphere Tracer class
 */

#include "SingleSphereTracer.h"
#include "ShadeRec.h"

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
SingleSphereTracer::SingleSphereTracer() : Tracer() {

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
  //ShadeRec shadeRec;
  //double t;
  //if ray hit the sphere, return red color, otherwise retur black color
  return RGBColor(0, 0, 0);
}
