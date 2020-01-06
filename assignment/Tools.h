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
void cylinder2(float radius, float height, int sideR = NULL, int sideG = NULL, int sideB = NULL);
void cuboid();
void pyramid();
void my3DPolygon(float polygon[], int numOfElements);

bool compare_float(float x, float y, float epsilon = 0.01f);
bool compare_float(double x, double y, double epsilon = 0.01f);