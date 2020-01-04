#include "BodyParts.h"
#include "Tools.h"

//POSITIONING THE BODY PARTS
void head() {
	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	glPushMatrix();
	glTranslatef(0.0f, 0.69f, 0.0f);

	//Head
	glPushMatrix();
	glTranslatef(0.0f, 0.27f, 0.0f);
	glRotatef(-90, 0, 0, 1);
	glColor3f(0.9f, 0.9f, 0.9f);
	cylinder2(0.15, 0.5);
	glPopMatrix();

	//Headplate
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	float 
		x1 = 0.15, y1 = 0.2,
		x2 = 0.0, y2 = 0.4,
		x3 = -0.15, y3 = 0.2,
		x4 = -0.25, y4 = 0.15,
		x5 = -0.25, y5 = -0.15,
		x6 = -0.15, y6 = -0.2,
		x7 = 0.0, y7 = -0.4,
		x8 = 0.15, y8 = -0.2,
		x9 = 0.25, y9 = -0.15,
		x10 = 0.25, y10 = 0.15,
		z0 = 0.01, z1 = -0.04;

	float headPlate[22] = { x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,z0,z1 };
	my3DPolygon(headPlate, sizeof(headPlate) / sizeof(headPlate[0]));
	glPopMatrix();

	//PlatespikeL
	glPushMatrix();
	glRotatef(-20, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
		x1 = -0.4, y1 = 0.15,
		x2 = -0.2, y2 = 0.15,
		x3 = -0.2, y3 = -0.03,
		z0 = 0.05, z1 = 0.01;

	float platespikeL[8] = { x1,x2,x3,y1,y2,y3,z0,z1 };
	my3DPolygon(platespikeL, sizeof(platespikeL) / sizeof(platespikeL[0]));
	glPopMatrix();

	//PlatespikeR
	glPushMatrix();
	glRotatef(20, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
		x1 = 0.4, y1 = 0.15,
		x2 = 0.2, y2 = 0.15,
		x3 = 0.2, y3 = -0.03,
		z0 = 0.05, z1 = 0.01;

	float platespikeR[8] = { x1,x2,x3,y1,y2,y3,z0,z1 };
	my3DPolygon(platespikeR, sizeof(platespikeR) / sizeof(platespikeR[0]));
	glPopMatrix();

	//Peacock
	glPushMatrix();
	glColor3f(0.3f, 0.3f, 0.3f);
		x1 = 0.025, y1 = 0.1,
		x2 = -0.025, y2 = 0.1,
		x3 = -0.025, y3 = 0.55,
		x4 = 0.025, y4 = 0.55,
		z0 = 0.2, z1 = -0.2;

	float peacock[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(peacock, sizeof(peacock) / sizeof(peacock[0]));
	glPopMatrix();

	//RocketLauncherL
	glPushMatrix();
	glTranslatef(-0.25f, 0.17f, -0.07f);
	glRotatef(-80, 0, 1, 0);

	glPushMatrix();
	glColor3f(0.4f, 0.4f, 0.4f);
	cylinder2(0.1, 0.45, 0.7*255, 0.7 * 255, 0.7 * 255);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.03, 0, 0);
	glColor3f(0.3f, 0.3f, 0.3f);
	cylinder2(0.11, 0.2, 0.1 * 255, 0.1 * 255, 0.1 * 255);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.13, 0, 0);
	glColor3f(0.2f, 0.2f, 0.2f);
	cylinder2(0.12, 0.2, 0.1 * 255, 0.1 * 255, 0.1 * 255);
	glPopMatrix();

	glPopMatrix();

	//RocketLauncherR
	glPushMatrix();
	glTranslatef(0.25f, 0.17f, -0.07f);
	glRotatef(-100, 0, 1, 0);

	glPushMatrix();
	glColor3f(0.4f, 0.4f, 0.4f);
	cylinder2(0.1, 0.45, 0.7 * 255, 0.7 * 255, 0.7 * 255);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.03, 0, 0);
	glColor3f(0.3f, 0.3f, 0.3f);
	cylinder2(0.11, 0.2, 0.1 * 255, 0.1 * 255, 0.1 * 255);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.13, 0, 0);
	glColor3f(0.2f, 0.2f, 0.2f);
	cylinder2(0.12, 0.2, 0.1 * 255, 0.1 * 255, 0.1 * 255);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	gluDeleteQuadric(var);
}