#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

GLfloat arr[] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0,
				 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0};

void init();
void display();
void mouse(int button, int state, int x, int y);
void motion(int x, int y);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("bomb");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	init();


	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		puts(state == GLUT_UP ? "M1 release!" : "M1 click!");
	}
}

void motion(int x, int y)
{
	printf("motion: %d %d\n", x, y);
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}
