/**
 * Description : Implementation of the World class
 */

#include "World.h"
#include "..\Objects\Sphere.h"
#include "..\Objects\Plane.h"
#include "..\Engine\SingleSphereTracer.h"
#include "..\Engine\MultipleObjectsTracer.h"
#include "..\Engine\ShadeRec.h"
#include "..\MathLib\Vector.h"
#include "..\MathLib\Point.h"
#include "..\MathLib\Normal.h"

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
World::World(int _width, int _height) {
  backgroundColor = RGBColor(0, 0, 0);
  tracerPtr = NULL;
  imgWidth = _width;
  imgHeight = _height;
  int imgSize = imgWidth * imgHeight * 3;
  imgPixels = new float[imgSize];

  // Reset all the pixel colors in our buffer to be maroon.
  for (int i = 0; i < imgHeight; i++) {
    for (int j = 0; j < imgWidth; j++) {
      displayPixel(i, j, RGBColor(0.5, 0, 0));
    }
  }
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
World::~World() {
  if (tracerPtr) {
    delete tracerPtr;
    tracerPtr = NULL;
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
void World::renderScene() {
  RGBColor pixelColor;
  Ray ray;
  int hRes = viewPlane.hRes;
  int vRes = viewPlane.vRes;
  float pixelSize = viewPlane.pixelSize;
  float zw = 100.0;

  ray.d = Vector(0, 0, -1); // The ray is pointing inwards to the objects
  // Go through each pixels
  for (int row = 0; row < vRes; row++) {
    for (int col = 0; col < hRes; col++) {
      // Calculate the ray
      // We start from the bottom left corner
      // Read page 66 to understand how we calculate the x,y and z for the ray
      ray.o = Point(
        pixelSize * (col - hRes/2.0 + 0.5),
        pixelSize * (row - vRes/2.0 + 0.5),
        zw);
      // Now trace the ray and get what color it should be for the pixel
      pixelColor = tracerPtr->traceRay(ray);
      displayPixel(row, col, pixelColor);
    }
  }
}

//------------------------------------------------------------------------------
// Display the pixel with the color we calculated
//------------------------------------------------------------------------------
void World::displayPixel(const int _row, const int _column,
  const RGBColor& _pixelColor) {
  int position = (_row * imgWidth + _column) * 3;
  imgPixels[position + 0] = _pixelColor.r;
  imgPixels[position + 1] = _pixelColor.g;
  imgPixels[position + 2] = _pixelColor.b;
}

//------------------------------------------------------------------------------
// Build the world with objects we want to trace
//------------------------------------------------------------------------------
void World::build() {
  // viewPlane.setHRes(imgWidth);
  // viewPlane.setVRes(imgHeight);
  // viewPlane.setPixelSize(1);

  // backgroundColor = RGBColor(1, 1, 1);
  // tracerPtr = new SingleSphereTracer(this);

  // sphere.setCenter(0, 0, 0);
  // sphere.setRadius(100);

  viewPlane.setHRes(imgWidth);
  viewPlane.setVRes(imgHeight);
  viewPlane.setPixelSize(1);
  tracerPtr = new MultipleObjectsTracer(this);
  backgroundColor = RGBColor(0, 0, 0);

  Sphere* spherePtr = new Sphere;

  // Sphere #1
  spherePtr->setCenter(0, -25, 0);
  spherePtr->setRadius(80);
  spherePtr->setColor(1, 0, 0);
  addObject(spherePtr);

  // Sphere #2
  spherePtr = new Sphere(Point(0, 30, 0), 60);
  spherePtr->setColor(1, 1, 0);
  addObject(spherePtr);

  // Plane
  Plane* planePtr = new Plane(Point(0, 0, 0), Normal(0, 5, 1));
  planePtr->setColor(0.0f, 0.3f, 0.0f);
  addObject(planePtr);
}

//------------------------------------------------------------------------------
// Delete all objects in the world
//------------------------------------------------------------------------------
void World::deleteObjects() {
  int size = objects.size();

  for (int i = 0; i < size; i++) {
    delete objects[i];
    objects[i] = NULL;
  }

  objects.erase(objects.begin(), objects.end());
}

//------------------------------------------------------------------------------
// Check if the ray hits at least one of the objects in the world
//------------------------------------------------------------------------------
ShadeRec World::hitBareBoneObjects(const Ray& _ray) {
  ShadeRec shadeRec(*this);
  double t;
  double tmin = 1.0E10;
  int numObjects = objects.size();

  for (int j = 0; j < numObjects; j++) {
    if (objects[j]->isHit(_ray, t, shadeRec) && (t < tmin)) {
      shadeRec.hitObject = true;
      shadeRec.hitColor =objects[j]->getColor();
      tmin = t;
    }
  }
  return shadeRec;
}
