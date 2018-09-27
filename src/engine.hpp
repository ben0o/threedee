#ifndef ENGINE_H
#define ENGINE_H

#include "GLFW/glfw3.h"
#include "console.hpp"
#include "controller.hpp"
#include "camera.hpp"
#include "controllerGame.hpp"
#include "controllerMenu.hpp"
#include "glm/vec3.hpp"

class Engine
{

public:
	// OpenGL callbacks
	void MouseCallback(double,double);
	void KeyCallback(int, int, int, int);

	void Run(GLFWwindow*);
	void Update(double);
	void Draw();
	void Unload();
	
	void ToggleMenu();
	
	Console * p_console;
	Controller* p_cntrMenu;
	Controller* p_cntrGame;
	Controller* p_cntrCurrent;
	Camera* p_camera;
	
private:
	GLFWwindow* p_window;

	glm::vec3 vec3InputDirection;
	bool bShowMenu;
	bool bGameRunning;
	bool bShowLoadingScreen;
	
	//Camera
	float oldMousePosX;
	float oldMousePosY;
	float mouseSensitivity;

protected:

	
};

#endif
