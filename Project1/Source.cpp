#include <glut.h>
#include<cmath>

#define PI 3.14159

void xyAxis();

void sky();
void sun();
void cloud();
void clouds();

void ground();
void building(float red, float green, float blue);
void rowOneBuildings();
void rowTwoBuildings();
void window();
void street();
void tree();
void trees();

void grandLine();

void sea();
void boat();

GLfloat boatSpeed = -1150;
GLfloat cloudSpeed = 0;
const GLint ortho = 1000;

void drawRectangle(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}
void drawRectangle(int x1, int y1, int x2, int y2) {
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}
void drawEllipse(float centerX, float centerY, float radiusX, float radiusY) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; ++i) {
		float angle = i * (2.0f * PI / 360.0f);
		float x = centerX + radiusX * cos(angle);
		float y = centerY + radiusY * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
}
void animation(int value) {
	glutPostRedisplay();
	glutTimerFunc(20, animation, 0);
}

void init() {
	glClearColor(0.95, 0.95, 0.95, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-ortho, ortho, -ortho, ortho);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	sky();
	ground();
	grandLine();
	sea();

	xyAxis();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1150, 600); // 1350x700
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Masterpiece");

	init();
	glutDisplayFunc(display);
	glutTimerFunc(20, animation, 0);
	glutMainLoop();
	return 0;
}

void sky() {
	glColor3f(0.490f, 0.992f, 0.988f);
	drawRectangle(-ortho, -300, ortho, ortho);
	glColor3f(0.9882, 0.9921, 0.0078);
	sun();
	clouds();
}
void sun() {
	drawEllipse(800, 800, 100, 90);
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex2i(800, 800);
	glVertex2i(650, 650);
	glEnd();
	for (int i = 1; i <= 7; i++)
	{
		glTranslatef(800, 800, 0);
		glRotatef(-45, 0, 0, 1);
		glTranslatef(-800, -800, 0);
		glBegin(GL_LINES);
		glVertex2i(800, 800);
		glVertex2i(650, 650);
		glEnd();
	}
	glPopMatrix();
}
void cloud() {
	glColor3f(1, 1, 1);
	drawEllipse(300, 800, 200, 80);
	glPushMatrix();
	drawEllipse(380, 800, 80, 100);
	drawEllipse(300, 800, 80, 100);
	drawEllipse(220, 800, 80, 100);
	glPopMatrix();
}
void clouds() {
	glPushMatrix();
	glTranslatef(cloudSpeed, 0, 0);
	cloudSpeed += .3;
	if (cloudSpeed > 900) cloudSpeed = -1500;
	cloud();
	glPopMatrix();
}

void ground() {
	street();
	trees();
	rowTwoBuildings();
	rowOneBuildings();
}
void building(float red, float green, float blue) {
	glColor3f(red, green, blue);
	//glColor3f(0.5568, 0.3372, 0.3411);
	drawRectangle(-900, -300, -600, 400);
	// Windows
	glPushMatrix();
	glColor3f(1, 1, 1);
	drawRectangle(-880, -200, -775, -120);
	glTranslatef(0, 200, 0);
	drawRectangle(-880, -200, -775, -120);
	glTranslatef(0, 200, 0);
	drawRectangle(-880, -200, -775, -120);
	glTranslatef(150, 0, 0);
	drawRectangle(-880, -200, -775, -120);
	glTranslatef(0, -200, 0);
	drawRectangle(-880, -200, -775, -120);
	glTranslatef(0, -200, 0);
	drawRectangle(-880, -200, -775, -120);
	glPopMatrix();
}
void rowOneBuildings() {
	glPushMatrix();
	building(0.5568, 0.3372, 0.3411);
	glTranslatef(750, 0, 0);
	building(0.5568, 0.3372, 0.3411);
	glTranslatef(750, 0, 0);
	building(0.5568, 0.3372, 0.3411);
	glPopMatrix();
}
void rowTwoBuildings() {
	glPushMatrix();
	glTranslatef(400, 350, 0);
	glScalef(1, 0.5, 1);
	building(0.5568, 0.3372, 0.3411);
	glTranslatef(700, 0, 0);
	building(0.5568, 0.3372, 0.3411);
	glPopMatrix();
}
void tree() {
	// Root
	glColor3f(0.5843, 0.2980, 0);
	drawRectangle(-400, -310, -350, -100);
	glPushMatrix();
	// Dark Green
	glColor3f(0, 0.392, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(-450, -200);
	glVertex2i(-300, -200);
	glVertex2i(-375, 0);
	glEnd();
	// Light Green
	glColor3f(0.392, 0.7960, 0);
	glScalef(1, 1.3, 1);
	glTranslatef(0, 100, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(-475, -200);
	glVertex2i(-275, -200);
	glVertex2i(-375, 0);
	glEnd();
	glPopMatrix();
}
void trees() {
	glPushMatrix();
	tree();
	glTranslatef(800, 0, 0);
	tree();
	glScalef(.7, .7, 1);
	glTranslatef(650, 600, 0);
	tree();	
	glTranslatef(-2800, 0, 0);
	tree();
	glPopMatrix();
}
void street() {
	// Street Ground
	glColor3f(0.6862, 0.7529, 0.6901);
	drawRectangle(-ortho, -310, ortho, 200);

	// Street Lines
	glColor3f(1, 1, 1);
	drawRectangle(-ortho, -70, ortho, -30);
}

void grandLine() {
	glColor3f(0.1921f, 0.0980f, 0.0039f);
	drawRectangle(-ortho, -400, ortho, -320);
	glColor3f(0, 0, 0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2i(-ortho, -310);
	glVertex2i(ortho, -310);
	glEnd();
}

void sea() {
	glColor3f(0.2235f, 0.69411f, 0.8);
	drawRectangle(-ortho, -ortho, ortho, -400);
	boat();
}
void boat() {
	glPushMatrix();
	glTranslatef(boatSpeed, 0, 0);
	boatSpeed += 5;
	if (boatSpeed > 1650) boatSpeed = -1150;


	// Upper part
	glColor3f(0, 0, 0);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(-250, -500);
	glVertex2i(-250, -400);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(-250, -425);
	glVertex2i(-200, -450);
	glVertex2i(-250, -475);
	glEnd();
	glColor3f(0.992, 0.396, 0.694);
	glBegin(GL_TRIANGLES);
	glVertex2i(-250, -500);
	glVertex2i(-300, -650);
	glVertex2i(-200, -650);
	glEnd();


	// Top of the boat
	glColor3f(0.984f, 1, 0.364);
	glBegin(GL_POLYGON);
	// Left Triangle
	glVertex2i(-500, -750);
	// Rigth Triangle
	glVertex2i(0, -750);
	glVertex2i(-100, -650);
	glVertex2i(-400, -650);
	glEnd();

	// Windows
	glPushMatrix();
	glColor3f(0.909f, 0.0509f, 0.0039f);
	window();
	glTranslatef(100, 0, 0);
	window();
	glTranslatef(100, 0, 0);
	window();
	glPopMatrix();

	// Bottom of Boat
	glColor3f(0.39f, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, -850);
	// Right Triangle
	glVertex2i(150, -750);
	glVertex2i(0, -750);
	glVertex2i(-500, -750);
	// Left Triangle
	glVertex2i(-650, -750);
	glVertex2i(-500, -850);
	glEnd();


	// Water
	glColor3f(0.0196, 0.5568, 0.69411);
	drawRectangle(-500, -880, 0, -850);
	glPopMatrix();
}
void window() {
	drawRectangle(-400, -725, -350, -675);
}

void xyAxis() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	glVertex2i(-ortho, ortho - ortho);
	glVertex2i(ortho, ortho - ortho);
	glVertex2i(ortho - ortho, -ortho);
	glVertex2i(ortho - ortho, ortho);
	glEnd();
}