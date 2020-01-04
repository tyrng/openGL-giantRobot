#include "Tools.h"

void cube() {
	glBegin(GL_QUADS);
	//bottom
	//glColor3f(1, 0, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1, 0, 1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);

	//left
	//glColor3f(0, 0, 1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 1, 1);

	//right
	//glColor3f(0, 1, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1, 0, 1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, 0, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(1, 1, 1);

	//front
	//glColor3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, 0, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1, 1, 1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 1, 1);

	//back
	//glColor3f(1, 1, 0);		
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 1, 0);

	//top
	//glColor3f(1, 0, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 1, 1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, 1, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1, 1, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 1, 0);

	glEnd();
}


void cylinder2(float radius,float height,int sideR,int sideG,int sideB)
{
	float x = 0.0;
	float y = 0.0;
	float angle = 0.0;
	float angle_stepsize = 0.1;

	glTranslatef(-height / 2, 0, 0);
	glRotated(-90, 0, 0, 1);
	glRotated(-90, 1.0, 0, 0);

	/** Draw the tube */
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * M_PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glTexCoord2f(x, height);
		glVertex3f(x, y, height);
		glTexCoord2f(x, 0.0);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glTexCoord2f(radius, height);
	glVertex3f(radius, 0.0, height);
	glTexCoord2f(radius, 0.0);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	/** Draw the circle on bottom of cylinder */
	if (sideR != NULL && sideG != NULL && sideB != NULL)
		glColor3ub(sideR, sideG, sideB);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * M_PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glTexCoord2f(x, 0);
		glVertex3f(x, y, 0);
		angle = angle + angle_stepsize;
	}
	glTexCoord2f(radius, 0);
	glVertex3f(radius, 0.0, 0);
	glEnd();

	/** Draw the circle on top of cylinder */
	if (sideR != NULL && sideG != NULL && sideB != NULL)
		glColor3ub(sideR, sideG, sideB);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * M_PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glTexCoord2f(x, 0);
		glVertex3f(x, y, height);
		angle = angle + angle_stepsize;
	}
	glTexCoord2f(radius, height);
	glVertex3f(radius, 0.0, height);
	glEnd();
}

void cylinder() {
	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);
	gluCylinder(var, 0.01, 0.01, 1, 5, 1); //base radius, topRadius, height, slices, stacks
	gluQuadricDrawStyle(var, GLU_FILL);
}

void cuboid() {
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	//front
	glVertex3f(0, 0.6, 0);
	glVertex3f(0.3, 0.6, 0);
	glVertex3f(0.3, 0, 0);
	glVertex3f(0, 0, 0);
	//left
	glVertex3f(0, 0.6, 0);
	glVertex3f(0, 0.6, 0.3);
	glVertex3f(0, 0, 0.3);
	glVertex3f(0, 0, 0);
	//back
	glVertex3f(0, 0.6, 0.3);
	glVertex3f(0.3, 0.6, 0.3);
	glVertex3f(0.3, 0, 0.3);
	glVertex3f(0, 0, 0.3);
	//right
	glVertex3f(0.3, 0.6, 0.3);
	glVertex3f(0.3, 0.6, 0);
	glVertex3f(0.3, 0, 0);
	glVertex3f(0.3, 0, 0.3);
	//top
	glVertex3f(0, 0.6, 0.3);
	glVertex3f(0.3, 0.6, 0.3);
	glVertex3f(0.3, 0.6, 0);
	glVertex3f(0, 0.6, 0);
	//bottom
	glVertex3f(0, 0, 0.3);
	glVertex3f(0.3, 0, 0.3);
	glVertex3f(0.3, 0, 0);
	glVertex3f(0, 0, 0);
	glEnd();
}

void pyramid()
{
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(2, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0, 0, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-2, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, 0.5, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0, 0, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -2, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.5, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0, 0, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 2, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0, 0, 1);
	glEnd();
}

//CREATING POLYGONS
void my3DPolygon(float polygon[], int numOfElements) {

	//int numOfElements = sizeof(polygon)/ sizeof(polygon[0]);
	int size = int(numOfElements / 2) - 1;
	float z0 = polygon[numOfElements - 1];
	float z1 = polygon[numOfElements - 2];

	//OUTPUT-------------------------------------------------------
	char str[256];
	sprintf_s(str, "It works! - number: %d \n", numOfElements);
	OutputDebugString(str);
	//-------------------------------------------------------------

	float xMax = 0, xMin = 10, yMax = 0, yMin = 10, xLen = 0, yLen = 0, scale = 1;
	float texelX = 0, texelY = 0;

	//determining texels 
	for (int i = 0; i < size; i++) {
		if (polygon[i] < xMin) { xMin = polygon[i]; }
		if (polygon[i] > xMax) { xMax = polygon[i]; }
		if (polygon[i + size] < yMin) { yMin = polygon[i]; }
		if (polygon[i + size] > yMax) { yMax = polygon[i]; }
	}

	xLen = xMax - xMin;
	yLen = yMax - yMin;
	if (xLen > yLen) { scale = xLen; }
	else { scale = yLen; }

	//front
	glBegin(GL_POLYGON);
	for (int i = 0; i < size; i++) {
		texelX = (polygon[i] - xMin) / scale;
		texelY = (polygon[i + size] - yMin) / scale;
		glTexCoord2f(texelX, texelY);
		glVertex3f(polygon[i], polygon[i + size], z0);
	}
	glEnd();
	//back
	glBegin(GL_POLYGON);
	for (int i = 0; i < size; i++) {
		texelX = (polygon[i] - xMin) / scale;
		texelY = (polygon[i + size] - yMin) / scale;
		glTexCoord2f(texelX, texelY);
		glVertex3f(polygon[i], polygon[i + size], z1);
	}
	glEnd();

	//middle
	glBegin(GL_QUADS);
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			glTexCoord2f(0, 0);
			glVertex3f(polygon[0], polygon[size], z1);
			glTexCoord2f(0, 0.5);
			glVertex3f(polygon[i], polygon[i + size], z1);
			glTexCoord2f(0.5, 0.5);
			glVertex3f(polygon[i], polygon[i + size], z0);
			glTexCoord2f(0.5, 0);
			glVertex3f(polygon[0], polygon[size], z0);
		}
		else {
			glTexCoord2f(0, 0);
			glVertex3f(polygon[i], polygon[i + size], z1);
			glTexCoord2f(0, 0.5);
			glVertex3f(polygon[i + 1], polygon[i + size + 1], z1);
			glTexCoord2f(0.5, 0.5);
			glVertex3f(polygon[i + 1], polygon[i + size + 1], z0);
			glTexCoord2f(0.5, 0);
			glVertex3f(polygon[i], polygon[i + size], z0);
		}
	}
	glEnd();

}