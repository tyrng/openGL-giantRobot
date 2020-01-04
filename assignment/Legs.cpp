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
	glTranslatef(0.0f, 0.91f, 0.02f);
	gluSphere(var, 0.125, 8, 8);
	glPopMatrix();

	//Upper Leg (ULTRA PLATED LEG EXPANSION TO THE MAX SUZUKI MAYO NIECE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
	glPushMatrix();
	glColor3f(0.47f, 0.05f, 0.05f);

	glTranslatef((p*0.142) - 0.074, 0.11f, 0.0f);

	glScalef(0.74, 0.6, 0.8);
	glRotatef(185, 1.0, 0.0, 0.0);

	float x1 = 0.0, y1 = 0.4,
		x2 = 0.2, y2 = 0.4,
		x3 = 0.2, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.1, z1 = -0.1;

	float legPiece [10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(legPiece, sizeof(legPiece) / sizeof(legPiece[0]));


	glPopMatrix();

	//Upper CROSS CUT FAN PART !!!!!!!!!!!!!!!!!!!!!
	glPushMatrix();
	glColor3f(0.8f, 0.5f, 0.5f);

	glTranslatef((p*0.142) - 0.076, -0.15f, 0.0f);

	glScalef(0.76, 0.6, 0.31);
	glRotatef(295, 1.0, 0.0, 0.0);

	x1 = 0.0, y1 = 0.4,
		x2 = 0.2, y2 = 0.4,
		x3 = 0.2, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.1, z1 = -0.1;

	float legFan[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(legFan, sizeof(legFan) / sizeof(legFan[0]));

	glPopMatrix();

	//Upper JOINT bone structyre BY ONG JON SHEN ITS ME? DUHH !!!!!!!!!!!!!!!!!!!!!
	glPushMatrix();
	glColor3f(0.47f, 0.05f, 0.05f);

	glTranslatef((p*0.142) - 0.074, -0.05f, -0.03f);

	glScalef(0.74, 0.6, 0.7);
	glRotatef(175, 1.0, 0.0, 0.0);

	x1 = 0.0, y1 = 0.4,
		x2 = 0.2, y2 = 0.4,
		x3 = 0.2, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.1, z1 = -0.1;

	float jointBone[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(jointBone, sizeof(jointBone) / sizeof(jointBone[0]));

	glPopMatrix();

	//UPPER LEGGGG ElboW JOINT CYLINDERRRRRRRRRRRRRRRRRRRRRRRRRR
	glPushMatrix();
	
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef((p*0.142), -0.14f, -0.01f);
	cylinder2(0.06, 0.175);

	glPopMatrix();
	//==========================================================


	gluDeleteQuadric(var);
}

void lowerLeg(char position) {

	float p = 0.0;
	if (position == 'L') { p = -1; }
	else if (position == 'R') { p = 1; }

	GLUquadricObj *var = NULL;
	var = gluNewQuadric();
	gluQuadricTexture(var, GL_TRUE);

	//Whole LOWER Leg SECTION NSNSNNSSNNSNS
	glPushMatrix();
	glTranslatef(p*0.142f, -0.39f, 0.0f);

	//Lower Leg SHIELDDDDDDDDDDSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
	
	//Front
	glPushMatrix();
	glColor3f(0.8f, 0.5f, 0.5f);
	glTranslatef(0.0f, 0.032f, -0.04f);
	glScalef(1.05, 1.56, 0.75);
	glRotatef(77, 1.0, 0.0, 0.0);
	myElbow();
	glPopMatrix();

	//Back Boneeeee HEEEEEEEEEEEEEEEEEEEEEEEHEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
	glPushMatrix();
	glColor3f(0.6f, 0.05f, 0.05f);
	glScalef(0.74, 0.87, 0.63);
	glTranslatef(-0.099f, 0.13f, -0.00f);
	glRotatef(181, 1.0, 0.0, 0.0);
	
	float x1 = 0.0, y1 = 0.4,
		x2 = 0.2, y2 = 0.4,
		x3 = 0.2, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.1, z1 = -0.1;

	float backBone[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(backBone, sizeof(backBone) / sizeof(backBone[0]));
	glPopMatrix();

	//LOWER SHIELD ANKLEEEEE H0000000000000000000000000000000000000000000000000000
	glPushMatrix();
	glColor3f(0.8f, 0.8f, 0.8f);
	glScalef(0.95, 0.15, 0.63);
	glTranslatef(0.0003f, -1.85f, -0.15f);

	glRotatef(-3, 1.0, 0.0, 0.0);
	glRotatef(270, 0.0, 1.0, 0.0);

	x1 = 0.0, y1 = 0.8,
		x2 = 0.2, y2 = 0.4,
		x3 = 0.2, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.1, z1 = -0.1;

	float ankle[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(ankle, sizeof(ankle) / sizeof(ankle[0]));
	glPopMatrix();


	//END OF SHARING 
	glPopMatrix();

	//UPPER LEGGGG ElboW JOINT CYLINDERRRRRRRRRRRRRRRRRRRRRRRRRR
	glPushMatrix();

	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef((p*0.142), -0.3f, -0.008f);
	cylinder2(0.06, 0.175);

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
	glTranslatef(p*0.142f, -0.39f, 0.0f);
	glScalef(0.8, 0.6, 0.8);

	//Left Feet
	//Feet
	glPushMatrix();
	glColor3f(0.4f, 0.05f, 0.05f);
	glTranslatef(0.0f, -0.54f, 0.0f);
	glRotatef(90, 0.0, 1.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);

	glScalef(1.2, 1.5, 1.6);

	myFeet();
	glPopMatrix();
	//Ankle
	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.07f);
	glTranslatef(0.0f, -0.45f, 0.05f);
	glScalef(0.6, 1.4, 1.4);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.15, 0.0, 0.1, 4, 4);
	glPopMatrix();
	//Toe
	glPushMatrix();
	glColor3f(0.7f, 0.05f, 0.05f);
	glTranslatef(0.0f, -0.44f, -0.08f);
	glRotatef(-130, 1.0, 0.0, 0.0);
	glScalef(0.5, 1.0, 1.0);
	gluCylinder(var, 0.2, 0.0, 0.1, 4, 4);
	glPopMatrix();
	glPopMatrix();

	gluDeleteQuadric(var);
}