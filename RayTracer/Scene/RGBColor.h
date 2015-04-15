/**
 * Description : Header file for RGB class
 * Author      : Anh Tuan Do
 * Read chapter 3.5 for more information about RGB Color
 */

#ifndef __RGBColor__
#define __RGBColor__

class RGBColor {
  public:
    // Default constructor
    RGBColor();

    // Constructor with 1 value
    RGBColor(float color);

    // Constructor with 3 values
    RGBColor(float _red, float _green, float _blue);

    // Copy constructor
    RGBColor(const RGBColor& color);

    // Destructor
    ~RGBColor();

    // Assignment operator
    RGBColor& operator=(const RGBColor& color);

    // Debug
    void print();

    float r, g, b;
};

#endif
