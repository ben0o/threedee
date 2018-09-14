
#include "controllerGame.hpp"
#include "GL/glut.h"

ControllerGame::ControllerGame()
{
}
ControllerGame::ControllerGame(Console* _ptr)
{
	p_console = _ptr;
}
ControllerGame::~ControllerGame()
{
}
void ControllerGame::Update(double)
{
}
void ControllerGame::Draw()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	//glEnable(GL_CULL_FACE);
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);     	// Red
        glVertex3f(0.5f, -0.5f, 0.5f);
        glColor3f(0.0f, 1.0f, 0.0f);		//green
		glVertex3f(0.5f, 0.5f, 0.5f);
		glColor3f(0.0f, 0.0f, 1.0f);     	// Blue
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glColor3f(1.0f, 0.0f, 1.0f);     	// Magenta
		glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();
}
void ControllerGame::LoadScene(std::string)
{
}
