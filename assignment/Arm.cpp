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
	//Cylinder pipe boosters
	glTranslatef(p, 0.6f, 0.0f);
	glScalef(1.1, 1.1, 1.0);
	glRotatef(-20, 1.0, 0.0, 0.0);
	glColor3f(0.14, 0.04, 0.35);
	gluCylinder(var, 0.08, 0.04, 0.4, 10, 10);
	glPopMatrix();


	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glPushMatrix();
	//Cylinder spikes
	glTranslatef(p, 0.52f, -0.05f);
	glRotatef(140, 1.0, 0.0, 0.0);
	glColor3f(0.14, 0.04, 0.35);
	gluCylinder(var, 0.06, 0.0, 0.12, 6, 6);
	glPopMatrix();
	
	//SPIKE #2 MID SPIKE
	glPushMatrix();
	glTranslatef(p, 0.61f, -0.09f);
	glRotatef(180, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.08, 0.0, 0.15, 6, 6);
	glPopMatrix();

	//SPIKE #3
	glTranslatef(p, 0.7f, -0.04f);
	glRotatef(250, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.06, 0.0, 0.09, 6, 6);

	glPopMatrix();


	//CYLINDER AETHETIC
	glPushMatrix();
	glTranslatef(p, 0.6f, 0.0f);

	glColor3f(0.51, 0.62, 0.85);
	cylinder2(0.07, 0.29);

	glPopMatrix();




	//000 BALL OF DOOM!
	glPushMatrix();
	glTranslatef(p, 0.6f, 0.0f);
	glScalef(1.1, 1.1, 1.0);
	glRotatef(-10, 1.0, 0.0, 0.0);

	glColor3f(0.0, 0.16, 0.98);
	gluSphere(var, 0.13, 8, 8);

	glPopMatrix();


	//BLOCKY ARM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	glPushMatrix();

	glRotatef(-10, 1.0, 0.0, 0.0);
	glTranslatef(p-0.07f, 0.165f, 0.10f);
	glScalef(0.65, 0.65, 0.65);

	//cuboid!@!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	glColor3f(0.4, 0.4, 0.98);

	float x1 = 0.0, y1 = 0.45,
		x2 = 0.22, y2 = 0.45,
		x3 = 0.22, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.1, z1 = -0.1;

	float topArm[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(topArm, sizeof(topArm) / sizeof(topArm[0]));

	glPopMatrix();

	//ADDITIONAL ARMOUR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! COME AND CHECK ME !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	glPushMatrix();

	glColor3f(0.14, 0.04, 0.35);
	glRotatef(-25, 1.0, 0.0, 0.0);
	glTranslatef(p - 0.04f, 0.23f, 0.14f);
	glScalef(0.4, 0.4, 0.4);

	my3DPolygon(topArm, sizeof(topArm) / sizeof(topArm[0]));



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
	glColor3f(0.0, 0.16, 0.98);

	glTranslatef(p, 0.25f, 0.05f);

	glScalef(1.1, 1.1, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(var, 0.1, 0.06, 0.3, 10, 10);

	glColor3f(0.14, 0.04, 0.35);
	glTranslatef(0.0f, 0.05f, 0.0f);
	glScalef(1.0, 0.53, 1.0);
	glRotatef(140, 1.0, 0.0, 0.0);
	myElbow();
	glPopMatrix();

	//CYLINDER AESTHETICSSSSSSSSSS
	glPushMatrix();

	glTranslatef(p, 0.25f, 0.05f);
	glColor3f(0.51, 0.62, 0.85);
	cylinder2(0.05, 0.21);


	glPopMatrix();

	//MOARRRRR PLATE ARMOURRRRR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	glPushMatrix();

	glColor3f(0.9f, 0.9f, 0.9f);
	glRotatef(15, 1.0, 0.0, 0.0); 

	glTranslatef(p-0.04, -0.037f, 0.0f);
	glScalef(0.35, 0.35, 0.35);
	
	float x1 = 0.0, y1 = 0.45,
		x2 = 0.22, y2 = 0.45,
		x3 = 0.22, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.08, z1 = -0.08;

	float plate[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(plate, sizeof(plate) / sizeof(plate[0]));

	glPopMatrix();

	//SECOND ARMOURRRR!!!!!!!!!!

	glPushMatrix();

	glColor3f(0.6f, 0.6f, 0.6f);
	glRotatef(15, 1.0, 0.0, 0.0);

	glTranslatef(p - 0.0365, 0.0f, -0.022f);
	glScalef(0.35, 0.35, 0.35);

	x1 = 0.0, y1 = 0.45,
		x2 = 0.20, y2 = 0.45,
		x3 = 0.20, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.08, z1 = -0.08;

	float plate2[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(plate2, sizeof(plate2) / sizeof(plate2[0]));

	glPopMatrix();

	//THIURDDDDDD FCKING  ARMOURRRR!!!!!!!!!!

	glPushMatrix();

	glColor3f(0.4f, 0.4f, 0.4f);
	glRotatef(15, 1.0, 0.0, 0.0);

	glTranslatef(p - 0.029, 0.0375f, -0.035f);
	glScalef(0.35, 0.35, 0.35);

	x1 = 0.0, y1 = 0.45,
		x2 = 0.16, y2 = 0.45,
		x3 = 0.16, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.08, z1 = -0.08;

	float plate3[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };

	my3DPolygon(plate3, sizeof(plate3) / sizeof(plate3[0]));

	glPopMatrix();

	//ANOTHER BALL OF DOOM IN LOWER ARM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	glPushMatrix();
	glTranslatef(p, 0.12f, -0.019f);

	glColor3f(0.14, 0.04, 0.35);
	gluSphere(var, 0.04, 16, 16);

	glPopMatrix();

	//CYLINDER OF CONECTOR TO THE PALMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	glPushMatrix();
	glTranslatef(p, -0.07f, 0.052f);

	glColor3f(0.51, 0.62, 0.85);
	cylinder2(0.04, 0.15);

	glPopMatrix();


	//PALMS WEAK ARMS A HEAVY MOMS SPAGETTTTT!!!!!!!!!!!!!!!!!!!!!!!!!!!
	glPushMatrix();

	glColor3f(0.14, 0.04, 0.35);
	glRotatef(10, 1.0, 0, 0);
	glTranslatef(p - 0.0718, -0.083f, 0.018f);
	glScalef(0.35, 0.35, 0.35);

	x1 = 0.0, y1 = 0.1,
		x2 = 0.41, y2 = 0.1,
		x3 = 0.41, y3 = 0,
		x4 = 0, y4 = 0,
		z0 = 0.08, z1 = -0.08;

	float cubeCon[10] = { x1,x2,x3,x4,y1,y2,y3,y4,z0,z1 };
	my3DPolygon(cubeCon, sizeof(cubeCon) / sizeof(cubeCon[0]));

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

	//Palm MAGICCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
	glPushMatrix();
	glColor3f(0.0, 0.16, 0.98);
	glTranslatef(p*0.39, -0.07f, 0.05f);
	glRotatef(-98, 0.0, 1.0, 0.0);
	glRotatef(p, 1.0, 0.0, 0.0);

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
	glColor3f(0.51, 0.62, 0.85);
	glTranslatef(p*0.39, -0.07f, 0.05f);
	glRotatef(-100, 0.0, 1.0, 0.0);
	glRotatef(p * 5, 1.0, 0.0, 0.0);

	//Thumb
	glPushMatrix();
	glColor3f(0.51, 0.62, 0.85);
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
	glColor3f(0.51, 0.62, 0.85);
	glTranslatef(-0.04f, -0.2f, 0.0f);
	//glRotatef(n * angleM, 1.0, 0.0, 0.0);
	myFinger(0.05);

	glTranslatef(0.0f, -0.05f, 0.0f);
	glRotatef(n * 45, 1.0, 0.0, 0.0);
	glRotatef(n * angleD, 1.0, 0.0, 0.0);
	myFinger(0.05);
	glPopMatrix();

	//Middle finger
	glPushMatrix();
	glColor3f(0.51, 0.62, 0.85);
	glTranslatef(-0.01f, -0.2f, 0.0f);
	glRotatef(n * angleM, 1.0, 0.0, 0.0);
	myFinger(0.05);

	glTranslatef(0.0f, -0.05f, 0.0f);
	glRotatef(n * 45, 1.0, 0.0, 0.0);
	glRotatef(n * angleD, 1.0, 0.0, 0.0);
	myFinger(0.05);
	glPopMatrix();

	//Ring finger
	glPushMatrix();
	glColor3f(0.51, 0.62, 0.85);
	glTranslatef(0.02f, -0.2f, 0.0f);
	glRotatef(n * angleM, 1.0, 0.0, 0.0);
	myFinger(0.05);

	glTranslatef(0.0f, -0.05f, 0.0f);
	glRotatef(n * 45, 1.0, 0.0, 0.0);
	glRotatef(n * angleD, 1.0, 0.0, 0.0);
	myFinger(0.05);
	glPopMatrix();

	//Pinkie
	glPushMatrix();
	glColor3f(0.51, 0.62, 0.85);
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