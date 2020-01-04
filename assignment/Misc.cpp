#include "BodyParts.h"
#include "Tools.h"

void myThorn() {
	glBegin(GL_TRIANGLES);
	//up right
	glColor3f(0.1f, 0.1f, 0.1f);
	glTexCoord2f(0, 0);
	glVertex3f(0.0, 0.0, -0.05);
	glTexCoord2f(0, 0.5);
	glVertex3f(0.0, 0.1, 0.0);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0.1, 0.0, 0.0);
	//down right
	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0, 0);
	glVertex3f(0.0, 0.0, -0.05);
	glTexCoord2f(0, 0.5);
	glVertex3f(0.1, 0.0, 0.0);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0.0, -0.1, 0.0);
	//down left
	glColor3f(0.9f, 0.9f, 0.9f);
	glTexCoord2f(0, 0);
	glVertex3f(0.0, 0.0, -0.05);
	glTexCoord2f(0, 0.5);
	glVertex3f(0.0, -0.1, 0.0);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(-0.1, 0.0, 0.0);
	//top left
	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0, 0);
	glVertex3f(0.0, 0.0, -0.05);
	glTexCoord2f(0, 0.5);
	glVertex3f(-0.1, 0.0, 0.0);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0.0, 0.1, 0.0);
	glEnd();
}

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
	glScalef(0.5, 1, 5);
	glScalef(0.25, 0.25, 0.25);
	glColor3f(1, 1, 1);
	pyramid();
	glPopMatrix();
}

void shield() {
	glPushMatrix();
	glScalef(0.05, 1, 1);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0.2, 0.2, 0.2);
	cube();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.05, 1, 1);
	glScalef(0.5, 0.5, 0.5);
	glTranslatef(2, 0.5, -0.2);
	glRotatef(45, 1, 0, 0);
	glColor3f(0.4, 0.4, 0.4);
	cube();
	glPopMatrix();
}

void myYogaMat() {

	float x1 = -0.9, y1 = -0.45,
		x2 = 0.9, y2 = -0.45,
		x3 = 0.9, y3 = -0.55,
		x4 = -0.9, y4 = -0.55,

		z0 = 0.7, z1 = -0.7;

	float mat[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(mat, sizeof(mat) / sizeof(mat[0]));
}

void sunglasses() {
	glPushMatrix();
	glTranslatef(1, 1, 0);
	glRotatef(90, 0, 0, 1);
	cuboid();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.3, 0.3);
	glTranslatef(3.9, 3.8, 0);
	glRotatef(90, 0, 0, 1);
	cuboid();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.7, 1, 0);
	glRotatef(90, 0, 0, 1);
	cuboid();
	glPopMatrix();
}

void ball() {
	glColor3f(1, 0.5, 0.2);
	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);
	gluSphere(var, 0.1, 20, 10);
}

void lasers() {
	glPushMatrix();
	glTranslatef(0.05, 0.78, -0.25);
	glScalef(1, 1, 0.2);
	glColor3f(1, 1, 0);
	cylinder();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.05, 0.78, -0.25);
	glScalef(1, 1, 0.2);
	glColor3f(1, 1, 0);
	cylinder();
	glPopMatrix();
}

void topHat() {
	glPushMatrix();
	glTranslatef(-0.05, 0.9, -0.05);
	glScalef(1, 1, 1);
	glScalef(0.1, 0.1, 0.1);
	glColor3f(0.1, 0.1, 0.1);
	cube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1, 0.9, -0.1);
	glScalef(2, 0.2, 2);
	glScalef(0.1, 0.1, 0.1);
	glColor3f(0, 0, 0);
	cube();
	glPopMatrix();
}