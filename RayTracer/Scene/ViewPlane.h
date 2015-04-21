/**
 * Description : Header file for View Plane class
 * Read chapter 3.6.3
 */

#ifndef __VIEWPLANE__
#define __VIEWPLANE__

class ViewPlane {
  public:
    // Horizontal image resolution
    int hRes;

    // Vertical image resolution
    int vRes;

    // Pixel size
    float pixelSize;

    // Gamma correction factor
    float gamma;

    // Invered Gamma
    float inversedGamma;

    // Color is red if the value is out of gamut
    bool showOutOfGamut;

    // Default constructor
    ViewPlane();

    // Copy constructor
    ViewPlane(const ViewPlane& _viewPlane);

    // Destructor
    ~ViewPlane();

    // Set horizontal resolution
    void setHRes(const int _hres);

    // Set vertical resolution
    void setVRes(const int _vres);

    // Set pixel size
    void setPixelSize(const float _size);

    // Set gamma
    void setGamma(const float _gamma);

    // Set Gamut Display
    void setGamutDisplay(const bool _show);
};

#endif
