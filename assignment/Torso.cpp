#include "BodyParts.h"
#include "Tools.h"

void body() {
	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	//upper body
	glPushMatrix();
	glColor3f(0.4f, 0.05f, 0.05f);
	glTranslatef(0.0f, 0.65f, 0.0f);
	glScalef(1.2, 1.2, 1.0);
	float x1 = 0.15, y1 = 0.05,
		x2 = 0.25, y2 = 0.0,
		x3 = 0.15, y3 = -0.31,
		x4 = -0.15, y4 = -0.31,
		x5 = -0.25, y5 = 0.0,
		x6 = -0.15, y6 = 0.05,
		z0 = 0.1, z1 = -0.1;

	float body[14] = { x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6,z0,z1 };
	my3DPolygon(body, sizeof(body) / sizeof(body[0]));
	glPopMatrix();

	//Body pyramids
	glPushMatrix();
	glColor3f(0.7f, 0.35f, 0.35f);

	//Top Pyramid
	glPushMatrix();
	glTranslatef(0.0f, 0.60f, -0.1f);
	glRotatef(-167, 1.0, 0, 0);
	glScalef(0.45, 0.125, 0.325);
	pyramid();
	glPopMatrix();

	//Middle Pyramid
	glPushMatrix();
	glTranslatef(0.0f, 0.475f, -0.1f);
	glRotatef(-153, 1.0, 0, 0);
	glScalef(0.35, 0.125, 0.3);
	pyramid();
	glPopMatrix();

	//Bottom Pyramid
	glPushMatrix();
	glTranslatef(0.0f, 0.35f, -0.1f);
	glRotatef(-140, 1.0, 0, 0);
	glScalef(0.25, 0.125, 0.25);
	pyramid();
	glPopMatrix();

	glPopMatrix();

	//Top Pipe
	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(0.0f, 0.62f, -0.16f);
	cylinder2(0.03, 0.42);
	glPopMatrix();

	//Middle Pipe
	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(0.0f, 0.515f, -0.16f);
	cylinder2(0.03, 0.31);
	glPopMatrix();

	//Bottom Pipe
	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(0.0f, 0.4f, -0.16f);
	cylinder2(0.03, 0.23);
	glPopMatrix();

	//Left Pipe
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(-0.17f, 0.48f, -0.1f);
	glRotated(107,0, 0, 1);
	cylinder2(0.06, 0.38);
	glPopMatrix();

	//Right Pipe
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(0.17f, 0.48f, -0.1f);
	glRotated(-107, 0, 0, 1);
	cylinder2(0.06, 0.38);
	glPopMatrix();

	//Back Pyramid
	glPushMatrix();
	glTranslatef(0.0f, 0.65f, 0.15f);
	glScalef(0.5, 0.35, 0.2);
	glRotatef(100, 1.0, 0, 0);
	glColor3f(0.7f, 0.35f, 0.35f);
	pyramid();
	glPopMatrix();

	//Back Left Pipe
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(0.17f, 0.44f, 0.11f);
	glRotated(20, 1, 0, 0);
	glRotated(-107, 0, 0, 1);
	cylinder2(0.08, 0.47);
	glPopMatrix();

	//Back Right Pipe
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(-0.17f, 0.44f, 0.11f);
	glRotated(20, 1, 0, 0);
	glRotated(107, 0, 0, 1);
	cylinder2(0.08, 0.47);
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

	//Waist Pipe
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(0.0f, -0.12f, 0.0f);
	cylinder2(0.07, 0.5);
	glPopMatrix();

	//Small Waist Pipe
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, -0.12f, 0.0f);
	cylinder2(0.05, 0.55);
	glPopMatrix();
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