#include <GL\glew.h>
#include <GL\freeglut.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string>

GLfloat a = 0, b = 0, c = 0, d = -20, e = 0;
int flag = 0;
int ok = 1;
float aero = 400.0;
int aero2 = -4500;
int rot = 0;
int limit;
int no_of_obj = 150;
GLfloat random_z[150][3];
GLfloat random_m[60][3];
float angle = 0.0;
float lx = 0.0f, lz = -1.0f, ly = 1.0f;
float x = 0.0f, z = 1100.0f, y = 825.0f;
float sky_x = 0, sky_y = 2400, sky_z = -1000;
float px = 0.5, py = 0.5, box_x = 0, box_y = 0;
int leftmouse = 0;
int rightmouse = 0;
float ccy = 3400.0, ccx = 0.0, ccz = 0.0;

static void Timer(int value) {
	//z -= 0.5;
	if (rot < 360)
		rot += 1;
	else
		rot = 1;
	if (ok == false)
		aero2 += 2;
	if (ok == 3)
		aero += 1;
	glutPostRedisplay();
	// 100 milliseconds
	glutTimerFunc(10, Timer, 0);
}



//RANDOM FUNCTION FOR
void random2() {
	for (int i = 0; i < no_of_obj; i++)
	{
		if (i % 2 == 0)
			random_z[i][0] = (rand() % 2000);
		else
			random_z[i][0] = -(rand() % 2000);

		random_z[i][1] = 5.0;
		random_z[i][2] = -((rand() % 10000) + 100);
	}
}
void draw_ground() {
	glDisable(GL_LIGHTING);

	glBegin(GL_QUADS);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-10000.0f, 70.0f, -8900.0f);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(10000.0f, 70.0f, -8900.0f);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(10000.0f, 70.0f, 3500.0f);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-10000.0f, 70.0f, 3500.0f);


	glEnd();

	glEnable(GL_LIGHTING);
}
void draw_red()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-25.0f + ccx, 82.0f, -25.0f + ccz);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(25.0f + ccx, 82.0f, -25.0f + ccz);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(25.0f + ccx, 82.0f, 25.0f + ccz);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-25.0f + ccx, 82.0f, 25.0f + ccz);


	glEnd();
}
void aeroplanes()
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(a, 0.0, -3000.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//back wing
	glVertex2f(-30.0 + d, 418.0);
	glVertex2f(-30.0 + d, 420.0);
	glVertex2f(-28.2 + d, 420.0);
	glVertex2f(-25.7 + d, 418.0);
	glEnd();
	glPopMatrix();
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(a, 0.0, -3000.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//rightside wing
	glVertex2f(-16.0 + d, 416.0);
	glVertex2f(-18.5 + d, 415.0);
	glVertex2f(-14.5 + d, 415.0);
	glVertex2f(-12.0 + d, 416.0);
	glEnd();
	glPopMatrix();





	glPushMatrix();
	glTranslatef(a, 0.0, -3000.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);//door
	glVertex2f(-23.0 + d, 416.0);
	glVertex2f(-23.0 + d, 417.0);
	glVertex2f(-20.0 + d, 417.0);
	glVertex2f(-20.0 + d, 416.0);
	glEnd();

	glPopMatrix();

	glColor3f(0.0, 0.0, 1.0);


	glPushMatrix();
	glTranslatef(a, 0.0, -3000.0);
	glBegin(GL_POLYGON);//rectangular body
	glVertex2f(-30.0 + d, 416.0);
	glVertex2f(-30.0 + d, 418.0);
	glVertex2f(-10.0 + d, 418.0);
	glVertex2f(-10.0 + d, 416.0);
	glEnd();
	glPopMatrix();
	//glPopMatrix();
	glPushMatrix();
	glTranslatef(a, 0.0, -3000.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//upper triangle construction plane
	glVertex2f(-10.0 + d, 418.0);
	//glVertex2f(150.0, 450.0);
	//glVertex2f(155.0, 445.0);
	glVertex2f(-5.0 + d, 417.0);
	glVertex2f(-10.0 + d, 416.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(a, 0.0, -3000.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//left side wing
	glVertex2f(-16.0 + d, 418.0); //-15,418
	glVertex2f(-18.5 + d, 418.7); //-16,419
	glVertex2f(-14.5 + d, 418.7); //-17,419
	glVertex2f(-12.0 + d, 418.0); //-17.5,418
	glEnd();
	glPopMatrix();
	//glPushMatrix();
	glTranslatef(a, 0.0, -3000.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//rightside wing
	glVertex2f(-16.0 + d, 416.0);
	glVertex2f(-18.5 + d, 417.0);
	glVertex2f(-14.5 + d, 417.0);
	glVertex2f(-12.0 + d, 416.0);
	glEnd();
	;
	glEnable(GL_LIGHTING);

}

void update(int value)
{
	d += 0.002; //Plane movement in x axis
	glutPostRedisplay();
	glutTimerFunc(150, update, 0);//delay
	if (d > 67)
	{
		d = -20;
	}
}

//SKY
void draw_sky() {
	glDisable(GL_LIGHTING);
	//glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);

	glColor3f(0.0, 0.6, 0.8);
	glVertex3f(-5000.0f, -1000.0f, -5500.0f + z);
	glVertex3f(-5000.0f, 3000.0f, -5500.0f + z);

	glColor3f(0.130, 0.280, 0.450);
	glVertex3f(5000.0f, 3000.0f, -5500.0f + z);
	glVertex3f(5000.0f, -1000.0f, -5500.0f + z);

	glEnd();
	glEnable(GL_LIGHTING);

}

//CLOUDS
void clouds()
{

	glPushMatrix();
	//glTranslatef(-20,200,-200);
	glColor3ub(224, 224, 224);
	glTranslatef(0, 20, -40);
	glutSolidSphere(10, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(224, 224, 224);
	glTranslatef(0, 20, -30);
	glutSolidSphere(5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(224, 224, 224);
	glTranslatef(-10, 30, -30);
	glutSolidSphere(10, 30, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(224, 224, 224);
	glTranslatef(0, 25, -30);
	glutSolidSphere(10, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(224, 224, 224);
	glTranslatef(0, 10, -30);
	glutSolidSphere(10, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(224, 224, 224);
	glTranslatef(0, 20, -50);
	glutSolidSphere(10, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(224, 224, 224);
	glTranslatef(-20, 20, -50);
	glutSolidSphere(20, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(224, 224, 224);
	glTranslatef(-15, 20, -10);
	glutSolidSphere(20, 20, 20);
	glPopMatrix();

}
void draw_clouds(float rZ) {
	float mcolor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 }; //White Color
	GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_LEFT, GL_AMBIENT_AND_DIFFUSE, mcolor);
	glMaterialfv(GL_LEFT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_LEFT, GL_SHININESS, 20);

	for (int i = 0; i < no_of_obj; i++) {
		glPushMatrix();

		glTranslatef(random_z[i][0] + 50, 1100, random_z[i][2] + 100 + rZ);

		clouds();
		glPopMatrix();
	}


}

//TREES
void trees()
{

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, 20.0, -40.0);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(3, 40, 40, 20);
	glTranslatef(0.0, -20.0, 40.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.8, 0.0);
	glTranslatef(0.0, 20.0, -40.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(7, 10, 40, 20);
	glTranslatef(0.0, -20.0, 40.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.7, 0.0);
	glTranslatef(0.0, 13.0, -40.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(10, 10, 40, 20);
	glTranslatef(0.0, -20.0, 40.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.0);
	glTranslatef(0.0, 4.0, -40.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(15, 12, 40, 20);
	glTranslatef(0.0, -20.0, 40.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.0);
	glTranslatef(0.0, -5.0, -40.0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 16, 5, 5);
	glTranslatef(0.0, -20.0, 40.0);
	glPopMatrix();


}
void draw_tree(float rZ) {
	for (int i = 0; i < no_of_obj; i++) {
		glPushMatrix();

		glTranslatef(random_z[i][0] + 50, 10, random_z[i][2] + 100 + rZ);
		glScaled(3, 3, 3);
		trees();
		glPopMatrix();
	}

}

//MOUNTAINS


//TEXT RENDERING
void stroke_text(int tx, int ty, int tz, float sx, float sy, float sz, char* str) {
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);

	glTranslatef(tx, ty, tz);
	glScalef(sx, sy, sz);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char*)str);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

//RENDER INSTRUCTION TEXT
void render_instruct() {

	char instruct_title[] = " INSTRUCTIONS";
	char welcome[] = "Welcome , Read the Instructions before playing";
	char i1[] = "To Move the skydiver press UP,DOWN,LEFT,RIGHT";
	char i2[] = "Land the skydiver on the REDZONE to Win";
	char i3[] = "If you miss the Red Zone -> GAME OVER";
	char i4[] = "Enjoy";
	char press[64] = "Press Space to Continue";

	glDisable(GL_LIGHTING);
	glColor3b(0.0, 0.0, 0.0);
	stroke_text(-16, 414, -3000, 0.015, 0.015, 0.025, instruct_title);
	stroke_text(-30, 410, -3000, 0.015, 0.015, 0.025, welcome);
	stroke_text(-30, 406, -3000, 0.015, 0.015, 0.025, i1);
	stroke_text(-30, 402, -3000, 0.015, 0.015, 0.025, i2);
	stroke_text(-30, 398, -3000, 0.015, 0.015, 0.025, i3);
	stroke_text(-30, 394, -3000, 0.015, 0.015, 0.025, i4);
	stroke_text(-30, 390, -3000, 0.015, 0.015, 0.025, press);
	glEnable(GL_LIGHTING);

}

//RENDER INTRODUTION TEXT
void render_text() {

	char title[] = "GRAPHICAL VISUALIZATION OF SKYDIVING";
	char clgName[] = "SJB Institute of Technology";
	char dept[] = "Department of Computer Science";
	char year[] = "2020";

	char amal[] = "SAURAV C.V";
	char amal_usn[] = "1JB17CS138";

	char unais[] = "UMANG JOSHI";
	char unais_usn[] = "1JB17CS166";

	char press[] = "Press Enter to Start";

	glDisable(GL_LIGHTING);
	glColor3b(1.0, 0.0, 0.0);
	stroke_text(-20, 417, -3000, 0.020, 0.020, 0.020, clgName);
	stroke_text(-16, 414, -3000, 0.015, 0.015, 0.025, dept);
	stroke_text(-3, 412, -3000, 0.010, 0.010, 0.025, year);
	stroke_text(-35, 400, -3000, 0.025, 0.025, 0.025, title);
	stroke_text(-35, 395, -3000, 0.010, 0.010, 0.010, amal);
	stroke_text(-35, 393, -3000, 0.010, 0.010, 0.010, amal_usn);
	stroke_text(25, 395, -3000, 0.010, 0.010, 0.010, unais);
	stroke_text(25, 393, -3000, 0.010, 0.010, 0.010, unais_usn);
	stroke_text(-10, 387, -3000, 0.015, 0.015, 0.015, press);

	glEnable(GL_LIGHTING);

}

//RENDER GAME OVER TEXT
void render_win() {

	char game_over[64] = "YOU WON!!!!!";

	glDisable(GL_LIGHTING);
	glColor3b(0.0, 0.0, 0.0);
	stroke_text(-13, 400, -3000, 0.025, 0.025, 0.025, game_over);
	glEnable(GL_LIGHTING);
}
void render_lost() {

	char game_over[] = "YOU LOST";

	glDisable(GL_LIGHTING);
	glColor3b(0.0, 0.0, 0.0);
	stroke_text(-13, 400, -3000, 0.025, 0.025, 0.025, game_over);
	glEnable(GL_LIGHTING);
}


//SKYDIVER
void skydiver_jump() {

	int add = 10;
	glPushMatrix();
	glTranslatef(0.0, 20.0, -100.0);
	glScaled(0.65, 0.25, 1.5);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 20.0, -110.0);
	glScaled(0.40, 0.40, 0.40);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(5, 20, 20);
	glPopMatrix();





	glPushMatrix();
	glTranslatef(-2.4, 20.0, -90.0);
	glScaled(0.20, 0.25, 1);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.4, 20.0, -90.0);
	glScaled(0.20, 0.25, 1);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3, 28.0, -81.0);
	glRotatef(90, 1, 0, 0);
	glScaled(0.20, 0.25, 0.60);
	glTranslatef(2.4, -20.0, 10.0);
	glColor3f(1.0, 0.5, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 28.0, -81.0);
	glRotatef(90, 1, 0, 0);
	glScaled(0.20, 0.25, 0.60);
	glTranslatef(2.4, -20.0, 10.0);
	glColor3f(1.0, 0.5, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.4, 24.0, -85.0);
	glScaled(0.20, 0.25, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.4, 24.0, -85.0);
	glScaled(0.20, 0.25, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.60, 25.0, -105.0);
	glRotatef(90, 0, 1, 0);
	glScaled(0.20, 0.25, 0.50);
	glTranslatef(2.4, -20.0, 10.0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10, 25.0, -105.0);
	glRotatef(90, 0, 1, 0);
	glScaled(0.20, 0.25, 0.50);
	glTranslatef(2.4, -20.0, 10.0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7, 20.0, -108.0);
	glScaled(0.20, 0.25, 0.6);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7, 20.0, -108.0);
	glScaled(0.20, 0.25, 0.6);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();
}
void draw_skydiver_jump() {

	float add = 5.0f;
	//bool collide;


	//sky_y -= 20.0f;
	if (y + sky_y > 85.0) {
		glPushMatrix();
		glTranslated(x + sky_x, y + sky_y, z + sky_z);
		skydiver_jump();
		glPopMatrix();
	}
	else {
		if ((x + sky_x > -25.0 && x + sky_x < 25.0) && (z + sky_z > 75.0 && z + sky_z < 125.0)) {
			ok = 4;
		}
		else {
			ok = 5;
		}
	}
}

void display(void) {

	if (ok == 1) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0.0, 400.0, -2950.0, 0.0, 400.0, -3000.0, 0.0f, 1.0f, 0.0f);
		render_text();

		glutSwapBuffers();

	}
	if (ok == 2) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		gluLookAt(0.0, 400.0, -2950.0, 0.0, 400.0, -3000.0, 0.0f, 1.0f, 0.0f);
		render_instruct();
		draw_sky();
		aeroplanes();
		glutTimerFunc(0, update, 0);

		glutSwapBuffers();



	}
	if (ok == 3) {

		// Clear Color and Depth Buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();
		sky_y -= 25.0f;
		ccy -= 25.0f;
		gluLookAt(0.0, ccy, 0.0, 0.0, 0.0, 0.0, 0.0f, 0.0f, -1.0f);
		draw_red();
		draw_ground();
		draw_sky();
		draw_clouds(-6000);
		draw_tree(-6000);
		draw_clouds(0);
		draw_tree(0);
		draw_skydiver_jump();
		glutSwapBuffers();
		Sleep(1);

	}

	if (ok >= 4) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		gluLookAt(0.0, 400.0, -2950.0, 0.0, 400.0, -3000.0, 0.0f, 1.0f, 0.0f);

		glDisable(GL_LIGHTING);

		glBegin(GL_QUADS);

		glColor3f(0.0, 0.6, 0.8);
		glVertex3f(-5000.0f, -1000.0f, -5500.0f);
		glVertex3f(-5000.0f, 3000.0f, -5500.0f);

		glColor3f(0.130, 0.280, 0.450);
		glVertex3f(5000.0f, 3000.0f, -5500.0f);
		glVertex3f(5000.0f, -1000.0f, -5500.0f);

		glEnd();
		glEnable(GL_LIGHTING);
		if (ok == 4) {
			render_win();
		}
		else {
			render_lost();
		}

		glutSwapBuffers();
	}

}

void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 6000.0f);


	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

//KEYBOARD 
void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.5f;

	switch (key) {

	case GLUT_KEY_LEFT:
		//sky_x -= 2.0f;
		if (sky_x > -100.0)
		{
			sky_x -= 5.0f;
			ccx += 5.0f;
		}
		//
		break;
	case GLUT_KEY_RIGHT:
		//sky_x += 2.0f;
		if (sky_x < 100.0) {
			sky_x += 5.0f;
			ccx -= 5.0f;
		}
		//ccx -= 20.0f;
		break;
	case GLUT_KEY_UP:
		if (sky_z >= -1040)
		{
			sky_z -= 5.0f;
			ccz += 5.0f;
		}
		//
		//sky_y += 20.0f;
		//sky_z += 2.0f;
		break;
	case GLUT_KEY_DOWN:
		if (sky_z <= -960) {
			sky_z += 5.0f;
			ccz -= 5.0f;
		}
		//
		//sky_y -= 20.0f;
		//sky_z -= 2.0f;
		break;
	}
}
void callmouse()
{
	if (leftmouse) {
		sky_y -= 20.0f;
		ccy -= 20.0f;
	}


}

void mouse(int btn, int state, int xxx, int yyy)
{
	if (btn == GLUT_LEFT_BUTTON)
	{

		leftmouse = (state == GLUT_DOWN);
	}
	if (btn == GLUT_RIGHT_BUTTON)
	{
		//ccy -= 50.0f;
		rightmouse = (state == GLUT_DOWN);
	}
}
void processNormalKeys(unsigned char key, int xx, int yy)
{
	float fraction = 0.1f;
	switch (key) {
	case 113:exit(0);
	case 65:
		y -= 5;
		break;
	case 97:y += ly * fraction;
		break;
	case 13: ok = 2;
		break;
	case 32: ok = 3;
		break;
	}

}
//MENU
void menu(int op) {

	switch (op) {
	case 0:glutFullScreen();
		break;
	case 1:
	case 'Q':
	case 'q':
		exit(0);
	}
}
//LIGHTING
void lighting() {
	glEnable(GL_COLOR_MATERIAL);
	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
	random2();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1366, 768);
	glutCreateWindow("Skydiving");
	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(mouse);
	glutIdleFunc(callmouse);
	glutSpecialFunc(processSpecialKeys);
	int subMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Full Screen", 0);
	glutAddMenuEntry("Exit", 'q');
	glutCreateMenu(menu);
	glutAddSubMenu("Sub Menu", subMenu);
	glutAddMenuEntry("Quit", 'q');
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glEnable(GL_DEPTH_TEST);
	Timer(0);
	lighting();
	glutMainLoop();
	return 1;
}
