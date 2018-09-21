#ifndef ENGINE_H
#define ENGINE_H

#include "GLFW/glfw3.h"
#include "console.hpp"
#include "controller.hpp"
#include "controllerGame.hpp"
#include "controllerMenu.hpp"

class Engine
{

public:

	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////

	// OpenGL callbacks
	void MouseCallback(double,double);
	void KeyCallback(int, int, int, int);
	
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////

	//void PassShaderManager(ShaderManager *);

	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////

	void ToggleMenu();
	void Run(GLFWwindow*);
	void Update(double);
	void Draw();
	void Unload();
	
	Console * p_console;
	Controller* p_cntrMenu;
	Controller* p_cntrGame;
	Controller* p_cntrCurrent;
	
private:
	GLFWwindow* p_window;


	int forward;
	int left;	
	float magnitudeMouseX;
	float magnitudeMouseY;
	bool bShowMenu;
	bool bGameRunning;
	bool bShowLoadingScreen;
	
protected:

	
};

#endif
