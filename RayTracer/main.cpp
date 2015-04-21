/**
 * Description : Ray Tracing program
 * This is based on the code in "Ray Tracing from ground up" book
 */

#include <iostream>
#include "Scene\World.h"
using namespace std;

//------------------------------------------------------------------------------
// Windows
//------------------------------------------------------------------------------
#include <gl\glut.h>

//------------------------------------------------------------------------------
// Mac
//------------------------------------------------------------------------------
//#include <OpenGL/glu.h>
//#include <OpenGL/OpenGL.h>
//#include <GLUT/GLUT.h>

//World world(640, 640);
World world(640, 640);
int imgWidth;
int imgHeight;

//------------------------------------------------------------------------------
// Display content on the screen
//------------------------------------------------------------------------------
void displayCallback() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  float* imgPixels = world.imgPixels;
  glDrawPixels(imgWidth, imgHeight, GL_RGB, GL_FLOAT, imgPixels);

  glutSwapBuffers();
}

//------------------------------------------------------------------------------
// Entry point of the program
//------------------------------------------------------------------------------
int main (int argc, char* argv[]) {
  world.build();
  world.renderScene();

  imgWidth = world.imgWidth;
  imgHeight = world.imgHeight;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(imgWidth, imgHeight);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Ray Tracing");
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
  glutDisplayFunc(displayCallback);
  glutMainLoop();
  return 0;
}
