#ifndef ENGINE_H
#define ENGINE_H

#include "GL/glut.h"
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
	void GLCallbackMouseMove(int,int);
	void GLCallbackKeyPress(unsigned char, int, int);
	void GLCallbackKeyRelease(unsigned char, int, int);
	
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////

	//void PassShaderManager(ShaderManager *);

	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////

	void FirstRunInitialise();
	
	void ToggleMenu();
	
	void Update();
	void Draw();
	void Unload();
	
	Console * p_console;
	Controller* p_cntrMenu;
	Controller* p_cntrGame;
	Controller* p_cntrCurrent;
	
private:
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
