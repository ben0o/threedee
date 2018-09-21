
#include "controllerGame.hpp"
#include "GLFW/glfw3.h"

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
	glBegin(GL_QUADS);
    // front
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    // back
    glVertex3f(0.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(0.0f, 1.0f, -1.0f);
    // right
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    // left
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.0f, 1.0f, -1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    // top
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(0.0f, 1.0f, -1.0f);
    // bottom
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);
	glEnd();
}
void ControllerGame::LoadScene(std::string)
{
}
