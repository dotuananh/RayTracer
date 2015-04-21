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

//------------------------------------------------------------------------------
// Struct to store the RGB information of a pixel
//------------------------------------------------------------------------------
class World {
  public:
    ViewPlane viewPlane;
    RGBColor backgroundColor;
    Tracer* tracerPtr;
    Sphere sphere;
    vector<GeometricObject*> objects;

    World(int _imgWidth, int _imgHeight);
    ~World();
    void addObject(GeometricObject* _objectPtr);
    void build();
    void renderScene();
    RGBColor maxToOne(const RGBColor& _color) const;
    RGBColor clampToColor(const RGBColor& _color) const;
    void displayPixel(const int _row, const int _column,
      const RGBColor& _pixelColor);
    ShadeRec hitBareBoneObjects(const Ray& _ray);
    void deleteObjects();

    //--------------------------------------------------------------------------
    // This is the buffer we'll use to store the information for each pixel
    // A pixel will have 3 color bytes (Red, Green, and Blue)
    // Thus the total size of this buffer will be (Width * Height) * 3
    // For example, if we want to create a ray traced image of 50 x 50
    // We'll have 50 x 50 = 2500 pixels.
    // Each pixel needs 3 bytes to store its color information.
    // The total memory needed will be 2500 pixels * 3 byes = 7500 bytes
    // The drawing in this program is basically just to display this buffer
    // memory using glDrawPixels
    // Ref:http://www.cs.mun.ca/~blangdon/opengl/glDrawPixels.html
    //
    // With glDrawPixels, the start of the array (a[o])will be
    // drawn at the bottom left corner so we'll need some conversion
    //--------------------------------------------------------------------------
    int imgWidth;
    int imgHeight;
    float* imgPixels;


};

#endif
