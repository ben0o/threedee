
#ifndef CONSOLE_H
#define CONSOLE_H

#include "GL/glut.h"
#include <sstream>
#include <string>
#include <iostream>

class Console
{
public:
	Console();
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
};

#endif
