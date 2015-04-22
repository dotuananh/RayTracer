/**
 * Description : Implementation of the Multiple Objects Tracer class
 */

#include "MultipleObjectsTracer.h"
#include "..\Scene\World.h"

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
MultipleObjectsTracer::MultipleObjectsTracer(): Tracer() {

}

//------------------------------------------------------------------------------
// Constructor with the world pointer
//------------------------------------------------------------------------------
MultipleObjectsTracer::MultipleObjectsTracer(World* worldPtr):
  Tracer(worldPtr) {

}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
MultipleObjectsTracer::~MultipleObjectsTracer() {

}

//------------------------------------------------------------------------------
// Trace the ray
//------------------------------------------------------------------------------
RGBColor MultipleObjectsTracer::traceRay(const Ray& _ray) const {
  ShadeRec shadeRec(worldPtr->hitBareBoneObjects(_ray));

  if (shadeRec.hitObject) {
    return shadeRec.hitColor;
  }

  return worldPtr->backgroundColor;
}
