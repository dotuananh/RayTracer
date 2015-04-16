/**
 * Description : Header file for ShadeRec class
 * This class stores the information where the ray hits an object.
 * Read chapter 3.4.3 for more information about ShadeRec
 */

#ifndef __SHADE_REC__
#define __SHADE_REC__

class World; // forward declaration because we only use a reference of World

#include "..\MathLib\Point.h"
#include "..\MathLib\Normal.h"
#include "..\Scene\RGBColor.h"

class ShadeRec {
  public:
    // True if a ray hit an object
    bool hitObject;

   // The hit location
   Point hitLocation;

   // The normal at the hit point
   Normal hitNormal;

   // The color at the hit point
   RGBColor hitColor;

   // Reference to the world
   //World& world;

   ShadeRec();
   // Constructor
   //ShadeRec(World& _world);

   // Copy contructor
   ShadeRec(const ShadeRec& _shadeRec);

   // Debug
   void print();
};

#endif
