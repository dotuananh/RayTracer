/**
 * Description : Implementation of ViewPlane class
 */

#include "ViewPlane.h"

//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------
 ViewPlane::ViewPlane() {
  hRes = 2;
  vRes = 2;
  pixelSize = 1.0;
  gamma = 1.0;
  inversedGamma = 1.0;
  showOutOfGamut = false;
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
ViewPlane::~ViewPlane() {

}

//------------------------------------------------------------------------------
// Set horizontal resolution
//------------------------------------------------------------------------------
void ViewPlane::setHRes(const int _hRes) {
  hRes = _hRes;
}

//------------------------------------------------------------------------------
// Set vertical resolution
//------------------------------------------------------------------------------
void ViewPlane::setVRes(const int _vRes) {
  vRes = _vRes;
}

//------------------------------------------------------------------------------
// Set pixel size
//------------------------------------------------------------------------------
void ViewPlane::setPixelSize(const float _size) {
  pixelSize = _size;
}

//------------------------------------------------------------------------------
// Set Gamma
//------------------------------------------------------------------------------
void ViewPlane::setGamma(const float _gamma) {
  gamma = _gamma;
  inversedGamma = 1.0f / gamma;
}

//------------------------------------------------------------------------------
// Set Gamut display
//------------------------------------------------------------------------------
void ViewPlane::setGamutDisplay(const bool _show) {
  showOutOfGamut = _show;
}
