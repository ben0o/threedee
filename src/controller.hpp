#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
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
	virtual void Update(double);
	virtual void Draw();

	virtual void CompareSettings();
	
protected:
	Console* p_console;
	Settings* p_settings;
	bool bActive;
};
#endif
