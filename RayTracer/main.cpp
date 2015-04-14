/**
 * Description : Ray Tracing program
 * This is based on the code in "Ray Tracing from ground up" book
 */

//------------------------------------------------------------------------------
// Windows
//------------------------------------------------------------------------------
#include <iostream>
#include <gl\glut.h>
using namespace std;

//------------------------------------------------------------------------------
// Mac
//------------------------------------------------------------------------------
//#include <iostream>
//#include <OpenGL/glu.h>
//#include <OpenGL/OpenGL.h>
//#include <GLUT/GLUT.h>
//using namespace std;

#include "MathLib\Point.h"

//------------------------------------------------------------------------------
// Global constant values
//------------------------------------------------------------------------------
const int imgWidth = 800;
const int imgHeight = 600;
const int imgSize = imgWidth * imgHeight * 3; // See explanation below

//------------------------------------------------------------------------------
// Struct to store the RGB information of a pixel
//------------------------------------------------------------------------------
typedef struct _rgb {
  GLfloat r;
  GLfloat g;
  GLfloat b;
} RGB;

//------------------------------------------------------------------------------
// This is the buffer we'll use to store the information for each pixel
// A pixel will have 3 color bytes (Red, Green, and Blue)
// Thus the total size of this buffer will be (Width * Height) * 3
// For example, if we want to create a ray traced image of 50 x 50
// We'll have 50 x 50 = 2500 pixels.
// Each pixel needs 3 bytes to store its color information.
// The total memory needed will be 2500 pixels * 3 byes = 7500 bytes
// The drawing in this program is basically just to display this buffer memory
// using glDrawPixels
// Ref:http://www.cs.mun.ca/~blangdon/opengl/glDrawPixels.html
//------------------------------------------------------------------------------
RGB* imgPixels = new RGB[imgWidth * imgHeight];

//------------------------------------------------------------------------------
// Initialize the pixel buffer
//------------------------------------------------------------------------------
void initializeBuffer() {
  // Reset all the pixel colors in our buffer to be maroon.
  for (int i = 0; i < imgWidth * imgHeight; i++) {
    imgPixels[i].r = 0.5f;
    imgPixels[i].g = 0.0f;
    imgPixels[i].b = 0.0f;
  }
}


//------------------------------------------------------------------------------
// Display content on the screen
//------------------------------------------------------------------------------
void displayCallback() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glDrawPixels(imgWidth, imgHeight, GL_RGB, GL_FLOAT, imgPixels);
  glutSwapBuffers();
}

//------------------------------------------------------------------------------
// Test Point class
//------------------------------------------------------------------------------
void testPointClass() {
  Point p1; // Using default constructor
  Point p2 (1, 2); // 2D point constructor
  Point p3 (2, 3, 2); // 3D point constructor
  Point p4 (p3); // Copy constructor
  p1.print();
  p2.print();
  p3.print();
  p4.print();
  Point p5 = p4;
  p5.print();
  p5 = p5 * 3;
  p5.print();
  Point p6 = -p5;
  p6.print();
  Point p7(0, 0, 0);
  Point p8(0, 3, 0);
  cout << p7.squareDistance(p8) << endl;
  cout << p7.distance(p8) << endl;
}

//------------------------------------------------------------------------------
// Entry point of the program
//------------------------------------------------------------------------------
int main (int argc, char* argv[]) {
  // glutInit(&argc, argv);
  // glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  // glutInitWindowSize(imgWidth, imgHeight);
  // glutInitWindowPosition(100, 100);
  // glutCreateWindow("Ray Tracing");
  // glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  // glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  // glOrtho(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
  // initializeBuffer();
  // glutDisplayFunc(displayCallback);
  // glutMainLoop();

  // Test zone - Begin
  testPointClass();
  // Test zone - End

  return 0;
}
