
#define SCREEN_WIDTH 1024.0f
#define SCREEN_HEIGHT 768.0f
#include <iostream>
#include "GL/glew.h"
#include "GL/glut.h"
#include "engine.hpp"
//#include "shader.h"

Engine engine;

void MyDisplay()
{
	engine.Update();
	engine.Draw();
	
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}
void MyMouseMove(int x, int y)
{
	engine.GLCallbackMouseMove(x,y);
	glutPostRedisplay();
}
void MyMouseClick(int button, int state, int x, int y)
{
	// TO DO
}
void MyKeyPress(unsigned char key, int x, int y)
{
	engine.GLCallbackKeyPress(key,x,y);
	glutPostRedisplay();
}
void MyKeyRelease(unsigned char key, int x, int y)
{
	engine.GLCallbackKeyRelease(key,x,y);
	glutPostRedisplay();
}
void MyIdle()
{
	engine.Update();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45,SCREEN_WIDTH/SCREEN_HEIGHT,1.0,500.0);
}

void MyTimer(int t)
{
	engine.Update();
	glutPostRedisplay();
}
int main(int argc, char **argv)
{	
	glutInit(&argc,argv);
	std::cout << "Initialised FREEGLUT" <<std::endl;
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("ThreeDee");
	glutSetCursor(GLUT_CURSOR_NONE);
	
	//GL functions
	glutDisplayFunc(MyDisplay);
	glutMotionFunc( MyMouseMove );									//MouseMovement callback with either button held down
	glutPassiveMotionFunc( MyMouseMove );							//MouseMovement callback with no button held down
	glutMouseFunc( MyMouseClick );									//Mouse click
	glutKeyboardFunc( MyKeyPress );									//Keyboard press
	glutKeyboardUpFunc( MyKeyRelease );								//Keyboard release
	glutIdleFunc(MyIdle);											//Idle
	//glutReshapeFunc(reshape);
	
	glutTimerFunc(2, MyTimer,0);
	glewInit();
	std::cout << "Initialised GLEW" <<std::endl;
	//ShaderManager * sm_p = new ShaderManager();
	
	//engine.PassShaderManager(sm_p);
	engine.FirstRunInitialise();
	glutMainLoop();
}
