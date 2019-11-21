#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

int phase = 0;
int flash_count = 0;
int powderhose_len = 200;

void init();
void display();
void mouse(int button, int state, int x, int y);
void reshape(int w, int h);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
	return 0;
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && phase == 0)
	{
		phase++;
	}
}

void init()
{
	glClearColor(0.1, 0.0, 0.2, 0.0);
	GLfloat mat_diffuse[] = {1.0, 0.7, 0.0, 0.0};
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	flash_count++;
	if (phase == 1 && powderhose_len)
	{
		powderhose_len--;
		if (!powderhose_len)
		{
			phase++;
			flash_count = 0;
		}
	}
	if (phase == 1 && (flash_count / 3) % 2)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	}
	else
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}
	glColor3f(0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	GLfloat light_pos[] = {0.3 + 0.01 * (powderhose_len - 1),
						   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
							   3.008 * (0.3 + 0.01 * (powderhose_len - 1)),
						   0.5, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	if (phase == 1 || phase == 0)
	{
		glutSolidSphere(1, 40, 50);
		glLineWidth(7);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < powderhose_len; i++)
		{
			glVertex3f(0.3 + 0.01 * i, -(0.3 + 0.01 * i) * (0.3 + 0.01 * i) + 3.008 * (0.3 + 0.01 * i), 0.5);
		}
		glEnd();
		if (phase == 1 && (flash_count / 3) % 2)
		{
			glLineWidth(3);
			glBegin(GL_LINES);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) - 0.05,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)),
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) - 0.25,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)),
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) + 0.05,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)),
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) + 0.25,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)),
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1),
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) - 0.05,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1),
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) - 0.25,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1),
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) + 0.05,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1),
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) + 0.25,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) - 0.05,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) + 0.05,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) - 0.25,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) + 0.25,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) + 0.05,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) - 0.05,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) + 0.25,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) - 0.25,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) - 0.05,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) - 0.05,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) - 0.25,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) - 0.25,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) + 0.05,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) + 0.05,
					   0.5);
			glVertex3f(0.3 + 0.01 * (powderhose_len - 1) + 0.25,
					   -(0.3 + 0.01 * (powderhose_len - 1)) * (0.3 + 0.01 * (powderhose_len - 1)) +
						   3.008 * (0.3 + 0.01 * (powderhose_len - 1)) + 0.25,
					   0.5);
			glEnd();
		}
	}
	else
	{
		if (flash_count < 200)
		{
		//	glClearColor((flash_count / 5) % 2 ? 0.1 : 1.0, (flash_count / 5) % 2 ? 0.0 : 1.0, (flash_count / 5) % 2 ? 0.2 : 0.5, 0.0);
			glClearColor((flash_count / 5) % 2 ? 1.0 : 1.0, (flash_count / 5) % 2 ? 1.0 : 1.0, (flash_count / 5) % 2 ? 1.0 : 0.5, 0.0);
			flash_count++;
		}
		else
		{
			srand(time(NULL));
			GLfloat pos_x = fmod(rand(), 5);
			GLfloat pos_y = fmod(rand(), 5);
			GLfloat pos_z = fmod(rand(), 5);
			glBegin(GL_POLYGON);
			glVertex3f(pos_x, pos_y, pos_z);
			glVertex3f(pos_x + 0.2, pos_y + 0.2, pos_z);
			glVertex3f(pos_x, pos_y + 0.2, pos_z + 0.2);
			glVertex3f(pos_x + 0.2, pos_y, pos_z);
			glEnd();
		}

	}
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}