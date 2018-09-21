
#ifndef CONSOLE_H
#define CONSOLE_H

#include "GLFW/glfw3.h"
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

class Console
{
public:
	Console(GLFWwindow*);
	~Console();
	void Message(int,std::string);
	void Message(int,std::string,float);
	//void PassWorld(World *);

	//Data hooks
	void CheckForErrors();
	void FrameRate();
	void UpdateRate();

	//Displays
	void DisplayFrameRate();

	//configurable flags
	bool bEnableVBO;
	bool bEnableFBO;
	bool bShowFrameRate;

	//Not user configurable
	bool bPlayerCameraInitialised;
	bool bAllowRendering;

private:
	//frame rate
	float framesPerSecond;
	float basetime;
	float frames;
	float updates;
	float updatesPerSecond;
	
	GLFWwindow* p_window;
};

#endif
