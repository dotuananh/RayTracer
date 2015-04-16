/**
 * Description : Implementation of ShadeRec class
 */

#include <iostream>
#include "ShadeRec.h"

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
ShadeRec::ShadeRec() {
  hitObject = false;
}

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
//ShadeRec::ShadeRec(World& _world) {
  //hitObject = false;
  //world = _world;
//}

//------------------------------------------------------------------------------
// Copy constructor
//------------------------------------------------------------------------------
//ShadeRec::ShadeRec(const ShadeRec& _shadeRec) {
  //hitObject = _shadeRec.hitObject;
  //hitLocation = _shadeRec.hitLocation;
  //hitColor = _shadeRec.hitColor;
  //world = _shadeRec.world;
//}

//------------------------------------------------------------------------------
// Debug
//------------------------------------------------------------------------------
void ShadeRec::print() {
  std::cout << "ShadeRec debug info - hit: " << hitObject << "\n";
  hitLocation.print();
  hitNormal.print();
  hitColor.print();
}
