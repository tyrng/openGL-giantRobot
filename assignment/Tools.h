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
#define M_PI 3.14159265358979323846


//Shapes
void cube();
void cylinder();
//void cylinder2(float radius, float halfLength, int slices);
void cylinder2(float radius, float height, int R, int G, int B);
void cuboid();
void pyramid();
void my3DPolygon(float polygon[], int numOfElements);

