/**
 * Description : Implementation of the World class
 */

#include "World.h"
#include "..\Objects\Sphere.h"
#include "..\Engine\SingleSphere.h"
#include "..\Engine\ShadeRec.h"
#include "..\MathLib\Vector.h"
#include "..\MathLib\Point.h"
#include "..\MathLib\Normal.h"

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
World::World() {
  backgroundColor = RGB(0, 0, 0);
  tracePtr = NULL;
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
World::~World() {
  if (tracePtr) {
    delte tracePtr;
    tracePtr = NULL;
  }
  deleteObjects();
}

//------------------------------------------------------------------------------
// Add and object to the world
//------------------------------------------------------------------------------
void World::addObject(GeometricObject* _objectPtr) {
  objects.push_back(_objectPtr);
}

//------------------------------------------------------------------------------
// Render the scene
// This is it! The begining of the process.
// We create a view plane, for each pixel in the view plane,
// we shoot a ray through it.
// Based on the traceRay function, we'll display the color of that pixel.
//------------------------------------------------------------------------------
void World::renderScene() const {
  RGBColor pixelColor;
  Ray ray;
  int hRes = viewPlane.hRes;
  int vRes = viewPlane.vRes;
  float pixelSize = viewPlane.pixelSize;
  float zw = 100.0;

  ray.d = Vector(0, 0, -1); // The ray is pointing inwards to the objects
  // Go through each pixels
  for (int row = 0; row <= vRes; row++) {
    for (int col = 0; col <= hRes; col++) {
      // Calculate the ray
      // Read page 66 to understand how we calculate the x,y and z for the ray
      ray.o = Point(
        pixelSize * (c - hRes/2.0 + 0.5),
        pixelSize * (r - vRes/2.0 + 0.5),
        zw);
      // Now trace the ray and get what color it should be for the pixel
      pixelColor = tracePtr->traceRay(ray);
      displayPixel(row, col, pixelColor);
    }
  }
}
