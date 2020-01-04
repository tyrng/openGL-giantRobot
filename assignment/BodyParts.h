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

//Head
void head();

//Torso
void myBody();
void body();
void myWaist();
void waist();
void buttBones();


//Arms
void upperHand(char position);
void myElbow();
void lowerHand(char position);
void myPalm();
void palm(char position);
void myFinger(float length);
void fingers(float angleM, float angleD, char position);

//Legs
void upperLeg(char position);
void lowerLeg(char position);
void myFeet();
void feet(char position);

//Misc
void myThorn();
void sword();
void shield();
void myYogaMat();
void sunglasses();
void ball();
void lasers();
void topHat();
