#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "GLFW/glfw3.h"
#include "console.hpp"
#include "Structs.hpp"
#include "SceneManager.hpp"

class Controller
{
public:
	Controller();
	Controller(Console*,Settings*,SceneManager*);
	~Controller();
	
	void SetForegroundStatus();					//used to switch between controllers
	bool GetForegroundStatus();
	virtual void Update(double) {}
	virtual void Draw(GLFWwindow*) {}
	virtual void MouseSetRotation(double,double) {}
	virtual void CompareSettings() {}
	

protected:
	Console* p_console;
	Settings* p_settings;
	bool bActive;
};
#endif
