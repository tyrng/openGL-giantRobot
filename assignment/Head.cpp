#include "BodyParts.h"

//POSITIONING THE BODY PARTS
void head() {
	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	//Head
	glPushMatrix();
	glTranslatef(0.0f, 0.77f, 0.0f);
	glColor3f(0.9f, 0.9f, 0.9f);
	gluSphere(var, 0.1, 20, 20);

	//Left eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(-0.05f, 0.01f, -0.08f);
	gluSphere(var, 0.015, 20, 20);
	glPopMatrix();

	//Right eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.01f, -0.08f);
	gluSphere(var, 0.015, 20, 20);
	glPopMatrix();

	gluQuadricTexture(var, GL_FALSE);
	//Helmet
	glPushMatrix();
	glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
	glRotatef(90, 0.0, 1.0, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluSphere(var, 0.15, 30, 30);
	glPopMatrix();

	glPopMatrix();

	gluDeleteQuadric(var);
}