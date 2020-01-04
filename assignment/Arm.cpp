#include "BodyParts.h"
#include "Tools.h"

void upperHand(char position) {

	float p = 0.0;
	if (position == 'L') { p = -0.39f; }
	else if (position == 'R') { p = 0.39f; }

	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	glPushMatrix();
	glTranslatef(p, 0.6f, 0.0f);
	glScalef(1.1, 1.1, 1.0);
	glRotatef(-10, 1.0, 0.0, 0.0);

	glColor3f(0.9f, 0.9f, 0.9f);
	gluSphere(var, 0.13, 8, 8);

	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(0.0f, -0.13f, 0.0f);
	gluSphere(var, 0.09, 8, 8);

	glTranslatef(0.0f, -0.1f, 0.0f);
	gluSphere(var, 0.08, 8, 8);

	glTranslatef(0.0f, -0.1f, 0.0f);
	gluSphere(var, 0.07, 8, 8);
	glPopMatrix();

	gluDeleteQuadric(var);
}

void myElbow() {
	float x1 = 0.05, y1 = 0.1,
		x2 = 0.1, y2 = 0.0,
		x3 = 0.05, y3 = -0.1,
		x4 = -0.05, y4 = -0.1,
		x5 = -0.1, y5 = 0.0,
		x6 = -0.05, y6 = 0.1,
		z0 = 0.1, z1 = -0.1;

	float elbow[14] = { x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6,z0,z1 };
	my3DPolygon(elbow, sizeof(elbow) / sizeof(elbow[0]));
}

void lowerHand(char position) {

	float p = 0.0;
	if (position == 'L') { p = -0.39f; }
	else if (position == 'R') { p = 0.39f; }

	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	glPushMatrix();
	glColor3f(0.4f, 0.05f, 0.05f);

	glTranslatef(p, 0.25f, 0.05f);

	glScalef(1.1, 1.1, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.1, 0.06, 0.3, 10, 10);

	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(0.0f, 0.05f, 0.0f);
	glScalef(1.0, 0.5, 1.0);
	glRotatef(140, 1.0, 0.0, 0.0);
	myElbow();
	glPopMatrix();

	gluDeleteQuadric(var);
}

void myPalm() {
	float x1 = 0.05, y1 = 0.0,
		x2 = 0.1, y2 = -0.05,
		x3 = 0.1, y3 = -0.15,
		x4 = 0.08, y4 = -0.2,

		x5 = -0.05, y5 = -0.2,
		x6 = -0.1, y6 = -0.15,
		x7 = -0.1, y7 = -0.05,
		x8 = -0.05, y8 = 0.0,

		z0 = 0.05, z1 = -0.05;

	float palm[18] = { x1,x2,x3,x4,x5,x6,x7,x8,y1,y2,y3,y4,y5,y6,y7,y8,z0,z1 };
	my3DPolygon(palm, sizeof(palm) / sizeof(palm[0]));
}

void palm(char position) {

	float p = 0.0;
	if (position == 'L') { p = -1; }
	else if (position == 'R') { p = 1; }

	//Palm
	glPushMatrix();
	glColor3f(0.6f, 0.2f, 0.2f);
	glTranslatef(p*0.39, -0.07f, 0.05f);
	glRotatef(-100, 0.0, 1.0, 0.0);
	glRotatef(p * 5, 1.0, 0.0, 0.0);

	glScalef(0.8, 1.0, 1.0);
	myPalm();
	glPopMatrix();
}

void myFinger(float length) {

	float quarter = length / 4;

	float x1 = 0.005, y1 = 0.0,
		x2 = 0.01, y2 = -quarter,
		x3 = 0.01, y3 = -length + quarter,
		x4 = 0.005, y4 = -length,

		x5 = -0.005, y5 = -length,
		x6 = -0.01, y6 = -length + quarter,
		x7 = -0.01, y7 = -quarter,
		x8 = -0.005, y8 = 0.0,

		z0 = 0.01, z1 = -0.01;

	float finger[18] = { x1,x2,x3,x4,x5,x6,x7,x8,y1,y2,y3,y4,y5,y6,y7,y8,z0,z1 };
	my3DPolygon(finger, sizeof(finger) / sizeof(finger[0]));
}

void fingers(float angleM, float angleD, char position) {

	float p = 0.0;
	int n = 0;
	if (position == 'L') { p = -1; n = 1; }
	else if (position == 'R') { p = 1; n = -1; }

	//Fingers
	glPushMatrix();
	glColor3f(0.6f, 0.2f, 0.2f);
	glTranslatef(p*0.39, -0.07f, 0.05f);
	glRotatef(-100, 0.0, 1.0, 0.0);
	glRotatef(p * 5, 1.0, 0.0, 0.0);

	//Thumb
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(-0.06f, -0.16f, 0.0f);
	glRotatef(-10, 0.0, 0.0, 1.0);
	glRotatef(n * angleM, 1.0, 0.0, 0.0);
	myFinger(0.05);
	glTranslatef(0.0f, -0.05f, 0.0f);
	glRotatef(n * 30, 1.0, 0.0, 0.0);
	glRotatef(n * angleD, 1.0, 0.0, 0.0);
	myFinger(0.05);
	glPopMatrix();

	//Index finger
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(-0.04f, -0.2f, 0.0f);
	//glRotatef(n * angleM, 1.0, 0.0, 0.0);
	myFinger(0.05);

	glTranslatef(0.0f, -0.05f, 0.0f);
	glRotatef(n * 45, 1.0, 0.0, 0.0);
	glRotatef(n * angleD, 1.0, 0.0, 0.0);
	myFinger(0.07);
	glPopMatrix();

	//Middle finger
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(-0.01f, -0.2f, 0.0f);
	glRotatef(n * angleM, 1.0, 0.0, 0.0);
	myFinger(0.05);

	glTranslatef(0.0f, -0.05f, 0.0f);
	glRotatef(n * 45, 1.0, 0.0, 0.0);
	glRotatef(n * angleD, 1.0, 0.0, 0.0);
	myFinger(0.09);
	glPopMatrix();

	//Ring finger
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(0.02f, -0.2f, 0.0f);
	glRotatef(n * angleM, 1.0, 0.0, 0.0);
	myFinger(0.05);

	glTranslatef(0.0f, -0.05f, 0.0f);
	glRotatef(n * 45, 1.0, 0.0, 0.0);
	glRotatef(n * angleD, 1.0, 0.0, 0.0);
	myFinger(0.07);
	glPopMatrix();

	//Pinkie
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(0.05f, -0.2f, 0.0f);
	glRotatef(n * angleM, 1.0, 0.0, 0.0);
	myFinger(0.05);

	glTranslatef(0.0f, -0.05f, 0.0f);
	glRotatef(n * 45, 1.0, 0.0, 0.0);
	glRotatef(n * angleD, 1.0, 0.0, 0.0);
	myFinger(0.05);
	glPopMatrix();
	glPopMatrix();
}