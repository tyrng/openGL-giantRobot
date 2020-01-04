#include <Windows.h>
#include <Windowsx.h>
#include <gl/GL.h>
#include <GL/glu.h>
#include <math.h>
#include <iostream>
using namespace std;
#include <array>
#include <string> 
#include <map>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")


//Shapes
void cube();
void cylinder();
void cuboid();
void pyramid();
void my3DPolygon(float polygon[], int numOfElements);

