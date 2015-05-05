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

//==============================================================================
// BUILD functions
// Build the world with objects we want to trace
//==============================================================================

//------------------------------------------------------------------------------
// Build a scene with 35 spheres
// Figure in page 45 (chapter 3)
//------------------------------------------------------------------------------
void World::build() {
  viewPlane.setHRes(imgWidth); // 400
  viewPlane.setVRes(imgHeight); // 400
  viewPlane.setPixelSize(1);
  tracerPtr = new MultipleObjectsTracer(this);
  backgroundColor = RGBColor(0, 0, 0);

  // define the colors
  RGBColor yellow(      1.00f, 1.00f, 0.00f);
  RGBColor brown(       0.71f, 0.40f, 0.16f);
  RGBColor darkGreen(   0.00f, 0.41f, 0.41f);
  RGBColor orange(      1.00f, 0.75f, 0.00f);
  RGBColor green(       0.00f, 0.60f, 0.30f);
  RGBColor lightGreen(  0.65f, 1.00f, 0.30f);
  RGBColor darkYellow(  0.61f, 0.61f, 0.00f);
  RGBColor lightPurple( 0.65f, 0.30f, 1.00f);
  RGBColor darkPurple(  0.50f, 0.00f, 1.00f);

  // define the spheres
  Sphere* spherePtr01 = new Sphere(Point(5, 3, 0), 30);
  spherePtr01->setColor(yellow);
  addObject(spherePtr01);

  Sphere* spherePtr02 = new Sphere(Point(45, -7, -60), 20);
  spherePtr02->setColor(brown);
  addObject(spherePtr02);

  Sphere* spherePtr03 = new Sphere(Point(40, 43, -100), 17);
  spherePtr03->setColor(darkGreen);
  addObject(spherePtr03);

  Sphere* spherePtr04 = new Sphere(Point(-20, 28, -15), 20);
  spherePtr04->setColor(orange);
  addObject(spherePtr04);

  Sphere* spherePtr05 = new Sphere(Point(-25, -7, -35), 27);
  spherePtr05->setColor(green);
  addObject(spherePtr05);

  Sphere* spherePtr06 = new Sphere(Point(20, -27, -35), 25);
  spherePtr06->setColor(lightGreen);
  addObject(spherePtr06);

  Sphere* spherePtr07 = new Sphere(Point(35, 18, -35), 22);
  spherePtr07->setColor(green);
  addObject(spherePtr07);

  Sphere* spherePtr08 = new Sphere(Point(-57, -17, -50), 15);
  spherePtr08->setColor(brown);
  addObject(spherePtr08);

  Sphere* spherePtr09 = new Sphere(Point(-47, 16, -80), 23);
  spherePtr09->setColor(lightGreen);
  addObject(spherePtr09);

  Sphere* spherePtr10 = new Sphere(Point(-15, -32, -60), 22);
  spherePtr10->setColor(darkGreen);
  addObject(spherePtr10);

  Sphere* spherePtr11 = new Sphere(Point(-35, -37, -80), 22);
  spherePtr11->setColor(darkYellow);
  addObject(spherePtr11);

  Sphere* spherePtr12 = new Sphere(Point(10, 43, -80), 22);
  spherePtr12->setColor(darkYellow);
  addObject(spherePtr12);

  Sphere* spherePtr13 = new Sphere(Point(30, -7, -80), 10);
  spherePtr13->setColor(darkYellow);
  addObject(spherePtr13);

  Sphere* spherePtr14 = new Sphere(Point(-40, 48, -110), 18);
  spherePtr14->setColor(darkGreen);
  addObject(spherePtr14);

  Sphere* spherePtr15 = new Sphere(Point(-10, 53, -120), 18);
  spherePtr15->setColor(brown);
  addObject(spherePtr15);

  Sphere* spherePtr16 = new Sphere(Point(-55, -52, -100), 10);
  spherePtr16->setColor(lightPurple);
  addObject(spherePtr16);

  Sphere* spherePtr17 = new Sphere(Point(5, -52, -100), 15);
  spherePtr17->setColor(brown);
  addObject(spherePtr17);

  Sphere* spherePtr18 = new Sphere(Point(-20, -57, -120), 15);
  spherePtr18->setColor(darkPurple);
  addObject(spherePtr18);

  Sphere* spherePtr19 = new Sphere(Point(55, -27, -100), 17);
  spherePtr19->setColor(darkGreen);
  addObject(spherePtr19);

  Sphere* spherePtr20 = new Sphere(Point(50, -47, -120), 15);
  spherePtr20->setColor(brown);
  addObject(spherePtr20);

  Sphere* spherePtr21 = new Sphere(Point(70, -42, -150), 10);
  spherePtr21->setColor(lightPurple);
  addObject(spherePtr21);

  Sphere* spherePtr22 = new Sphere(Point(5, 73, -130), 12);
  spherePtr22->setColor(lightPurple);
  addObject(spherePtr22);

  Sphere* spherePtr23 = new Sphere(Point(66, 21, -130), 13);
  spherePtr23->setColor(darkPurple);
  addObject(spherePtr23);

  Sphere* spherePtr24 = new Sphere(Point(72, -12, -140), 12);
  spherePtr24->setColor(lightPurple);
  addObject(spherePtr24);

  Sphere* spherePtr25 = new Sphere(Point(64, 5, -160), 11);
  spherePtr25->setColor(green);
  addObject(spherePtr25);

  Sphere* spherePtr26 = new Sphere(Point(55, 38, -160), 12);
  spherePtr26->setColor(lightPurple);
  addObject(spherePtr26);

  Sphere* spherePtr27 = new Sphere(Point(-73, -2, -160), 12);
  spherePtr27->setColor(lightPurple);
  addObject(spherePtr27);

  Sphere* spherePtr28 = new Sphere(Point(30, -62, -140), 15);
  spherePtr28->setColor(darkPurple);
  addObject(spherePtr28);

  Sphere* spherePtr29 = new Sphere(Point(25, 63, -140), 15);
  spherePtr29->setColor(darkPurple);
  addObject(spherePtr29);

  Sphere* spherePtr30 = new Sphere(Point(-60, 46, -140), 15);
  spherePtr30->setColor(darkPurple);
  addObject(spherePtr30);

  Sphere* spherePtr31 = new Sphere(Point(-30, 68, -130), 12);
  spherePtr31->setColor(lightPurple);
  addObject(spherePtr31);

  Sphere* spherePtr32 = new Sphere(Point(58, 56, -180), 11);
  spherePtr32->setColor(green);
  addObject(spherePtr32);

  Sphere* spherePtr33 = new Sphere(Point(-63, -39, -180), 11);
  spherePtr33->setColor(green);
  addObject(spherePtr33);

  Sphere* spherePtr34 = new Sphere(Point(46, 68, -200), 10);
  spherePtr34->setColor(lightPurple);
  addObject(spherePtr34);

  Sphere* spherePtr35 = new Sphere(Point(-3, -72, -130), 12);
  spherePtr35->setColor(lightPurple);
  addObject(spherePtr35);
}


//------------------------------------------------------------------------------
// Build a scene with 2 spheres and a plane
// Figure 3.20
//------------------------------------------------------------------------------
// void World::build() {
//   viewPlane.setHRes(imgWidth); // 200
//   viewPlane.setVRes(imgHeight); // 200
//   viewPlane.setPixelSize(1);
//   tracerPtr = new MultipleObjectsTracer(this);
//   backgroundColor = RGBColor(0, 0, 0);

//   Sphere* spherePtr = new Sphere;

//   // Sphere #1
//   spherePtr->setCenter(0, -25, 0);
//   spherePtr->setRadius(80);
//   spherePtr->setColor(1, 0, 0);
//   addObject(spherePtr);

//   // Sphere #2
//   spherePtr = new Sphere(Point(0, 30, 0), 60);
//   spherePtr->setColor(1, 1, 0);
//   addObject(spherePtr);

//   // Plane
//   Plane* planePtr = new Plane(Point(0, 0, 0), Normal(0, 5, 1));
//   planePtr->setColor(0.0f, 0.3f, 0.0f);
//   addObject(planePtr);
// }

//------------------------------------------------------------------------------
// Build a scene with a single sphere
// Like Figure 3.18
//------------------------------------------------------------------------------
// void World::build() {
//   viewPlane.setHRes(imgWidth); // 400
//   viewPlane.setVRes(imgHeight); // 400
//   viewPlane.setPixelSize(1);

//   backgroundColor = RGBColor(1, 1, 1);
//   tracerPtr = new SingleSphereTracer(this);

//   sphere.setCenter(0, 0, 0);
//   sphere.setRadius(100);
// }
