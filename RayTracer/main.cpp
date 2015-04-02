/**
 * Description : Ray Tracing program
 */

#include <iostream>
#include <gl\glut.h>
using namespace std;

//------------------------------------------------------------------------------
// Display content on the screen
//------------------------------------------------------------------------------
void displayCallback() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0f, 1.0f, 1.0f);
  glFlush();
}

//------------------------------------------------------------------------------
// Entry point of the program
//------------------------------------------------------------------------------
int main (int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
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
