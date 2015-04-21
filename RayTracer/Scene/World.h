/**
 * Description : Header file for the World class
 * Read chapter 3.6.1 and 3.6.5
 */

#ifndef __WORLD__
#define __WORLD__

#include <vector>
#include "ViewPlane.h"
#include "RGBColor.h"
#include "..\Engine\Tracer.h"
#include "..\Objects\GeometricObject.h"
#include "..\Objects\Sphere.h"
#include "..\Mathlib\Ray.h"
using namespace std;

class World {
  public:
    ViewPlane viewPlane;
    RGBColor backgroundColor;
    Tracer* tracerPtr;
    Sphere sphere;
    vector<GeometricObject*> objects;

    World();
    ~World();
    void addObject(GeometricObject* _objectPtr);
    void build();
    void renderScene() const;
    RGBColor maxToOne(const RGBColor& _color) const;
    RGBColor clampToColor(const RGBColor& _color) const;
    void displayPixel(
      const int _row, const int _column, const RGBColor& _pixelColor) const;
    ShadeRec hitBareBoneObjects(const Ray& _ray);
    void deleteObjects();
};

#endif
