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

#include "BodyParts.h"
#include "Tools.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "OpenGL Window"

// mouse movement
float lastX = 0.0f, lastY = 0.0f;
float zoomLevel = 0.0f;
float lastXR = 0.0f, lastYR = 0.0f;

float wholeBodyAngleX = 0.0;
float wholeBodyAngleY = 0.0;
float wholeBodyAngleZ = 0.0;
float wholeBodyTranslateX = 0.0;
float wholeBodyTranslateY = 0.0;

//For camera
boolean cameraOn = true;
//float camera = -2;
float camera = 1;

//which part to move
char bodyParts = 'A';
float HangleX = 0.0, HangleY = 0.0, BangleX = 0.0, BangleY = 0.0, Wangle = 0.0, //body
AangleX = 0.0, AangleY = 0.0, EangleX = 0.0, EangleY = 0.0, PangleX = 0.0, PangleY = 0.0, FMangle = 0.0, FDangle = 0.0, //right hand
LangleX = 0.0, LangleY = 0.0, KangleX = 0.0, KangleY = 0.0, TangleX = 0.0, TangleY = 0.0,//right leg
QangleX = 0.0, QangleY = 0.0, RangleX = 0.0, RangleY = 0.0, UangleX = 0.0, UangleY = 0.0, IMangle = 0.0, IDangle = 0.0, //right hand
OangleX = 0.0, OangleY = 0.0, SangleX = 0.0, SangleY = 0.0, DangleX = 0.0, DangleY = 0.0; //right leg

char direction = 'U';

//For animation
boolean animationON = false;
float angle1 = 0.0, angle2 = 0.0, angle3 = 0.0;
boolean walk = false, fly = false, playBall = false, attack = false, bow = false, star = false, swag = false, laser = false, pushUp = false, wearHat = false;
boolean dir = 1; //direction
int loadTimes = 0;
float ballX = 0.05, ballY = 0;

void resetToFalse() {
	walk = false;
	fly = false;
	loadTimes = 0;
	playBall = false;
	ballX = 0.05;
	ballY = 0;
	attack = false;
	bow = false;
	star = false;
	laser = false;
	pushUp = false;
}

//For texture
GLuint texture = 0;
BITMAP BMP;
HBITMAP hBMP = NULL;
int texturePattern = 0;
static int TOTAL_TEXTURE_PATTERN = 8;

//For lighting
float lightx = 0.2;
float lighty = 2.0;
float lightz = -5.0; // - infront, + go back
GLfloat ambientLight[] = { 0.3, 0.3, 0.3, 1.0 }; //RGBA
GLfloat diffuseLight[] = { 0.3, 0.3, 0.3, 1.0 }; //RGBA
boolean lightOn = false;

void clear() {

	HangleX = 0.0; HangleY = 0.0; BangleX = 0.0; BangleY = 0.0; Wangle = 0.0; //body
	AangleX = 0.0; AangleY = 0.0; EangleX = 0.0; EangleY = 0.0; PangleX = 0.0; PangleY = 0.0; FMangle = 0.0; FDangle = 0.0; //right hand
	LangleX = 0.0; LangleY = 0.0; KangleX = 0.0; KangleY = 0.0; TangleX = 0.0; TangleY = 0.0;//right leg
	QangleX = 0.0; QangleY = 0.0; RangleX = 0.0; RangleY = 0.0; UangleX = 0.0; UangleY = 0.0; IMangle = 0.0; IDangle = 0.0; //right hand
	OangleX = 0.0; OangleY = 0.0; SangleX = 0.0; SangleY = 0.0; DangleX = 0.0; DangleY = 0.0; //right leg

	angle1 = 0.0; angle2 = 0.0; angle3 = 0.0;
	dir = 1;
	glLoadIdentity();
	resetToFalse();
	lightOn = false;
}

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_MOUSEMOVE:
		switch (wParam) {
		case MK_LBUTTON:
		{
			int xPos = GET_X_LPARAM(lParam);
			int yPos = GET_Y_LPARAM(lParam);
			wholeBodyAngleY += xPos - lastX;
			wholeBodyAngleX += yPos - lastY;
			lastX = xPos;
			lastY = yPos;
		}
			break;
		case MK_RBUTTON:
		{
			int xPosR = GET_X_LPARAM(lParam);
			int yPosR = GET_Y_LPARAM(lParam);
			wholeBodyTranslateX += (xPosR - lastXR)/1000.0f;
			wholeBodyTranslateY -= (yPosR - lastYR) / 1000.0f;
			lastXR = xPosR;
			lastYR = yPosR;
		}
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		lastX = GET_X_LPARAM(lParam);
		lastY = GET_Y_LPARAM(lParam);
		break;
	case WM_LBUTTONUP:
		//if (!textureOn)
			//textureOn = true;
			break;
	case WM_RBUTTONDOWN:
		lastXR = GET_X_LPARAM(lParam);
		lastYR = GET_Y_LPARAM(lParam);
		break;
	case WM_MOUSEWHEEL:
		zoomLevel += GET_WHEEL_DELTA_WPARAM(wParam) / 120.0f;
		if (cameraOn) { camera += GET_WHEEL_DELTA_WPARAM(wParam) / 1000.0f; }
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == VK_UP)
		{
			direction = 'U';
			//BODY
			if (bodyParts == 'H') { if (HangleX < 60) HangleX += 5.0; }
			else if (bodyParts == 'B') { if (BangleX < 120) BangleX += 5.0; }
			else if (bodyParts == 'W') {}
			//RIGHT LIMBS
			else if (bodyParts == 'A') { if (AangleX < 160) AangleX += 5.0; }
			else if (bodyParts == 'E') { if (EangleX < 120) EangleX += 5.0; }
			else if (bodyParts == 'P') { PangleX += 5.0; }
			else if (bodyParts == 'F') { if (FMangle > -90) FMangle -= 5.0; }
			else if (bodyParts == 'L') { if (LangleX < 135) LangleX += 5.0; }
			else if (bodyParts == 'K') { if (KangleX < 120) KangleX += 5.0; }
			else if (bodyParts == 'T') { if (TangleX < 40) TangleX += 5.0; }
			//LEFT LIMBS
			else if (bodyParts == 'Q') { if (QangleX < 160) QangleX += 5.0; }
			else if (bodyParts == 'R') { if (RangleX < 120) RangleX += 5.0; }
			else if (bodyParts == 'U') { UangleX += 5.0; }
			else if (bodyParts == 'I') { if (IMangle > -90) IMangle -= 5.0; }
			else if (bodyParts == 'O') { if (OangleX < 135) OangleX += 5.0; }
			else if (bodyParts == 'S') { if (SangleX < 120) SangleX += 5.0; }
			else if (bodyParts == 'D') { if (DangleX < 40) DangleX += 5.0; }

		}

		else if (wParam == VK_DOWN)
		{
			direction = 'D';

			//BODY
			if (bodyParts == 'H') { if (HangleX > -30) HangleX -= 5.0; }
			else if (bodyParts == 'B') { if (BangleX > -120) BangleX -= 5.0; }
			else if (bodyParts == 'W') {}
			//RIGHT LIMBS
			else if (bodyParts == 'A') { if (AangleX > -160) AangleX -= 5.0; }
			else if (bodyParts == 'E') { if (EangleX > -10) EangleX -= 5.0; }
			else if (bodyParts == 'P') { PangleX -= 5.0; }
			else if (bodyParts == 'F') { if (FMangle < 90) FMangle += 5.0; }
			else if (bodyParts == 'L') { if (LangleX > -120) LangleX -= 5.0; }
			else if (bodyParts == 'K') { if (KangleX > -120) KangleX -= 5.0; }
			else if (bodyParts == 'T') { if (TangleX > -60) TangleX -= 5.0; }
			//LEFT LIMBS
			else if (bodyParts == 'Q') { if (QangleX > -160) QangleX -= 5.0; }
			else if (bodyParts == 'R') { if (RangleX > -10) RangleX -= 5.0; }
			else if (bodyParts == 'U') { UangleX -= 5.0; }
			else if (bodyParts == 'I') { if (IMangle < 90) IMangle += 5.0; }
			else if (bodyParts == 'O') { if (OangleX > -120) OangleX -= 5.0; }
			else if (bodyParts == 'S') { if (SangleX > -120) SangleX -= 5.0; }
			else if (bodyParts == 'D') { if (DangleX > -60) DangleX -= 5.0; }
		}
		else if (wParam == VK_LEFT)
		{
			direction = 'L';

			//BODY
			if (bodyParts == 'H') { if (HangleY < 90) HangleY += 5.0; }
			else if (bodyParts == 'B') { if (BangleY < 45) BangleY += 5.0; }
			else if (bodyParts == 'W') {}
			//RIGHT LIMBS
			else if (bodyParts == 'A') { if (AangleY > -10) AangleY -= 5.0; }
			else if (bodyParts == 'E') { if (EangleY > -10) EangleY -= 5.0; }
			else if (bodyParts == 'P') { PangleY -= 5.0; }
			else if (bodyParts == 'F') { if (FDangle < 90) FDangle += 5.0; }
			else if (bodyParts == 'L') { if (LangleY > -5) LangleY -= 5.0; }
			else if (bodyParts == 'K') { if (KangleY > -10) KangleY -= 5.0; }
			else if (bodyParts == 'T') { if (TangleY > -20) TangleY -= 5.0; }
			//LEFT LIMBS
			else if (bodyParts == 'Q') { if (QangleY > -200) QangleY -= 5.0; }
			else if (bodyParts == 'R') { if (RangleY > -100) RangleY -= 5.0; }
			else if (bodyParts == 'U') { UangleY -= 5.0; }
			else if (bodyParts == 'I') { if (IDangle > -55) IDangle -= 5.0; }
			else if (bodyParts == 'O') { if (OangleY > -120) OangleY -= 5.0; }
			else if (bodyParts == 'S') { if (SangleY > -100) SangleY -= 5.0; }
			else if (bodyParts == 'D') { if (DangleY > -20) DangleY -= 5.0; }
		}
		else if (wParam == VK_RIGHT)
		{
			direction = 'R';

			//BODY
			if (bodyParts == 'H') { if (HangleY > -90) HangleY -= 5.0; }
			else if (bodyParts == 'B') { if (BangleY > -45) BangleY -= 5.0; }
			else if (bodyParts == 'W') {}
			//RIGHT LIMBS
			else if (bodyParts == 'A') { if (AangleY < 200) AangleY += 5.0; }
			else if (bodyParts == 'E') { if (EangleY < 100) EangleY += 5.0; }
			else if (bodyParts == 'P') { PangleY += 5.0; }
			else if (bodyParts == 'F') { if (FDangle > -55) FDangle -= 5.0; }
			else if (bodyParts == 'L') { if (LangleY < 120) LangleY += 5.0; }
			else if (bodyParts == 'K') { if (KangleY < 100) KangleY += 5.0; }
			else if (bodyParts == 'T') { if (TangleY < 20) TangleY += 5.0; }
			//LEFT LIMBS
			else if (bodyParts == 'Q') { if (QangleY < 10) QangleY += 5.0; }
			else if (bodyParts == 'R') { if (RangleY < 10) RangleY += 5.0; }
			else if (bodyParts == 'U') { UangleY += 5.0; }
			else if (bodyParts == 'I') { if (IDangle < 90) IDangle += 5.0; }
			else if (bodyParts == 'O') { if (OangleY < 5) OangleY += 5.0; }
			else if (bodyParts == 'S') { if (SangleY < 10) SangleY += 5.0; }
			else if (bodyParts == 'D') { if (DangleY < 20) DangleY += 5.0; }
		}

		//else if (wParam == 0x58) //X -rotate x direction
		//{
		//	wholeBodyAngleX += 5.0;
		//}
		//else if (wParam == 0x59) //Y -rotate y direction
		//{
		//	wholeBodyAngleY += 5.0;

		//}
		//else if (wParam == 0x5A) //Z -rotate z direction
		//{
		//	wholeBodyAngleZ += 5.0;

		//}
		else if (wParam == 0x48) //H - HEAD 
		{
			bodyParts = 'H';
		}
		else if (wParam == 0x42) //B - BODY
		{
			bodyParts = 'B';
		}

		else if (wParam == 0x51) //Q - LEFT ARM
		{
			bodyParts = 'Q';
		}
		else if (wParam == 0x52) //R - LEFT ELBOW
		{
			bodyParts = 'R';
		}
		else if (wParam == 0x55) //U - LEFT PALM
		{
			bodyParts = 'U';
		}
		else if (wParam == 0x49) //I - LEFT FINGERS
		{
			bodyParts = 'I';
		}
		else if (wParam == 0x41) //A - RIGHT ARM
		{
			bodyParts = 'A';
		}
		else if (wParam == 0x45) //E - RIGHT ELBOW
		{
			bodyParts = 'E';
		}
		else if (wParam == 0x50) //P - RIGHT PALM
		{
			bodyParts = 'P';
		}
		else if (wParam == 0x46) //F - RIGHT FINGERS
		{
			bodyParts = 'F';
		}
		else if (wParam == 0x57) //W - WAIST
		{
			bodyParts = 'W';
		}
		else if (wParam == 0x4F) //O - LEFT LEG
		{
			bodyParts = 'O';
		}
		else if (wParam == 0x53) //S - LEFT KNEE
		{
			bodyParts = 'S';
		}
		else if (wParam == 0x44) //D - LEFT TOE
		{
			bodyParts = 'D';
		}
		else if (wParam == 0x4C) //L - RIGHT LEG
		{
			bodyParts = 'L';
		}
		else if (wParam == 0x4B) //K - RIGHT KNEE
		{
			bodyParts = 'K';
		}
		else if (wParam == 0x54) //T - RIGHT TOE
		{
			bodyParts = 'T';
		}
		else if (wParam == 0x30) /*0*/ { clear(); animationON = true;  walk = true; }
		else if (wParam == 0x31) /*1*/ { clear(); animationON = true; fly = true; }
		else if (wParam == 0x32) /*2*/ { clear(); animationON = true; playBall = true; }
		else if (wParam == 0x33) /*3*/ { clear(); animationON = true; attack = true; }
		else if (wParam == 0x34) /*4*/ { clear(); animationON = true; bow = true; }
		else if (wParam == 0x35) /*5*/ { clear(); animationON = true; star = true; }
		else if (wParam == 0x36) /*6*/ { clear(); animationON = true; laser = true; }
		else if (wParam == 0x37) /*7*/ { clear(); animationON = true; pushUp = true; }
		else if (wParam == 0x38) /*8*/ {
			animationON = true;
			if (wearHat == false) { wearHat = true; }
			else wearHat = false;
		}
		else if (wParam == 0x39) /*9*/ {
			animationON = true;
			if (swag == false) { swag = true; }
			else swag = false;
		}

		else if (wParam == VK_CONTROL) /*CTRL - change texture*/ { if (texturePattern < TOTAL_TEXTURE_PATTERN) { texturePattern++; } else { texturePattern = 0; } }
		else if (wParam == VK_TAB) /*TAB - change lighting*/ { lightOn = !lightOn; }

		else if (wParam == VK_RETURN) { cameraOn = !cameraOn; lightz = -lightz; }
		else if (wParam == VK_ADD) { if (cameraOn) { camera += 0.1; } }
		else if (wParam == VK_SUBTRACT) { if (cameraOn) { camera -= 0.1; } }

		else if (wParam == VK_SPACE)
		{
			glPushMatrix();
			glLoadIdentity();
			glPopMatrix();
			wholeBodyAngleX = 0.0;
			wholeBodyAngleY = 0.0;
			wholeBodyAngleZ = 0.0;
			cameraOn = true;
			//camera = -2;
			camera = 1;

			HangleX = 0.0; HangleY = 0.0; BangleX = 0.0; BangleY = 0.0; Wangle = 0.0; //body
			AangleX = 0.0; AangleY = 0.0; EangleX = 0.0; EangleY = 0.0; PangleX = 0.0; PangleY = 0.0; FMangle = 0.0; FDangle = 0.0; //right hand
			LangleX = 0.0; LangleY = 0.0; KangleX = 0.0; KangleY = 0.0; TangleX = 0.0; TangleY = 0.0;//right leg
			QangleX = 0.0; QangleY = 0.0; RangleX = 0.0; RangleY = 0.0; UangleX = 0.0; UangleY = 0.0; IMangle = 0.0; IDangle = 0.0; //right hand
			OangleX = 0.0; OangleY = 0.0; SangleX = 0.0; SangleY = 0.0; DangleX = 0.0; DangleY = 0.0; //right leg

			direction = 'U';
			bodyParts = 'A';

			//close texture
			texturePattern = 0;

			//stop animation
			animationON = false;
			angle1 = 0.0;
			dir = 1;
			resetToFalse();
			glLoadIdentity();
		}
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 80;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

//CREATE TEXTURE
void setTexture(string fileName, GLuint texture) {
	//Step 3: Initialize texture info
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), fileName.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);

	//Step 4: Assign texture to polygon.
	glGenTextures(1, &texture); //generate texture
	glBindTexture(GL_TEXTURE_2D, texture);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Maxification Filters (Choose linear)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //Minification Filters
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
}

void deleteTexture(GLuint texture) {
	//Step 5: Remove texture info.
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

}

//(1)Interactive Functions

void moveHead(float angleX, float angleY) {

	glTranslatef(0.0f, 0.77f, 0.0f);
	glRotatef(angleX, 1, 0.0, 0.0); //X- up down, Y- left right
	glRotatef(angleY, 0.0, 1, 0.0); //X- up down, Y- left right
	glTranslatef(0.0f, -0.77f, 0.0f);
}

void moveBody(float angleX, float angleY) {
	glTranslatef(0, 0.12f, 0.0f);
	glRotatef(angleY, 0, 1, 0);
	glRotatef(angleX, 1, 0, 0);
	glTranslatef(0, -0.12f, 0.0f);
}

void moveArm(float angleX, float angleY, float angleZ, char position) {

	float p = 0.0;
	if (position == 'L') { p = -0.39f; }
	else if (position == 'R') { p = 0.39f; }

	glTranslatef(p, 0.6f, 0.0f);
	glRotatef(angleX, 1, 0.0, 0.0); //X- up down, Y- left right
	glRotatef(angleZ, 0, 1.0, 0.0); //X- up down, Y- left right
	glRotatef(angleY, 0.0, 0.0, 1); //X- up down, Y- left right
	glTranslatef(-p, -0.6f, 0.0f);
}

void moveLowerArm(float angleX, float angleY, char position) {

	float p = 0.0;
	if (position == 'L') { p = -0.39f; }
	else if (position == 'R') { p = 0.39f; }

	glTranslatef(p, 0.25f, 0.05f);
	glRotatef(angleX, 1, 0.0, 0.0);
	glRotatef(angleY, 0.0, 0.0, 1);
	glTranslatef(-p, -0.25f, -0.05f);

}

void movePalm(float angleX, float angleY, float angleZ, char position) {

	float p = 0.0;
	if (position == 'L') { p = -0.39f; }
	else if (position == 'R') { p = 0.39f; }

	glTranslatef(p, -0.07f, 0.05f);
	glRotatef(angleZ, 0.0, 1, 0.0);
	glRotatef(angleX, 1, 0.0, 0.0);
	glRotatef(angleY, 0.0, 0.0, 1);
	glTranslatef(-p, 0.07f, -0.05f);
}

void moveFingerMiddle(float angle, char position) {

	float p = 0.0;
	if (position == 'L') { p = -0.39f; }
	else if (position == 'R') { p = 0.39f; }

	glTranslatef(p, -0.07f, 0.05f);
	glRotatef(angle, 0.0, 0.0, 1);
	glTranslatef(-p, 0.07f, -0.05f);
}

void moveUpperLeg(float angleX, float angleY, char position) {

	float p = 0.0;
	if (position == 'L') { p = -1; }
	else if (position == 'R') { p = 1; }

	glTranslatef(p*0.12f, 0.18f, 0.0f);
	glRotatef(angleX, 1, 0.0, 0.0); //X- up down, Y- left right
	glRotatef(angleY, 0.0, 0.0, 1); //X- up down, Y- left right
	glTranslatef(-p * 0.12f, -0.18f, 0.0f);
}

void moveLowerLeg(float angleX, float angleY, char position) {

	float p = 0.0;
	if (position == 'L') { p = -1; }
	else if (position == 'R') { p = 1; }

	glTranslatef(p*0.12f, -0.23f, 0.0f);
	glRotatef(angleX, 1, 0.0, 0.0); //X- up down, Y- left right
	glRotatef(angleY, 0.0, 0.0, 1); //X- up down, Y- left right
	glTranslatef(-p * 0.12f, 0.23f, 0.0f);
}

void moveFeet(float angleX, float angleY, char position) {

	float p = 0.0;
	if (position == 'L') { p = -1; }
	else if (position == 'R') { p = 1; }

	glTranslatef(p*0.12f, -0.58f, 0.0f);
	glRotatef(angleX, 1, 0.0, 0.0); //X- up down, Y- left right
	glRotatef(angleY, 0.0, 0.0, 1); //X- up down, Y- left right
	glTranslatef(-p * 0.12f, 0.58f, 0.0f);
}

//(2)Animation (Weapons, skills)
void walkON() {
	if ((angle1 <= -50) || (angle1 >= 50)) { dir = !dir; }
	if (dir) angle1 += 0.5; else angle1 -= 0.5;
}

void pushUpON() {
	glColor3f(0.1f, 0.1f, 0.1f);
	glPushMatrix();
	glTranslatef(0.05f, 0.0f, 0.0f);
	glRotatef(-3, 0, 0, 1);
	myYogaMat();
	glPopMatrix();
	//To position
	if (angle1 > -90) {
		angle1 -= 0.5;
	}
	if (angle2 > -70) {
		angle2 -= 0.5;
	}
	glRotatef(angle1, 0, 1, 0);
	glRotatef(angle2, 1, 0, 0);

	//Push up and down
	if (angle1 <= -90 || angle2 <= -70) {
		if (angle3 >= 5 || angle3 <= -15) {
			dir = !dir;
		}
		if (dir) { angle3 += 0.2; } //if up
		else { angle3 -= 0.2; } // if down
		glTranslatef(0, -0.6, 0);
		glRotatef(angle3, 1, 0, 0);
		glTranslatef(0, 0.6, 0);
	}
}

void spinON() {
	angle1 += 10; //upper body keep spin

	if ((TangleX >= -90)) { TangleX -= 1; }
	if ((DangleX >= -90)) { DangleX -= 1; }

	if (OangleX <= -10 || OangleX >= 0) { dir = !dir; }
	if (dir) { OangleX += 0.05; LangleX += 0.05; }
	else { OangleX -= 0.05; LangleX -= 0.05; }
}

int ballMove = 0;
boolean bounceBack = 0;

void playBallON() {
	if (UangleY <= -30 || UangleY >= 0) { dir = !dir; }
	if (dir) { UangleY += 0.12; }
	else { UangleY -= 0.12; }
	if (ballX <= 0.05 || ballX >= 0.3) { bounceBack = !bounceBack; }
	if (bounceBack) { ballX += 0.001; ballY -= 0.0025; }
	else { ballX -= 0.001; ballY += 0.0025; }
}

void attackON() {
	if (RangleX != 90) {
		RangleX += 0.5;
		EangleX += 0.5;
	}
	if (RangleX == 90) {
		if (UangleY != 90) {
			UangleY += 0.5;
			UangleX -= 0.1;
		}
		if (UangleY == 90) {
			if (IDangle != 90) {
				IDangle += 0.5;
				FDangle += 0.5;
			}
			if (IDangle == 90) {
				glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glScalef(0.5, 1, 0.5);
				glTranslatef(0.35, 0.40, -0.23);
				sword();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.5, 0, -0.3);
				shield();
				glPopMatrix();
			}
		}
	}
}

void bowON() {
	if (BangleX <= -90 || BangleX > 0) { dir = !dir; }
	if (dir) { BangleX += 0.5; }
	else { BangleX -= 0.5; }
}

void starON() {
	if (QangleY <= -90 && AangleY >= 90) { dir = !dir; }
	if (dir) { QangleY += 0.2; AangleY -= 0.2; SangleY += 0.1; KangleY -= 0.1; }
	else { QangleY -= 0.2; AangleY += 0.2; SangleY -= 0.1; KangleY += 0.1; }

	if (QangleY <= 180 && AangleY >= 180) { dir = !dir; }
	if (dir) { QangleY -= 0.2; AangleY += 0.2; SangleY += 0.1; KangleY -= 0.1; }
	else { QangleY += 0.2; AangleY -= 0.2; SangleY -= 0.1; KangleY += 0.1; }

	if (QangleY <= -90 && AangleY >= 90) { dir = !dir; }
	if (dir) { QangleY += 0.2; AangleY -= 0.2; SangleY -= 0.1; KangleY += 0.1; }
	else { QangleY -= 0.2; AangleY += 0.2; SangleY += 0.1; KangleY -= 0.1; }

	if (QangleY >= 0 && AangleY <= 0) { dir = !dir; }
	if (dir) { QangleY += 0.2; AangleY -= 0.2; SangleY += 0.1; KangleY -= 0.1; }
	else { QangleY -= 0.2; AangleY += 0.2; SangleY -= 0.1; KangleY += 0.1; }
}

float shootLaser = 0.0;
void laserON() {
	boolean firstRun = false;
	if (firstRun == false) {
		QangleX = 90;
		BangleY = -20;
		AangleX = -30;
		AangleY = 30;
		EangleX = 60;
		LangleX = 30;
		LangleY = 40;
		KangleX = -90;
		OangleX = 30;
		OangleY = 20;
		HangleY = 20;
		firstRun = true;
	}

	if (shootLaser != 0.01) {
		shootLaser -= 0.001;
	}
}

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear background colour (default : black)
	glClearColor(0.35f, 0.35f, 0.7f, 0.1); //Red Green Blue Alpha

	glLineWidth(20.0f);
	//Enable Alpha
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	//Set light position
	if (lightOn) {
		GLfloat lightPosition[] = { lightx, lighty, lightz, 1.0 }; //XYZ

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
		glEnable(GL_COLOR_MATERIAL); /* Ambient and diffuse material latch immediately to the current color. */
		glColorMaterial(GL_FRONT, GL_DIFFUSE);

		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHTING);
	}

	if (texturePattern > 0) {
		string fileName[] = { "diamond.bmp","rocks.bmp", "ice.bmp","smoke.bmp", "surface.bmp","brick.bmp", "metal.bmp","wood.bmp" };

		//Step 3: Initialize texture info
		glEnable(GL_TEXTURE_2D);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
		hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), fileName[texturePattern - 1].c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		GetObject(hBMP, sizeof(BMP), &BMP);

		//Step 4: Assign texture to polygon.
		glGenTextures(1, &texture); //generate texture
		glBindTexture(GL_TEXTURE_2D, texture);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Maxification Filters (Choose linear)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //Minification Filters
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0,
			GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
	}

	//setup camera
	if (cameraOn) {
		//Set Up Camera
		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//glFrustum(-0.5, 0.5, -0.5, 0.5, 1.0, 10.0);//Left Right Bottom Top Near Far
		//										   //glOrtho(-1, 1, -1, 1, 1.0, 10.0);//Left Right Bottom Top Near Far
		//glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();

		//gluLookAt(0, 0.6, camera, // look from camera XYZ 
		//	0, 0.1, 0,  // look at the origin 
		//	0, 1, 0); // positive Y up vector
	}
	else {
		if (animationON == false) {
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}
	}

	//For keep repeating animations
	if (fly) {
		glTranslatef(0.0, 0.001, 0.0);
		loadTimes += 1;
		if (loadTimes == 1000) {
			glLoadIdentity();
			loadTimes = 0;
		}
	}

	if (laser) {
		glTranslatef(-0.001, 0, 0);
		loadTimes += 1;
		if (loadTimes == 600) {
			glLoadIdentity();
			loadTimes = 0;
			shootLaser = 0;
		}
	}

	glPushMatrix();
	glScalef(camera, camera, camera);
	glTranslatef(wholeBodyTranslateX, wholeBodyTranslateY, 0);
	glRotatef(wholeBodyAngleX, 1, 0, 0);
	glRotatef(wholeBodyAngleY, 0, 1, 0);
	glRotatef(wholeBodyAngleZ, 0, 0, 1);
	glScalef(0.5, 0.5, 0.5);

	if (pushUp) {
		pushUpON();
	}

	//Head
	glPushMatrix();// Head to waist

	if (walk) {
		walkON();
		moveBody(0, angle1 / 3);
	}
	if (fly) {
		glPushMatrix();
		AangleX = 90;
		AangleY = 90;
		QangleX = 90;
		QangleY = -90;
		glPopMatrix();
		spinON();
		moveBody(0, angle1 / 3);
	}
	if (playBall) {
		glPushMatrix();
		RangleX = 50;
		RangleY = -20;
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.5, 0, -0.35);
		glTranslatef(ballX, ballY, 0);
		ball();
		glPopMatrix();

		playBallON();
	}
	if (attack) {
		glPushMatrix();
		attackON();
		glPopMatrix();
	}
	if (bow) {
		glPushMatrix();
		bowON();
		glPopMatrix();
		swag = false;
		wearHat = false;
	}
	if (star) {
		glPushMatrix();
		starON();
		glPopMatrix();
	}
	if (laser) {
		glPushMatrix();
		laserON();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, shootLaser);
		lasers();
		glPopMatrix();
	}
	if (swag) {
		glPushMatrix();
		glTranslatef(-0.2, 0.55, -0.1);
		glScalef(0.2, 0.2, 0.2);
		sunglasses();
		glPopMatrix();
	}
	if (wearHat) {
		glPushMatrix();
		topHat();
		glPopMatrix();
	}

	moveBody(BangleX, BangleY);

	//Head
	glPushMatrix();
	moveHead(HangleX, HangleY);
	head();
	glPopMatrix();

	//Body
	glPushMatrix();
	body();
	glPopMatrix();

	//Left Upper Hand
	glPushMatrix();
	if (walk) { moveArm(-angle1 / 2, 0, 0, 'L'); }
	if (pushUp) { moveArm(-angle1, 0, -80, 'L');  if (angle3 < 0) moveArm(angle3 * 6, 0, 0, 'L'); }
	moveArm(QangleX, QangleY, 0, 'L');
	upperHand('L');

	//Left Lower Hand
	if (pushUp) { if (angle3 < 0) moveLowerArm(-angle3 * 6, 0, 'L'); }
	moveLowerArm(10, 0, 'L');
	moveLowerArm(RangleX, RangleY, 'L');
	lowerHand('L');

	//Palm
	if (pushUp) { movePalm(0, angle1 / 2, angle1 / 2, 'L'); if (angle3 < 0) movePalm(0, angle3 * 2, 0, 'L'); }
	movePalm(UangleX, UangleY, 0, 'L');
	palm('L');
	fingers(IMangle, IDangle, 'L');
	glPopMatrix();

	//Right Upper Hand
	glPushMatrix();
	if (walk) { moveArm(angle1 / 2, 0, 0, 'R'); }
	if (pushUp) { moveArm(-angle1, 0, 80, 'R'); if (angle3 < 0) moveArm(angle3 * 6, 0, 0, 'R'); }
	moveArm(AangleX, AangleY, 0, 'R');
	upperHand('R');

	//Right Lower Hand
	if (pushUp) { if (angle3 < 0) moveLowerArm(-angle3 * 6, 0, 'R'); }
	moveLowerArm(10, 0, 'R');
	moveLowerArm(EangleX, EangleY, 'R');
	lowerHand('R');

	//Palm
	if (pushUp) { movePalm(0, -angle1 / 2, -angle1 / 2, 'R'); if (angle3 < 0) movePalm(0, -angle3 * 2, 0, 'R'); }
	movePalm(PangleX, PangleY, 0, 'R');
	palm('R');
	fingers(FMangle, FDangle, 'R');
	glPopMatrix();

	//Waist
	glPushMatrix();
	waist();
	glPopMatrix();

	//Butt bones
	glPushMatrix();
	buttBones();
	glPopMatrix();
	glPopMatrix();// Head to waist

	//Left Leg
	glPushMatrix();
	//Upper Leg
	if (walk) { moveUpperLeg(angle1, 0, 'L'); }
	moveUpperLeg(OangleX, OangleY, 'L');
	upperLeg('L');
	//Lower Leg
	if (walk) { moveLowerLeg(-angle1, 0, 'L'); }
	moveLowerLeg(SangleX, SangleY, 'L');
	lowerLeg('L');
	//Feet
	if (walk) { moveFeet(angle1, 0, 'L'); }
	moveFeet(DangleX, DangleY, 'L');
	feet('L');
	glPopMatrix();

	//Right Leg
	glPushMatrix();
	//Upper Leg
	if (walk) { moveUpperLeg(-angle1, 0, 'R'); }
	moveUpperLeg(LangleX, LangleY, 'R');
	upperLeg('R');

	//Lower Leg
	if (walk) { moveLowerLeg(angle1, 0, 'R'); }
	moveLowerLeg(KangleX, KangleY, 'R');
	lowerLeg('R');

	//Feet
	if (walk) { moveFeet(-angle1, 0, 'R'); }
	moveFeet(TangleX, TangleY, 'R');
	feet('R');
	glPopMatrix();

	glPopMatrix();

	//Step 5: Remove texture info.
	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

	//disable lighting
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHTING);


	//glLoadIdentity();

	glFlush();

	//--------------------------------
	//	End of OpenGL drawing
	//--------------------------------
}
//--------------------------------------------------------------------


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1024, 1024,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	/*if (cameraOn) {
	//Set Up Camera
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.5, 0.5, -0.5, 0.5, 1.0, 10.0);//Left Right Bottom Top Near Far
	//glOrtho(-5, 5, -5, 5, 1.0, 10.0);//Left Right Bottom Top Near Far
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	}*/

	glEnable(GL_DEPTH_TEST);

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display(); //refresh new frame

		SwapBuffers(hdc);

	}


	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------