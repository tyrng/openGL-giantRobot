#include "BodyParts.h"
#include "Tools.h"

void sword() {
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glScalef(2, 0.2, 0.5);
	glScalef(0.3, 0.3, 0.3);
	glColor3f(0.4, 0.4, 0.4);
	cube();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0.2, -0.2, 0);
	glScalef(0.5, 0.7, 0.5);
	glScalef(0.3, 0.3, 0.3);
	glColor3f(0.2, 0.2, 0.2);
	cube();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0.075, 0.28, 0);
	glScalef(0.5, 1, 10);
	glScalef(0.25, 0.25, 0.25);
	glColor3f(1, 1, 1);
	pyramid();
	glPopMatrix();
}

void shield() {

	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glScalef(1.3, 1.8, 0.7);
	glRotatef(175, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.35, 0.0, 0.15, 6, 6);
	glPopMatrix();

	gluDeleteQuadric(var);
}

void laserL(float laserSize) {
	glPushMatrix();
	glTranslatef(0.0f, 0.69f, 0.0f);
	glPushMatrix();
	glTranslatef(-0.25f, 0.15f, -0.3f);
	glPushMatrix();
	//glTranslatef(-0.05, 0.78, -0.25);
	glRotatef(90, 0, 1, 0);
	glScalef(laserSize, laserSize, laserSize);
	glColor3f(1, 1, 0);
	cylinder2(0.01, 0.05);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void laserR(float laserSize) {
	glPushMatrix();
	glTranslatef(0.0f, 0.69f, 0.0f);
	glPushMatrix();
	glTranslatef(0.25f, 0.15f, -0.3f);
	glPushMatrix();
	//glTranslatef(-0.05, 0.78, -0.25);
	glRotatef(90, 0, 1, 0);
	glScalef(laserSize, laserSize, laserSize);
	glColor3f(1, 1, 0);
	cylinder2(0.01, 0.05);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}