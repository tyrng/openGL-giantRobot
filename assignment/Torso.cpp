#include "BodyParts.h"
#include "Tools.h"

void myBody() {
	float x1 = 0.15, y1 = 0.05,
		x2 = 0.25, y2 = 0.0,
		x3 = 0.15, y3 = -0.25,
		x4 = -0.15, y4 = -0.25,
		x5 = -0.25, y5 = 0.0,
		x6 = -0.15, y6 = 0.05,
		z0 = 0.1, z1 = -0.1;

	float body[14] = { x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6,z0,z1 };
	my3DPolygon(body, sizeof(body) / sizeof(body[0]));
}

void body() {
	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	//upper body
	glPushMatrix();
	glColor3f(0.4f, 0.05f, 0.05f);
	glTranslatef(0.0f, 0.65f, 0.0f);
	glScalef(1.2, 1.2, 1.0);
	myBody();
	glPopMatrix();

	//Thorn
	float scaleX = 0.4;
	float scaleY = 0.2;
	float scaleZ = 0.5;
	//level1
	//1
	glPushMatrix();
	glTranslatef(-0.2f, 0.63f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslatef(0.1f, 0.65f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(0.0f, 0.6f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslatef(-0.1f, 0.65f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//5
	glPushMatrix();
	glTranslatef(0.2f, 0.63f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();

	//level2
	glPushMatrix();
	glTranslatef(0.0f, -0.1f, 0.0f);
	//1
	glPushMatrix();
	glTranslatef(-0.2f, 0.63f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslatef(0.1f, 0.65f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(0.0f, 0.6f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslatef(-0.1f, 0.65f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//5
	glPushMatrix();
	glTranslatef(0.2f, 0.63f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	glPopMatrix();

	//level3
	glPushMatrix();
	glTranslatef(0.0f, -0.2f, 0.0f);
	//2
	glPushMatrix();
	glTranslatef(0.1f, 0.65f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(0.0f, 0.6f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslatef(-0.1f, 0.65f, -0.1f);
	glScalef(scaleX, scaleY, scaleZ);
	myThorn();
	glPopMatrix();
	glPopMatrix();

	//Left Bowel
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(-0.3f, 0.63f, 0.0f);
	glScalef(1.1, 1.1, 1.0);
	gluSphere(var, 0.06, 20, 20);
	glPopMatrix();

	//Right Bowel
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.3f, 0.63f, 0.0f);
	glScalef(1.1, 1.1, 1.0);
	gluSphere(var, 0.06, 20, 20);
	glPopMatrix();

	gluDeleteQuadric(var);
}

void myWaist() {
	float x1 = 0.1, y1 = 0.1,
		x2 = 0.2, y2 = 0.0,
		x3 = 0.1, y3 = -0.1,
		x4 = -0.1, y4 = -0.1,
		x5 = -0.2, y5 = 0.0,
		x6 = -0.1, y6 = 0.1,
		z0 = 0.1, z1 = -0.1;

	float waist[14] = { x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6,z0,z1 };
	my3DPolygon(waist, sizeof(waist) / sizeof(waist[0]));
}

void waist() {
	glColor3f(0.6f, 0.2f, 0.2f);
	glTranslatef(0.0f, 0.26f, 0.0f);
	glScalef(0.9, 0.9, 0.85);
	myWaist();
}

void buttBones() {
	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(-0.06f, 0.18f, 0.0f);
	glScalef(0.6, 0.6, 0.6);

	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glRotatef(45, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.2, 0.05, 0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2f, 0.0f, 0.0f);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glRotatef(45, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.2, 0.05, 0.3, 20, 20);
	glPopMatrix();
	glPopMatrix();

	gluDeleteQuadric(var);
}