#include <GL/glut.h>
#include <math.h>

#define BASE_HEIGHT 16.0/2
#define BASE_RADIUS 4.0/2
#define HEAD_HEIGHT 5.0/2
#define HEAD_RADIUS 3.0/2
#define NECK_HEIGHT 2.0/2
#define EYE_LEVEL 3.0/2
#define NOSE_LENGTH 2.0/2
#define LOWER_ARM_HEIGHT 8.0/2
#define LOWER_ARM_WIDTH 2.0/2
#define UPPER_ARM_HEIGHT 5.0/2
#define UPPER_ARM_WIDTH 2.0/2
#define ARM_TRANSLATION 0.88/2
#define UPPER_LEG_HEIGHT 4.0
#define UPPER_LEG_WIDTH  0.6
#define LEG_TRANSLATION 3.5
#define LOWER_LEG_HEIGHT 3.5
#define LOWER_LEG_WIDTH  0.6
#define alpha 0.0
#define pi 3.14159265

static GLfloat theta[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
static GLint axis = 0;
GLUquadricObj *p;
GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat xpos = 0.0;
GLfloat ypos = 0.0;
GLfloat zpos = 0.0;
GLfloat ambient[3];
GLfloat diffuse[3];
GLfloat specular[3];
GLfloat shiness[] = { 50.0f };
float width = 500;
float height = 500;
void base(void);
void head(void);
void neck(void);
void upper_rarm(void);
void upper_larm(void);
void lower_rarm(void);
void lower_larm(void);
void left_upper_leg(void);
void right_upper_leg(void);
void left_lower_leg(void);
void right_lower_leg(void);
void init(void);
void display(void);
void reshape(int width, int height);
void processSpecialKeys(int, int, int);
void lsphere(void);
void init1(void);

void base(void) {
	double angle, angleInc;
	int i;
	angle = pi / 180;
	angleInc = angle;
	glPushMatrix();

	ambient[0] = 1.0; ambient[1] = 0.0; ambient[2] = 0.0;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluQuadricDrawStyle(p, GLU_FILL);
	gluCylinder(p, BASE_RADIUS, BASE_RADIUS, BASE_HEIGHT, 20, 20);

	glPopMatrix();

	glPushMatrix();

	gluQuadricDrawStyle(p, GLU_FILL);
	glTranslatef(0.0, BASE_HEIGHT, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluDisk(p, 0.0, BASE_RADIUS, 20, 20);
	glTranslatef(0.0, 0.0, -BASE_HEIGHT);
	gluDisk(p, 0.0, BASE_RADIUS, 20, 20);
	glPopMatrix();
}


void neck(void) {
	glPushMatrix();

	ambient[0] = 1.0; ambient[1] = 1.0; ambient[2] = 0.0;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, BASE_HEIGHT, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluQuadricDrawStyle(p, GLU_FILL);
	gluCylinder(p, HEAD_RADIUS / 2, HEAD_RADIUS / 2, HEAD_HEIGHT, 8, 6);
	glPopMatrix();
}

void head(void) {
	glPushMatrix();

	ambient[0] = 1.0; ambient[1] = 0.0; ambient[2] = 1.0;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluQuadricDrawStyle(p, GLU_FILL);
	gluCylinder(p, HEAD_RADIUS, HEAD_RADIUS, HEAD_HEIGHT, 20, 20);

	glPushMatrix();

	gluDisk(p, 0.0, HEAD_RADIUS, 20, 20);
	glTranslatef(0.0, 0.0, HEAD_HEIGHT);
	gluDisk(p, 0.0, HEAD_RADIUS, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.25, -HEAD_RADIUS + 0.12, EYE_LEVEL);

	ambient[0] = 1.0; ambient[1] = 1.0; ambient[2] = 1.0;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	gluQuadricDrawStyle(p, GLU_FILL);
	gluSphere(p, 0.250, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25, -HEAD_RADIUS + 0.12, EYE_LEVEL);
	ambient[0] = 1.0; ambient[1] = 1.0; ambient[2] = 1.0;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);


	gluQuadricDrawStyle(p, GLU_FILL);
	gluSphere(p, 0.250, 10, 10);
	glPopMatrix();

	glPushMatrix();
	ambient[0] = 1.0; ambient[1] = 0.5; ambient[2] = 0.0;
	diffuse[0] = 1.0; diffuse[1] = 0.5; diffuse[2] = 0.0;
	specular[0] = 0.5; specular[1] = 0.5; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
	glTranslatef(0.0, -HEAD_RADIUS, NOSE_LENGTH);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluQuadricDrawStyle(p, GLU_FILL);
	gluCylinder(p, 0.125, 0, NOSE_LENGTH, 10, 8);
	glPopMatrix();

	glPopMatrix();
}

void lower_rarm(void) {
	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 1.0; ambient[2] = 0.0;
	diffuse[0] = 0.0; diffuse[1] = 1.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * LOWER_ARM_HEIGHT, ARM_TRANSLATION);
	glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

void lower_larm(void) {
	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 1.0; ambient[2] = 0.0;
	diffuse[0] = 0.0; diffuse[1] = 1.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * LOWER_ARM_HEIGHT, -ARM_TRANSLATION);
	glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();
}

void upper_rarm(void) {
	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 1.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.0, 0.5 * LOWER_ARM_HEIGHT, ARM_TRANSLATION);
	glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();

}

void upper_larm(void) {
	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 1.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0., 0.5 * UPPER_ARM_HEIGHT, -ARM_TRANSLATION);
	glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, UPPER_ARM_WIDTH);
	glutSolidCube(1.0);


	glPopMatrix();

}

void upper_lleg(void) {
	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 1.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.5, 0.5 * UPPER_LEG_HEIGHT, -LEG_TRANSLATION);
	glScalef(UPPER_LEG_WIDTH, UPPER_LEG_HEIGHT, UPPER_LEG_WIDTH);
	glutSolidCube(2.0);

	glPopMatrix();
}

void upper_rleg(void) {
	glPushMatrix();

	ambient[0] = 0.0; ambient[1] = 0.0; ambient[2] = 1.0;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.5, 0.5 * UPPER_LEG_HEIGHT, -LEG_TRANSLATION);
	glScalef(UPPER_LEG_WIDTH, UPPER_LEG_HEIGHT, UPPER_LEG_WIDTH);
	glutSolidCube(3.0);

	glPopMatrix();
}

void lower_lleg(void) {
	glPushMatrix();

	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.5, 0.5 * LOWER_LEG_HEIGHT, -LEG_TRANSLATION);
	glScalef(LOWER_LEG_WIDTH, LOWER_LEG_HEIGHT, LOWER_LEG_WIDTH);
	glutSolidCube(5.0);

	glPopMatrix();
}

void lower_rleg(void) {
	glPushMatrix();

	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(0.5, 0.5 * LOWER_LEG_HEIGHT, -LEG_TRANSLATION);
	glScalef(LOWER_LEG_WIDTH, LOWER_LEG_HEIGHT, LOWER_LEG_WIDTH);
	glutSolidCube(5.5);

	glPopMatrix();
}

/////figure() {
/////glPushMatrix()
/////	torso({
/////glPushMatrix();
//////glRotatef(-90.0, 1.0, 0.0, 0.0);
//////gluCylinder(t, TORSO_RADIUS / 1.2, TORSO_RADIUS, TORSO_HEIGHT, 10, 10);
///////glPopMatrix();
////////});
/////	glRotate3f();
/////	head();
/////	glPopMatrix();
/////	glPushMatrix();
/////	glTranslate3f();
/////	glRotate3f();
/////	left_upper_arm();
/////	glPopMatrix();
/////	glPushMatrix();
///// }



void init1(void) {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat white_light[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat lmodel_ambient[] = { 1.0, 1.0, 0.0, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void lsphere(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.3, 5.3, 12.0, 0.0, 1.25, 0.0, 0.0, 1.0, 0.0);

	glPushMatrix();
	ambient[0] = 1.0; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);


	glTranslatef(0.0, 5.0, 0.0);
	lsphere();
	glPopMatrix();

	glPushMatrix();
	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 0.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(3.0, 0.5, 1.0);

	glPopMatrix();

	glPushMatrix();
	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(-4.0, 0.5, 3.0);

	glPopMatrix();

	glPushMatrix();
	ambient[0] = 0.3; ambient[1] = 0.3; ambient[2] = 0.3;
	diffuse[0] = 1.0; diffuse[1] = 0.0; diffuse[2] = 0.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glTranslatef(-3.0, 0.5, -3.0);

	glPopMatrix();

	glPushMatrix();
	ambient[0] = 0.5; ambient[1] = 0.5; ambient[2] = 0.5;
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0;
	specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

	glPopMatrix();

	glTranslatef(xpos, ypos, zpos);
	glRotatef(theta[0], 0.0, 1.0, 0.0);
	base();
	neck();

	glPushMatrix();
	glTranslatef(0.0, BASE_HEIGHT + HEAD_HEIGHT / 2, 0.0);
	glRotatef(theta[2], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	head();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[4], 0.0, 0.0, 1.0);
	lower_rarm();
	glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[6], 0.0, 0.0, 1.0);
	upper_rarm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[3], 0.0, 0.0, 1.0);
	lower_larm();
	glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[5], 0.0, 0.0, 1.0);
	upper_larm();

	glPopMatrix();
	
	glPushMatrix();

	glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[3], 0.0, 0.0, 1.0);
	glTranslatef(-2.0, UPPER_LEG_HEIGHT+5, 4.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[5], 0.0, 0.0, 1.0);
	upper_lleg();

	glPushMatrix();
	
	glPushMatrix();

	glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[3], 0.0, 0.0, 1.0);
	glTranslatef(-1.0, UPPER_LEG_HEIGHT - 5, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[5], 0.0, 0.0, 1.0);
	upper_rleg();

	glPushMatrix();

	glPushMatrix();

	glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[3], 0.0, 0.0, 1.0);
	glTranslatef(-17.0, LOWER_LEG_HEIGHT +30, 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[7], 0.0, 0.0, 1.0);
	lower_lleg();

	glPushMatrix();

	glPushMatrix();

	glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glRotatef(theta[3], 0.0, 0.0, 1.0);
	glTranslatef(4.0, LOWER_LEG_HEIGHT-7 , 0.0);
	glRotatef(0.0, 0.0, 0.0, 180.0);
	glRotatef(theta[7], 0.0, 0.0, 1.0);
	lower_rleg();

	glPushMatrix();


	glFlush();
	glutSwapBuffers();
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		xpos -= cos(90 * pi / 180 + theta[0] * pi / 180);
		zpos += sin(90 * pi / 180 + theta[0] * pi / 180);
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		break;
	case GLUT_KEY_DOWN:
		xpos += cos(90 * pi / 180 + theta[0] * pi / 180);
		zpos -= sin(90 * pi / 180 + theta[0] * pi / 180);
		if (xpos > 5)
			xpos = 5;
		if (zpos > 5)
			zpos = 5;
		if (xpos < -5)
			xpos = -5;
		if (zpos < -5)
			zpos = -5;
		break;
	case GLUT_KEY_LEFT: theta[0] -= 5.0; break;
	case GLUT_KEY_RIGHT: theta[0] += 5.0; break;
	case GLUT_KEY_PAGE_UP: ypos += 1.0; break;
	case GLUT_KEY_PAGE_DOWN: ypos -= 1.0; break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 0.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void) {
	GLfloat lightIntensity[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat light_position[] = { 2.0f, 6.0f, 3.0f, 0.0f };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	p = gluNewQuadric();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("human");
	init();
	init1();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
	return 0;
}
