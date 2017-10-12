#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

GLfloat rot_z = 1.0f;

float t = 0.0f;

//---------------------------------------------------------------
void free_mem(void)
{
	std::clog << "Exiting...\n";
}
//---------------------------------------------------------------
void DrawAxis(void)
{
	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0);
		glVertex3f( 0.0f, 0.0f, 0.0f);
		glVertex3f( 0.75f, 0.0f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0);
		glVertex3f( 0.0f, 0.0f, 0.0f);
		glVertex3f( 0.0f, 0.75f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0);
		glVertex3f( 0.0f, 0.0f, 0.0f);
		glVertex3f( 0.0f, 0.0f, 0.75f);

	glEnd();
}

//-----------------------------------------------------------------------------
void DrawCube1(void)
{
	float size1 = 0.5f;

	glColor3f(1.0f, 1.0f, 1.0);

	glBegin(GL_LINES);
		// bottom
		glVertex3f(-size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1,-size1);

		// top
		glVertex3f(-size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1,-size1);

		// left
		glVertex3f(-size1,-size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1,-size1);
		
		// right
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1,-size1);

		// front		
		glVertex3f(-size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1,-size1, size1);

		// back		
		glVertex3f(-size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1,-size1,-size1);
	glEnd();
}


//-----------------------------------------------------------------------------
void DrawCube2(void)
{
	float size1 = 0.25f;

	glColor3f(1.0f, 0.0f, 1.0);

	glBegin(GL_LINES);
		// bottom
		glVertex3f(-size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1,-size1);

		// top
		glVertex3f(-size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1,-size1);

		// left
		glVertex3f(-size1,-size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1,-size1);
		
		// right
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1,-size1);

		// front		
		glVertex3f(-size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1,-size1, size1);

		// back		
		glVertex3f(-size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1,-size1,-size1);
	glEnd();
}

//---------------------------------------------------------------
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, 512, 512);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    gluPerspective( 55.0f, 1.0f, 0.1f, 100.0f ); 

	gluLookAt(	0.0f, 0.0f, 2.5f, 
				0.0f, 0.0f, 0.0f, 
				0.0f, 1.0f, 0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawAxis();	

    glPushMatrix();
        glTranslatef( 0.5f, 0.0f, 0.0f );  
        DrawCube1();
    glPopMatrix();
    
    glTranslatef( -0.5f, 0.0f, 0.0f );  

    glRotatef( rot_z, 0, 0, 1 );

     rot_z *= 1.01f; 

	DrawCube2();

	glutSwapBuffers();
	glutPostRedisplay();
}

//---------------------------------------------------------------
int main(int argc, char **argv)
{
	std::clog << "Begin...\n";

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL: Pipeline Inspection");

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	
	glutDisplayFunc(display);	
	
	atexit(free_mem);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glutMainLoop();

	return 0;
}

