#include "BodyParts.h"
#include "Tools.h"

void upperLeg(char position) {

	float p = 0.0;
	if (position == 'L') { p = -1; }
	else if (position == 'R') { p = 1; }

	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	//Bone
	glPushMatrix();
	glTranslatef(p*0.12f, -0.39f, 0.0f);
	glScalef(0.8, 0.6, 0.8);
	glColor3f(0.4f, 0.05f, 0.05f);
	glTranslatef(0.0f, 0.95f, 0.0f);
	gluSphere(var, 0.13, 8, 8);
	glPopMatrix();

	//Upper Leg
	glPushMatrix();
	glColor3f(0.4f, 0.05f, 0.05f);

	glTranslatef(p*0.12f, 0.18f, 0.0f);

	glScalef(0.8, 0.6, 0.8);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.15, 0.05, 0.5, 4, 4);
	glPopMatrix();

	//Leg Elbow
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(p*0.12f, -0.15f, 0.0f);
	glScalef(0.8, 0.6, 0.8);
	glRotatef(-45, 1.0, 0.0, 0.0);
	myElbow();
	glPopMatrix();

	gluDeleteQuadric(var);
}

void lowerLeg(char position) {

	float p = 0.0;
	if (position == 'L') { p = -1; }
	else if (position == 'R') { p = 1; }

	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	//Whole Leg
	glPushMatrix();
	glTranslatef(p*0.12f, -0.39f, 0.0f);
	glScalef(0.8, 0.6, 0.8);

	//Lower Left Leg
	//Back
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(0.0f, 0.0f, 0.01f);
	glScalef(0.3, 1.0, 1.0);
	gluCylinder(var, 0.3, 0.0, 0.1, 4, 4);
	glPopMatrix();

	//Front
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(0.0f, 0.0f, -0.01f);
	glScalef(0.4, 1.0, 1.0);
	glRotatef(175, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.35, 0.0, 0.15, 6, 6);
	glPopMatrix();
	glPopMatrix();


	gluDeleteQuadric(var);
}

void myFeet() {
	float x1 = 0.1, y1 = 0.1,
		x2 = 0.2, y2 = 0.0,
		x3 = 0.1, y3 = -0.1,
		x4 = -0.05, y4 = -0.1,
		x5 = -0.1, y5 = -0.05,
		x6 = -0.1, y6 = 0.05,
		x7 = -0.05, y7 = 0.1,

		z0 = 0.05, z1 = -0.05;

	float feet[16] = { x1,x2,x3,x4,x5,x6,x7,y1,y2,y3,y4,y5,y6,y7,z0,z1 };
	my3DPolygon(feet, sizeof(feet) / sizeof(feet[0]));
}

void feet(char position) {

	float p = 0.0;
	if (position == 'L') { p = -1; }
	else if (position == 'R') { p = 1; }

	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	//Whole Leg
	glPushMatrix();
	glTranslatef(p*0.12f, -0.39f, 0.0f);
	glScalef(0.8, 0.6, 0.8);

	//Left Feet
	//Feet
	glPushMatrix();
	glColor3f(0.4f, 0.05f, 0.05f);
	glTranslatef(0.0f, -0.45f, 0.0f);
	glRotatef(90, 0.0, 1.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	myFeet();
	glPopMatrix();
	//Ankle
	glPushMatrix();
	glColor3f(0.4f, 0.05f, 0.05f);
	glTranslatef(0.0f, -0.4f, 0.0f);
	glScalef(0.5, 1.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.15, 0.0, 0.1, 4, 4);
	glPopMatrix();
	//Toe
	glPushMatrix();
	glColor3f(0.4f, 0.05f, 0.05f);
	glTranslatef(0.0f, -0.38f, -0.13f);
	glRotatef(-130, 1.0, 0.0, 0.0);
	glScalef(0.4, 1.0, 1.0);
	gluCylinder(var, 0.15, 0.0, 0.1, 4, 4);
	glPopMatrix();
	glPopMatrix();

	gluDeleteQuadric(var);
}